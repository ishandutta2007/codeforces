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

int T,N,K;
int X[202020],Y[202020],tim[202020];

template<int um> class UF {
	public:
	vector<int> par,rank,cnt;
	UF() {par=rank=vector<int>(um,0); cnt=vector<int>(um,1); for(int i=0;i<um;i++) par[i]=i;}
	void reinit(int num=um) {int i; FOR(i,num) rank[i]=0,cnt[i]=1,par[i]=i;}
	int operator[](int x) {return (par[x]==x)?(x):(par[x] = operator[](par[x]));}
	int count(int x) { return cnt[operator[](x)];}
	int operator()(int x,int y) {
		if((x=operator[](x))==(y=operator[](y))) return x;
		cnt[y]=cnt[x]=cnt[x]+cnt[y];
		if(rank[x]>rank[y]) return par[x]=y;
		rank[x]+=rank[x]==rank[y]; return par[y]=x;
	}
};
UF<202020> uf;
map<int,vector<pair<int,int>>> Xs,Ys;

int ok(int t) {
	uf.reinit(N+1);
	int i;
	FOR(i,N) {
		if(tim[i]<=t) uf(i,N);
	}
	FORR2(a,c,Xs) {
		FOR(i,c.size()-1) {
			if(c[i].first+K>=c[i+1].first) uf(c[i].second,c[i+1].second);
		}
	}
	FORR2(a,c,Ys) {
		FOR(i,c.size()-1) {
			if(c[i].first+K>=c[i+1].first) uf(c[i].second,c[i+1].second);
		}
	}
	
	int num=0;
	FOR(i,N+1) if(uf[i]==i) num++;
	return num-(t+1)<=1;
	
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N>>K;
		Xs.clear();
		Ys.clear();
		
		FOR(i,N) {
			cin>>X[i]>>Y[i]>>tim[i];
			Xs[X[i]].push_back({Y[i],i});
			Ys[Y[i]].push_back({X[i],i});
		}
		FORR2(a,b,Xs) sort(ALL(b));
		FORR2(a,b,Ys) sort(ALL(b));
			
		int ret=(1<<30)-1;
		for(i=29;i>=0;i--) if(ok(ret-(1<<i))) ret-=1<<i;
		cout<<ret<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}