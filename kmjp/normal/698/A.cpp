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
int A[101];
int dp[101][3];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	memset(dp,0x3f,sizeof(dp));
	dp[0][0]=0;
	cin>>N;
	
	FOR(i,N) {
		cin>>x;
		if(x&1) {
			dp[i+1][1]=min(dp[i+1][1],dp[i][0]);
			dp[i+1][1]=min(dp[i+1][1],dp[i][2]);
		}
		if(x&2) {
			dp[i+1][2]=min(dp[i+1][2],dp[i][0]);
			dp[i+1][2]=min(dp[i+1][2],dp[i][1]);
		}
		dp[i+1][0]=min(dp[i+1][0],dp[i][0]+1);
		dp[i+1][0]=min(dp[i+1][0],dp[i][1]+1);
		dp[i+1][0]=min(dp[i+1][0],dp[i][2]+1);
	}
	cout<<min(min(dp[N][0],dp[N][1]),dp[N][2])<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}