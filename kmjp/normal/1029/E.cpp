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
vector<int> E[202020];
ll dp[202020][4];
// 0-no cur and child
// 1-cur
// 2-no cur but child

void dfs(int cur,int pre) {
	// need edge
	dp[cur][1]=1;
	dp[cur][3]=10101010;
	FORR(e,E[cur]) if(e!=pre) {
		dfs(e,cur);
		dp[cur][0]+=min({dp[e][1],dp[e][2]});
		dp[cur][1]+=min({dp[e][0],dp[e][1],dp[e][2]});
		dp[cur][3]=min(dp[cur][3]+min({dp[e][1],dp[e][2]}),dp[cur][2]+dp[e][1]);
		dp[cur][2]+=dp[e][2];
	}
	dp[cur][2]=dp[cur][3];
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N-1) {
		cin>>x>>y;
		E[x].push_back(y);
		E[y].push_back(x);
	}
	ll ret=0;
	FORR(e,E[1]) {
		dfs(e,1);
		ret+=min({dp[e][0],dp[e][1]-1,dp[e][2]});
	}
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}