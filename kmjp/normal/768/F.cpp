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

ll F,W,H;
ll mo=1000000007;

ll combi(ll N_, ll C_) {
	const int NUM_=600001;
	static ll fact[NUM_+1],factr[NUM_+1],inv[NUM_+1];
	if (fact[0]==0) {
		inv[1]=fact[0]=factr[0]=1;
		for (int i=2;i<=NUM_;++i) inv[i] = inv[mo % i] * (mo - mo / i) % mo;
		for (int i=1;i<=NUM_;++i) fact[i]=fact[i-1]*i%mo, factr[i]=factr[i-1]*inv[i]%mo;
	}
	if(C_<0 || C_>N_) return 0;
	return factr[C_]*fact[N_]%mo*factr[N_-C_]%mo;
}
ll hcomb(ll P_,ll Q_) { 
	if(P_<0 || Q_<0) return 0;
	if(P_==0) return Q_==0;
	if(Q_==0) return 1;
	return combi(P_+Q_-1,Q_);
}

ll modpow(ll a, ll n) {
	ll r=1;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>F>>W>>H;
	
	if(F==0) {
		cout<<(W>H)<<endl;
		return;
	}
	
	ll P=0,Q=0;
	for(ll i=1;i<=F;i++) {
		ll a=hcomb(i,F-i);
		ll b=(2*hcomb(i,W-i)+hcomb(i+1,W-(i+1))+hcomb(i-1,W-(i-1)))%mo;
		ll c=(2*hcomb(i,W-i*(H+1))+hcomb(i+1,W-(i+1)*(H+1))+hcomb(i-1,W-(i-1)*(H+1)))%mo;
		
		(P += a*c)%=mo;
		(Q += a*b)%=mo;
	}
	P = P * modpow(Q,mo-2) % mo;
	cout<<P<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}