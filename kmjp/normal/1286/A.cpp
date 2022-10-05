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
int P[101];
int C[2];

int dp[105][105][105][2];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	if(N==1) return _P("0\n");
	
	C[0]=N/2;
	C[1]=N-C[0];
	
	FOR(i,102) FOR(x,101) FOR(y,101) dp[i][x][y][0]=dp[i][x][y][1]=1010;

	FOR(i,N) {
		cin>>P[i];
		
		if(i==0) {
			if(P[i]==0 || P[i]%2==0) dp[i+1][N/2-1][N-N/2][0]=0;
			if(P[i]==0 || P[i]%2==1) dp[i+1][N/2][N-N/2-1][1]=0;
		}
		else {
			FOR(j,2) FOR(x,101) FOR(y,101) if(dp[i][x][y][j]<1000) {
				if(x&&((P[i]==0)||(P[i]%2==0))) {
					dp[i+1][x-1][y][0]=min(dp[i+1][x-1][y][0],dp[i][x][y][j]+(j==1));
				}
				if(y&&((P[i]==0)||(P[i]%2==1))) {
					dp[i+1][x][y-1][1]=min(dp[i+1][x][y-1][1],dp[i][x][y][j]+(j==0));
				}
			}
		}
	}
	
	cout<<min(dp[N][0][0][0],dp[N][0][0][1])<<endl;
	
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}