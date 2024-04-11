#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
template<class T> bool chmax(T &a, const T &b) { if(a<b){a=b;return 1;}return 0;}
template<class T> bool chmin(T &a, const T &b) { if(a>b){a=b;return 1;}return 0;}
//-------------------------------------------------------

int N,M;
int A[444];

int dp[255][255][255];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,N) cin>>A[i];
	
	FOR(i,255) FOR(x,255) FOR(y,255) dp[i][x][y]=1<<20;
	dp[0][0][M]=0;
	int sum=0;
	FOR(i,N) {
		sum+=A[i];
		FOR(x,M+1) FOR(y,M+1) if(dp[i][x][y]<1<<20) {
			for(k=0;k<=y&&x+k<=M;k++) {
				dp[i+1][x+k][k]=min(dp[i+1][x+k][k],dp[i][x][y]+abs(x+k-sum));
			}
		}
	}
	int ret=1<<20;
	FOR(i,M+1) ret=min(ret,dp[N][M][i]);
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}