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
int H[1010010];
ll mo=1000000007;
ll dp[1010100][2];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	ll ret=0;
	for(i=1;i<=N;i++) cin>>H[i], H[i]--;
	
	for(i=1;i<=N;i++) {
		if(H[i-1]<=H[i]) {
			if(H[i]<=H[i+1]) {
				dp[i][0]=(H[i]+dp[i-1][0]*H[i-1])%mo;
			}
			else {
				if(H[i-1]<=H[i+1]) {
					dp[i][0]=H[i]-H[i+1];
					dp[i][1]=(H[i+1]+H[i-1]*dp[i-1][0])%mo;
				}
				else {
					dp[i][0]=(H[i]-H[i+1]+(H[i-1]-H[i+1])*dp[i-1][0])%mo;
					dp[i][1]=H[i+1]*(1+dp[i-1][0])%mo;
				}
			}
		}
		else {
			if(H[i]<=H[i+1]) {
				dp[i][0]=(1+dp[i-1][1])*H[i]%mo;
			}
			else {
				dp[i][0]=(H[i]-H[i+1])*(1+dp[i-1][1])%mo;
				dp[i][1]=H[i+1]*(1+dp[i-1][1])%mo;
			}
		}
		(ret+=dp[i][0]+dp[i][1])%=mo;
	}
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}