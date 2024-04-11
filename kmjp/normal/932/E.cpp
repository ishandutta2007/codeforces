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
ll dp[5050][5050];
ll fact[5050];

ll modpow(ll a, ll n) {
	ll r=1;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}

ll comb(int P_,int Q_) {
	if(P_<0 || Q_<0 || Q_>P_) return 0;
	ll p=1,q=1;
	Q_=min(Q_,P_-Q_);
	for(int i=1;i<=Q_;i++) p=p*P_%mo, q=q*i%mo,P_--;
	
	return p*modpow(q,mo-2)%mo;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	dp[0][0]=dp[1][1]=1;
	fact[0]=fact[1]=1;
	for(i=2;i<=5000;i++) {
		fact[i]=fact[i-1]*i%mo;
		for(k=1;k<=i;k++) {
			(dp[i][k]+=dp[i-1][k]*k)%=mo;
			(dp[i][k+1]+=dp[i-1][k])%=mo;
		}
	}
	
	cin>>N>>K;
	ll ret=0;
	for(int m=1;m<=min(N,K);m++) {
		ll pat=comb(N,m);
		pat=pat*dp[K][m]%mo*fact[m]%mo*modpow(2,N-m)%mo;
		ret+=pat;
	}
	cout<<ret%mo<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}