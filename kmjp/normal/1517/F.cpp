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

int N;
vector<int> E[101010];
const ll mo=998244353;
ll F[303][303];
ll G[303][303];
int D[303];
int K;

ll modpow(ll a, ll n = mo-2) {
	ll r=1;a%=mo;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}

int dfs(int cur,int pre) {
	
	D[cur]=0;
	ZERO(F[cur]);
	ZERO(G[cur]);
	F[cur][0]=G[cur][0]=1;
	
	int i,j;
	FORR(e,E[cur]) if(e!=pre) {
		dfs(e,cur);
		ll TF[303]={};
		ll TG[303]={};
		FOR(i,D[cur]+1) FOR(j,D[e]+1) {
			int mi=min(i,j+1);
			int ma=max(i,j+1);
			(TF[ma]+=F[cur][i]*F[e][j])%=mo;
			(TG[mi]+=G[cur][i]*G[e][j])%=mo;
			if(i+j+1<=K) {
				(TG[i]+=G[cur][i]*F[e][j])%=mo;
				(TG[j+1]+=F[cur][i]*G[e][j])%=mo;
			}
			else {
				(TF[i]+=F[cur][i]*G[e][j])%=mo;
				(TF[j+1]+=G[cur][i]*F[e][j])%=mo;
			}
		}
		
		FOR(i,K+1) {
			F[cur][i]=TF[i];
			G[cur][i]=TG[i];
		}
		
		D[cur]=max(D[cur],D[e]+1);
	}
	
	
	return D[cur];
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N-1) {
		cin>>x>>y;
		E[x-1].push_back(y-1);
		E[y-1].push_back(x-1);
	}
	
	ll ret=N*modpow(2,N)%mo;
	for(i=0;i<=N;i++) {
		K=i;
		dfs(0,0);
		FOR(j,K+1) (ret-=G[0][j])%=mo;
	}
	
	cout<<(ret%mo+mo)*modpow(modpow(2,N))%mo<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}