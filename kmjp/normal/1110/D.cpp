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
int A[1010101];

int dp[1010101][3][3];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	scanf("%d%d",&N,&M);
	FOR(i,N) {
		scanf("%d",&x);
		A[x+3]++;
	}
	
	FOR(i,1010000) {
		FOR(x,3) FOR(y,3) dp[i][x][y]=-1<<25;
	}
	dp[0][0][0]=0;
	FOR(i,1010000) FOR(x,3) FOR(y,3) if(dp[i][x][y]>=0) {
		int a,b,c;
		FOR(a,x+1) FOR(b,y+1) FOR(c,3) {
			int lef=A[i]-(a+b+c);
			if(lef<0) continue;
			dp[i+1][b][c]=max(dp[i+1][b][c],dp[i][x][y]+a+lef/3);
		}
	}
	
	
	cout<<dp[1005000][0][0]<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}