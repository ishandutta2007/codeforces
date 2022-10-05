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

int N,Q;
double P[101010];

const int NV=1<<18;
pair<double,double> M[NV*2];

pair<double,double> merge(pair<double,double> p1,pair<double,double> p2) {
	pair<double,double> p;
	p.first = (p1.first*p2.first)/(1+p1.second*(p2.first-1));
	p.second = p2.second + (p1.second*p2.first*(1-p2.second))/(1-p1.second*(1-p2.first));
	return p;
}

pair<double,double> getval(int x,int y,int l=0,int r=NV,int k=1) {
	if(x<=l && r<=y) return M[k];
	int m=(l+r)/2;
	if(y<=m) return getval(x,y,l,m,k*2);
	if(x>=m) return getval(x,y,m,r,k*2+1);
	return merge(getval(x,y,l,(l+r)/2,k*2),getval(x,y,(l+r)/2,r,k*2+1));
}
void update(int entry, double v) {
	int x,y;
	entry += NV;
	M[entry]={v,v};
	while(entry>1) {
		entry>>=1;
		M[entry] = merge(M[entry*2],M[entry*2+1]);
	}
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>Q;
	FOR(i,NV*2) M[i]={1,1};
	FOR(i,N) {
		cin>>x>>y;
		P[i]=x*1.0/y;
		update(i,P[i]);
	}
	
	while(Q--) {
		cin>>i;
		if(i==1) {
			cin>>i>>x>>y;
			i--;
			P[i]=x*1.0/y;
			update(i,P[i]);
		}
		else {
			cin>>x>>y;
			_P("%.12lf\n",getval(x-1,y).first);
		}
	}
	
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}