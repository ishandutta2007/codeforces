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
vector<int> E[303030];

const ll mo=998244353;
ll dp[303030][2][2];
// 0/1 selected
// 0/1 edge

void dfs(int cur,int pre) {
	dp[cur][0][0]=dp[cur][1][0]=1;
	FORR(e,E[cur]) if(e!=pre) {
		dfs(e,cur);
		ll to[2][2]={};
		int a,b,c,d,f;
		FOR(a,2) FOR(b,2) FOR(c,2) FOR(d,2) FOR(f,2) {
			if(f&&a&&c) continue;
			if(f==0 && c&&d==0) continue;
			(to[a][b|f]+=dp[cur][a][b]*dp[e][c][d])%=mo;
		}
		FOR(a,2) FOR(b,2) dp[cur][a][b]=to[a][b];
	}
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N-1) {
		cin>>x>>y;
		E[x-1].push_back(y-1);
		E[y-1].push_back(x-1);
	}
	dfs(0,0);
	cout<<(dp[0][0][0]+dp[0][0][1]+dp[0][1][1]+mo-1)%mo<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}