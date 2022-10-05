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

int N,K;
ll mo=1000000007;
ll modpow(ll a, ll n = mo-2) {
	ll r=1;a%=mo;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}

ll comb(ll N_, ll C_) {
	const int NUM_=400001;
	static ll fact[NUM_+1],factr[NUM_+1],inv[NUM_+1];
	if (fact[0]==0) {
		inv[1]=fact[0]=factr[0]=1;
		for (int i=2;i<=NUM_;++i) inv[i] = inv[mo % i] * (mo - mo / i) % mo;
		for (int i=1;i<=NUM_;++i) fact[i]=fact[i-1]*i%mo, factr[i]=factr[i-1]*inv[i]%mo;
	}
	if(C_<0 || C_>N_) return 0;
	return factr[C_]*fact[N_]%mo*factr[N_-C_]%mo;
}

ll from[251],to[251];
ll pk[252],pk1[252];


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K;
	from[0]=1;
	
	pk[0]=pk1[0]=1;
	FOR(i,251) pk[i+1]=pk[i]*K%mo,pk1[i+1]=pk1[i]*(K-1)%mo;
	
	FOR(y,N) {
		ZERO(to);
		for(x=0;x<=N;x++) for(r=0;x+r<=N;r++) {
			if(r==0) {
				(to[x]+=from[x]*pk1[N-x]%mo*(pk[x]+mo-pk1[x]))%=mo;
			}
			else {
				(to[x+r]+=from[x]*comb(N-x,r)%mo*pk1[N-x-r]%mo*pk[x])%=mo;
			}
		}
		swap(from,to);
	}
	cout<<from[N]<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}