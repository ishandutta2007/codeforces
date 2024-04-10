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

int N,M;
int A[303030];
const ll mo=998244353;

ll F[303030];


ll modpow(ll a, ll n = mo-2) {
	ll r=1;a%=mo;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>A[i];
		M+=A[i];
	}
	F[0]=N-1;
	for(x=1;x<M;x++) {
		ll a=(M-x)*modpow(M)%mo*modpow(N-1)%mo;
		ll b=1+x*F[x-1]%mo*modpow(M)%mo;
		F[x]=b*modpow(a)%mo;
	}
	
	for(i=M-1;i>=0;i--) F[i]=(F[i]+F[i+1])%mo;
	
	ll ret=0;
	FOR(i,N) ret+=F[A[i]];
	ret=(ret%mo-F[0]*(N-1)%mo+mo)%mo;
	cout<<ret*modpow(N)%mo<<endl;
	
	
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}