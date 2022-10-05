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

int N,A,B,K;
string S;
ll mo=1000000009;

ll modpow(ll a, ll n = mo-2) {
	ll r=1;a%=mo;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>A>>B>>K;
	cin>>S;
	
	ll ret=0;
	FOR(i,K) {
		ll v=modpow(A,N-i)*modpow(B,i)%mo;
		if(S[i]=='-') v=mo-v;
		ret+=v;
	}
	ret%=mo;
	
	ll ba=modpow(B*modpow(A)%mo,K);
	ll nk=(N+1)/K;
	
	if(ba==1) {
		ret*=nk;
	}
	else {
		ret=ret*(modpow(ba,nk)+mo-1)%mo*modpow(ba-1);
	}
	cout<<ret%mo<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}