#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int N;
int X[3],Y[3],R[3];

template<int um> class UF {
	public:
	vector<int> par,rank;
	UF() {rank=vector<int>(um,0); for(int i=0;i<um;i++) par.push_back(i);}
	int operator[](int x) {return (par[x]==x)?(x):(par[x] = operator[](par[x]));}
	int operator()(int x,int y) {
		if((x=operator[](x))==(y=operator[](y))) return x;
		if(rank[x]>rank[y]) return par[x]=y;
		rank[x]+=rank[x]==rank[y]; return par[y]=x;
	}
};
UF<500000> uf;

map<pair<double,double>,int> P;
vector<vector<double>> A[3];
int NE;

void add(double x,double y) {
	double rx=floor(x*1e8+0.5);
	double ry=floor(y*1e8+0.5);
	
	P[{rx,ry}]=0;
	int i,add=0;
	FOR(i,N) {
		if(abs(hypot(X[i]-x,Y[i]-y)-R[i])<1e-12) {
			add |= 1<<i;
			A[i].push_back({floor(atan2(x-X[i],y-Y[i])*1e8+0.5),rx,ry});
		}
	}
}

void hoge(double x1,double y1,double r1,double x2,double y2,double r2) {
	x2-=x1;
	y2-=y1;
	
	if(x2==0 && y2==0) return;
	double a=(x2*x2+y2*y2+r1*r1-r2*r2)/2.0;
	double d=(x2*x2+y2*y2)*r1*r1-a*a;
	if(d<0) return;
	d=sqrt(d);
	
	add(x1+(a*x2+y2*d)/(x2*x2+y2*y2),y1+(a*y2-x2*d)/(x2*x2+y2*y2));
	add(x1+(a*x2-y2*d)/(x2*x2+y2*y2),y1+(a*y2+x2*d)/(x2*x2+y2*y2));
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>X[i]>>Y[i]>>R[i];
	}
	FOR(i,N) {
		add(X[i]+R[i],Y[i]);
		FOR(j,i) {
			hoge(X[i],Y[i],R[i],X[j],Y[j],R[j]);
		}
	}
	
	x=0;
	FORR(p,P) p.second=x++;
	FOR(i,N) {
		sort(ALL(A[i]));
		A[i].erase(unique(ALL(A[i])),A[i].end());
		NE+=A[i].size();
		FOR(j,A[i].size()) {
			uf(P[{A[i][0][1],A[i][0][2]}],P[{A[i][j][1],A[i][j][2]}]);
		}
	}
	
	int ret=NE-P.size()+1;
	FOR(i,P.size()) if(uf[i]==i) ret++;
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}