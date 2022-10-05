#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
template<class T> bool chmax(T &a, const T &b) { if(a<b){a=b;return 1;}return 0;}
template<class T> bool chmin(T &a, const T &b) { if(a>b){a=b;return 1;}return 0;}
//-------------------------------------------------------

template<int um> class UF {
	public:
	vector<int> par,rank,cnt;
	UF() {par=rank=vector<int>(um,0); cnt=vector<int>(um,1); for(int i=0;i<um;i++) par[i]=i;}
	void reinit() {int i; FOR(i,um) rank[i]=0,cnt[i]=1,par[i]=i;}
	int operator[](int x) {return (par[x]==x)?(x):(par[x] = operator[](par[x]));}
	int count(int x) { return cnt[operator[](x)];}
	int operator()(int x,int y) {
		if((x=operator[](x))==(y=operator[](y))) return x;
		cnt[y]=cnt[x]=cnt[x]+cnt[y];
		if(rank[x]>rank[y]) return par[x]=y;
		rank[x]+=rank[x]==rank[y]; return par[y]=x;
	}
};

UF<606> uf;

int N,M;
vector<pair<int,int>> E[202];
int D[303];
int ma=-1;
int R[303];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,M) {
		cin>>x>>y>>r;
		x--;y--;
		E[x].push_back({y,r});
		E[y].push_back({x,-r});
		uf(x*2,y*2+1);
		uf(y*2,x*2+1);
		if(uf[x*2]==uf[x*2+1]) return _P("NO\n");
	}
	FOR(i,N) {
		FOR(j,N) D[j]=1010;
		D[i]=0;
		FOR(j,N+1) {
			FOR(x,N) FORR(e,E[x]) {
				if(e.second==0 || e.second==1) D[e.first]=min(D[e.first],D[x]+1);
				if(e.second==-1) D[e.first]=min(D[e.first],D[x]-1);
			}
		}
		x=0;
		FOR(j,N) {
			if(D[j]<0) break;
			x=max(x,D[j]);
		}
		if(j<N) continue;
		if(x>ma) {
			ma=x;
			FOR(j,N) R[j]=D[j];
		}
	}
	if(ma==-1) {
		cout<<"NO"<<endl;
	}
	else {
		cout<<"YES"<<endl;
		cout<<ma<<endl;
		FOR(j,N) cout<<R[j]<<" ";
		cout<<endl;
		
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}