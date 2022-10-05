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

int T;
ll N,M,K;
const ll mo=998244353;

ll modpow(ll a, ll n=mo-2) {
	ll r=1;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}


const int NUM_=400001;
static ll fact[NUM_+1],factr[NUM_+1],inv[NUM_+1];

ll from[2020],to[2020];
ll dp[2020][2020];


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	dp[0][0]=1;
	for(i=1;i<=2000;i++) {
		FOR(j,2001) {
			// same
			(dp[i][j]+=dp[i-1][j]*j)%=mo;
			// new
			(dp[i][j+1]+=dp[i-1][j])%=mo;
		}
		swap(from,to);
	}
	
	inv[1]=fact[0]=factr[0]=1;
	for (int i=2;i<=NUM_;++i) inv[i] = inv[mo % i] * (mo - mo / i) % mo;
	for (int i=1;i<=NUM_;++i) fact[i]=fact[i-1]*i%mo, factr[i]=factr[i-1]*inv[i]%mo;
	
	cin>>T;
	while(T--) {
		cin>>N>>M>>K;
		
		
		ll ret=0;
		ll p=1,q=1;
		for(i=1;i<=min(K,N);i++) {
			(p*=N+1-i)%=mo;
			ll b=modpow((M+1)/2,i);
			ll c=modpow(M,N-i);
			ll d=dp[K][i];
			ret+=p*b%mo*c%mo*d%mo;
		}
		cout<<ret%mo<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}