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

int N,K,L;
ll mo=998244353;
ll dp[4020][2020][2];


ll modpow(ll a, ll n = mo-2) {
	ll r=1;a%=mo;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K>>L;
	
	dp[0][0][0]=1;
	FOR(x,2*N+1) {
		FOR(y,N+1) {
			// P
			if(y>=K) (dp[x+1][y][1]+=dp[x][y][0])%=mo;
			// open
			if(y<N) {
				(dp[x+1][y+1][0]+=dp[x][y][0])%=mo;
				(dp[x+1][y+1][1]+=dp[x][y][1])%=mo;
			}
			// close
			if(y) {
				(dp[x+1][y-1][0]+=y*dp[x][y][0])%=mo;
				(dp[x+1][y-1][1]+=y*dp[x][y][1])%=mo;
			}
			
		}
	}
	
	ll ret=dp[2*N+1][0][1];
	FOR(i,N) ret=ret*2%mo;
	for(i=1;i<=N;i++) ret=ret*i%mo;
	for(i=1;i<=2*N+1;i++) ret=ret*modpow(i)%mo;
	cout<<ret*L%mo<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}