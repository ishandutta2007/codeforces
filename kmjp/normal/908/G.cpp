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

int N;
string S;

ll dp[2][701];
ll p10[707];
ll p11[707];
ll mo=1000000007;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>S;
	N=S.size();
	FORR(c,S) c-='0';
	
	p10[0]=1;
	FOR(i,705) {
		p10[i+1]=(p10[i]*10)%mo;
		p11[i+1]=(p11[i]*10+1)%mo;
	}
	
	ll ret=0;
	for(j=1;j<=9;j++) {
		ZERO(dp);
		dp[1][0]=1;
		FOR(i,N) {
			for(x=i;x>=0;x--) {
				ll dp0=dp[0][x],dp1=dp[1][x];
				dp[0][x]=dp[1][x]=0;
				
				if(dp1) {
					// smaller
					if(S[i]==j) {
						(dp[1][x+1] += dp1)%=mo;
						(dp[0][x] += dp1*j)%=mo;
					}
					else if(S[i]>j) {
						(dp[1][x] += 10*dp1)%=mo;
						(dp[0][x] += dp1*10*(S[i]-(j+1)))%=mo;
						(dp[0][x+1] += dp1)%=mo;
						(dp[0][x] += dp1*j)%=mo;
					}
					else {
						(dp[1][x] += dp1)%=mo;
						(dp[0][x] += dp1*S[i])%=mo;
					}
				}
				if(dp0) {
					(dp[0][x]+=dp0*(9-j)*10)%=mo;
					(dp[0][x+1]+=dp0)%=mo;
					(dp[0][x]+=dp0*j)%=mo;
				}
			}
		}
		FOR(x,701) {
			(ret+=p11[x]*j%mo*(dp[0][x]+dp[1][x]))%=mo;
		}
		
	}
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}