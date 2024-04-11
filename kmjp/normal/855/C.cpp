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
vector<int> E[101010];
int K,X;

ll dp[101010][11][3];
ll mo=1000000007;
ll A,B,C;

void dfs(int cur,int pre) {
	dp[cur][0][0]=A;
	dp[cur][1][1]=B;
	dp[cur][0][2]=C;
	
	int i,j,k;
	FORR(e,E[cur]) if(e!=pre) {
		ll tmp[11][3];
		FOR(i,11) FOR(j,3) tmp[i][j]=dp[cur][i][j];
		ZERO(dp[cur]);
		
		dfs(e,cur);
		for(int a=0;a<=X;a++) {
			for(int b=0;a+b<=X;b++) {
				(dp[cur][a+b][0] += tmp[a][0]*dp[e][b][0]+tmp[a][0]*dp[e][b][1]+tmp[a][0]*dp[e][b][2])%=mo;
				(dp[cur][a+b][1] += tmp[a][1]*dp[e][b][0])%=mo;
				(dp[cur][a+b][2] += tmp[a][2]*dp[e][b][0]+tmp[a][2]*dp[e][b][2])%=mo;
			}
		}
	}
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,N-1) {
		cin>>x>>y;
		E[x-1].push_back(y-1);
		E[y-1].push_back(x-1);
	}
	cin>>K>>X;
	
	A=K-1;
	B=1;
	C=M-K;
	
	
	dfs(0,-1);
	ll ret=0;
	FOR(i,X+1) ret+=dp[0][i][0]+dp[0][i][1]+dp[0][i][2];
	cout<<ret%mo<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}