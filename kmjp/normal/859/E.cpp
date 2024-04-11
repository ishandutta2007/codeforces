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
ll mo=1000000007;
int F[101010],T[101010];

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
UF<500000> uf;
int V[505050];
vector<int> E[404040];

ll dp[404040][2];

void dfs(int cur,int pre) {
	if(cur<2*N) {
		dp[cur][1]=1; // no pair
		dp[cur][0]=0; // pair
		FORR(e,E[cur]) if(e!=pre) {
			dfs(e,cur);
			ll x=dp[cur][0], y=dp[cur][1];
			dp[cur][0]=(x*(dp[e][0]+dp[e][1])+y*dp[e][0])%mo;
			dp[cur][1]=y*(dp[e][0]+dp[e][1])%mo;
		}
	}
	else {
		dp[cur][0]=1; // not used
		dp[cur][1]=0; // used
		FORR(e,E[cur]) if(e!=pre) {
			dfs(e,cur);
			ll x=dp[cur][0], y=dp[cur][1];
			dp[cur][0]=x*dp[e][0]%mo;
			dp[cur][1]=(x*dp[e][1]+y*dp[e][0])%mo;
		}
	}
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>F[i]>>T[i];
		F[i]--,T[i]--;
		E[F[i]].push_back(2*N+F[i]);
		E[2*N+F[i]].push_back(F[i]);
		uf(F[i],2*N+F[i]);
		if(F[i]!=T[i]) {
			E[F[i]].push_back(2*N+T[i]);
			E[2*N+T[i]].push_back(F[i]);
			uf(F[i],2*N+T[i]);
		}
	}
	FOR(i,N) {
		if(F[i]==T[i]) V[uf[F[i]]]++;
		else V[uf[F[i]]]+=2;
	}
	
	ll ret=1;
	FOR(i,4*N) if(i==uf[i] && uf.count(i)>2) {
		if(uf.count(i)==V[i]) {
			ret=ret*2%mo;
		}
		else {
			if(i<2*N) x=i;
			else x=E[i][0];
			dfs(x,-1);
			(ret*=dp[x][0])%=mo;
		}
	}
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}