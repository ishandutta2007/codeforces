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

int H,W;
const ll mo=1000000007;

ll dp[101010][2][2];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W;
	
	ll ret=0;
	FOR(i,2) {
		ZERO(dp);
		
		if(W==1) {
			ret+=2;
		}
		else {
			dp[2][0][1]=1;
			dp[2][1][0]=1;
			dp[2][0][0]=1;
			dp[2][1][1]=1;
			for(j=3;j<=W;j++) {
				dp[j][0][0]=dp[j-1][1][0];
				dp[j][1][1]=dp[j-1][0][1];
				dp[j][0][1]=(dp[j-1][1][0]+dp[j-1][0][0])%mo;
				dp[j][1][0]=(dp[j-1][0][1]+dp[j-1][1][1])%mo;
			}
			
			ret+=dp[W][0][0]+dp[W][0][1]+dp[W][1][0]+dp[W][1][1];
		}
		swap(W,H);
	}
	ret+=mo-2;
	cout<<ret%mo<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}