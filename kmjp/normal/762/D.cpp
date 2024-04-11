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

int W;
ll A[3][101010];
ll dp[101010][8];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>W;
	FOR(y,3) FOR(x,W) cin>>A[y][x];
	FOR(x,W+2) FOR(y,8) dp[x][y]=-1LL<<60;
	dp[0][1]=0;
	FOR(x,W) {
		dp[x+1][1]=max(dp[x+1][1],dp[x][1]+A[0][x]);
		dp[x+1][2]=max(dp[x+1][2],dp[x][1]+A[0][x]+A[1][x]);
		dp[x+1][4]=max(dp[x+1][4],dp[x][1]+A[0][x]+A[1][x]+A[2][x]);
		dp[x+1][1]=max(dp[x+1][1],dp[x][2]+A[0][x]+A[1][x]);
		dp[x+1][2]=max(dp[x+1][2],dp[x][2]+A[1][x]);
		dp[x+1][4]=max(dp[x+1][4],dp[x][2]+A[1][x]+A[2][x]);
		dp[x+1][1]=max(dp[x+1][1],dp[x][4]+A[0][x]+A[1][x]+A[2][x]);
		dp[x+1][2]=max(dp[x+1][2],dp[x][4]+A[1][x]+A[2][x]);
		dp[x+1][4]=max(dp[x+1][4],dp[x][4]+A[2][x]);
		dp[x+1][1]=max(dp[x+1][1],dp[x][7]+A[0][x]+A[1][x]+A[2][x]);
		dp[x+1][4]=max(dp[x+1][4],dp[x][7]+A[0][x]+A[1][x]+A[2][x]);
		dp[x+1][7]=max(dp[x+1][7],dp[x][1]+A[0][x]+A[1][x]+A[2][x]);
		dp[x+1][7]=max(dp[x+1][7],dp[x][4]+A[0][x]+A[1][x]+A[2][x]);
	}
	cout<<dp[W][4]<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}