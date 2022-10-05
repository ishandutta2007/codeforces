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

ll K,PA,PB,PC;
ll mo=1000000007;
ll dp[1010][1010];

ll modpow(ll a, ll n = mo-2) {
	ll r=1;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>K>>PA>>PB;
	PC=modpow(PA+PB);
	PA=PA*PC%mo;
	PB=PB*PC%mo;
	
	ll ret=0;
	dp[1][0]=1;
	for(x=1;x<K;x++) {
		for(y=0;y<K;y++) {
			// a
			(dp[x+1][y] += dp[x][y]*PA)%=mo;
			// b
			if(x+y>=K) {
				(ret+=(x+y)*dp[x][y]%mo*PB)%=mo;
			}
			else {
				(dp[x][x+y] += dp[x][y]*PB)%=mo;
			}
		}
	}
	FOR(y,K) (ret+=dp[K][y]*((y+K)+PA*modpow(PB)%mo))%=mo;
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}