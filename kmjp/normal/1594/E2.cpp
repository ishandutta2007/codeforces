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

int K;
int N;
ll V[2020];
int C[2020];
const ll mo=1000000007;
int E[6][6];
ll modpow(ll a, ll n = mo-2) {
	ll r=1;a%=mo;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}

ll dp[66];
vector<pair<ll,int>> ev[60];

map<ll,vector<ll>> M[60];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	FOR(i,6) FOR(j,6) if(i!=j&&i+j!=5) E[i][j]=1;
	
	dp[0]=1;
	for(i=1;i<=60;i++) {
		dp[i]=dp[i-1]*modpow(4,1LL<<i)%mo;
	}
	
	cin>>K;
	cin>>N;
	FOR(i,N) {
		cin>>V[i]>>s;
		if(s=="white") C[i]=0;
		if(s=="yellow") C[i]=5;
		if(s=="green") C[i]=1;
		if(s=="red") C[i]=2;
		if(s=="blue") C[i]=4;
		if(s=="orange") C[i]=3;
		x=0;
		ll cur=1;
		while(V[i]>cur) {
			x++;
			cur=cur*2+1;
		}
		ev[x].push_back({V[i],C[i]});
	}
	
	FORR2(a,b,ev[K-1]) {
		vector<ll> c(6);
		c[b]=1;
		
		M[K-1][a]=c;
	}
	for(i=K-2;i>=0;i--) {
		while(M[i+1].size()) {
			ll k=M[i+1].begin()->first/2;
			vector<ll> a(6,dp[K-1-(i+1)]),b(6,dp[K-1-(i+1)]);
			if(M[i+1].count(2*k)) {
				a=M[i+1][2*k];
				M[i+1].erase(2*k);
			}
			if(M[i+1].count(2*k+1)) {
				b=M[i+1][2*k+1];
				M[i+1].erase(2*k+1);
			}
			vector<ll> c(6);
			int z;
			FOR(x,6) FOR(y,6) FOR(z,6) if(E[x][y]&&E[x][z]) (c[x]+=a[y]*b[z])%=mo;
			M[i][k]=c;
		}
		
		FORR2(a,b,ev[i]) {
			vector<ll> c(6,dp[K-1-i]);
			if(M[i].count(a)) c=M[i][a];
			FOR(x,6) if(x!=b) c[x]=0;
			M[i][a]=c;
		}
	}
	ll ret=0;
	FORR2(a,b,M[0]) {
		FORR(c,b) ret+=c;
	}
	cout<<ret%mo<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}