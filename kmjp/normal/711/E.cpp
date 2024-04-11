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

ll N,K;
ll mo=1000003;

ll modpow(ll a, ll n = mo-2) {
	ll r=1;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K;
	if(N<=60 && 1LL<<N<K) return _P("1 1\n");
	
	ll A=1;
	ll T=modpow(2,N);
	ll B=modpow(T,K);
	FOR(i,K) {
		A = A * (T+mo-i) % mo;
		if(A==0) break;
	}
	
	A = (B - A + mo) % mo;
	(A *= modpow(T))%=mo;
	(B *= modpow(T))%=mo;
	for(i=1;i<=60;i++) {
		ll n=(K-1)>>i;
		ll revrev = modpow(2);
		
		(A *= modpow(revrev,n))%=mo;
		(B *= modpow(revrev,n))%=mo;
	}
	
	cout<<A<<" "<<B<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}