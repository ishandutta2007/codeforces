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
ll mo=1000000007;
ll V[1010101];
ll fact[1010101];

inline int mulmod(int a,int b,int mo) {
	int d,r;
	if(a==0 || b==0) return 0;
	if(a==1 || b==1) return max(a,b);
	__asm__("mull %4;"
	        "divl %2"
		: "=d" (r), "=a" (d)
		: "r" (mo), "a" (a), "d" (b));
	return r;
}

int modpow(int a, int n = mo-2) {
	int r=1;
	while(n) r=mulmod(r,(n%2)?a:1,mo),a=mulmod(a,a,mo),n>>=1;
	return r;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K;
	fact[0]=1;
	for(i=1;i<=K+3;i++) {
		V[i]=(V[i-1]+modpow(i,K))%mo;
		fact[i]=(fact[i-1]*i)%mo;
	}
	
	if(N<=K+2) {
		cout<<V[N]<<endl;
		return;
	}
	
	K++;
	ll a=1;
	FOR(i,K+1) a=a*(N+mo-i)%mo;
	ll ret=0;
	
	FOR(i,K+1) {
		int b=mulmod(fact[i],fact[K-i],mo);
		ll rev2=N-i;
		if((K-i)%2) b=mo-b;
		ret += mulmod(mulmod(mulmod(V[i],a,mo),modpow(rev2),mo),modpow(b),mo);
	}
	cout<<ret%mo<<endl;	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}