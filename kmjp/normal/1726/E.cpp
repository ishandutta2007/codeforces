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

int T,N;
const ll mo=998244353;
int R[402020];
const int NUM_=400001;
static ll fact[NUM_+1],factr[NUM_+1],inv[NUM_+1],fact2[NUM_+1];

ll comb(ll N_, ll C_) {
	if(C_<0 || C_>N_) return 0;
	return factr[C_]*fact[N_]%mo*factr[N_-C_]%mo;
}

ll modpow(ll a, ll n = mo-2) {
	ll r=1;a%=mo;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}

ll dp[402020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	inv[1]=fact[0]=factr[0]=1;
	fact2[0]=fact2[1]=1;
	for (int i=2;i<=NUM_;++i) inv[i] = inv[mo % i] * (mo - mo / i) % mo;
	for (int i=2;i<=NUM_;++i) fact2[i]=fact2[i-2]*i%mo;
	for (int i=1;i<=NUM_;++i) fact[i]=fact[i-1]*i%mo, factr[i]=factr[i-1]*inv[i]%mo;
	
	dp[0]=1;
	dp[1]=1;
	for(i=2;i<=400000;i++) {
		(dp[i]=dp[i-1]+dp[i-2]*(i-1))%=mo;
	}
	
	cin>>T;
	while(T--) {
		cin>>N;
		
		ll ret=0;
		for(int s=0;4*s<=N;s++) {
			ll a=comb(N-2*s,2*s);
			if(s) a=a*fact2[2*s-1]%mo*modpow(2,s)%mo;
			int lef=N-4*s;
			//cout<<s<<" "<<a<<endl;
			//for(j=0;j<=lef;j+=2) (ret+=a*comb(lef,j)%mo*(j?fact2[j-1]:1))%=mo;
			(ret+=a*dp[lef])%=mo;
			//cout<<ret<<endl;
		}
		
		
		/*
		vector<int> V;
		FOR(i,N) V.push_back(i);
		int ret=0;
		do {
			FOR(i,N) R[V[i]]=i;
			int ok=1;
			FOR(i,N) if(abs(V[i]-R[i])>1) ok=0;
			ret+=ok;
			
			if(ok) {
				int ng=0;
				x=0;
				FOR(i,N) if(V[i]!=R[i]) ng=1;
				FOR(i,N) if(i!=V[i]) x++;
				if(ng==0) {
					cout<<ok<<" "<<x<<" ";
					FORR(v,V) cout<<v;
					cout<<endl;
				}
			}
		}  while(next_permutation(ALL(V)));
		*/
		cout<<ret<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}