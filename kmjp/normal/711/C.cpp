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

int N,M,K;
int C[1010];
int A[110][110];
ll dp[110][110][110];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M>>K;
	FOR(i,N) cin>>C[i];
	FOR(y,N) FOR(x,M) cin>>A[y][x];
	
	memset(dp,0x3f,sizeof(dp));
	dp[0][0][0]=0;
	FOR(i,N) {
		FOR(x,M+1) {
			FOR(y,i+1) if(dp[i][x][y]<1LL<<59) {
				if(C[i]==0) {
					for(r=1;r<=M;r++) {
						if(x==r) dp[i+1][r][y] = min(dp[i+1][r][y],dp[i][x][y]+A[i][r-1]);
						else dp[i+1][r][y+1] = min(dp[i+1][r][y+1],dp[i][x][y]+A[i][r-1]);
					}
				}
				else {
					if(x==C[i]) dp[i+1][x][y] = min(dp[i+1][x][y],dp[i][x][y]);
					else dp[i+1][C[i]][y+1] = min(dp[i+1][C[i]][y+1],dp[i][x][y]);
				}
			}
		}
	}
	
	ll mi=1LL<<60;
	for(r=1;r<=M;r++) mi=min(mi,dp[N][r][K]);
	if(mi==1LL<<60) mi=-1;
	cout<<mi<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}