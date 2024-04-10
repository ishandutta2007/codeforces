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
vector<int> E[3030];
int num[3030][3030];
int L[3030][3030];
int P[3030][3030];

ll dp[3030][3030];
vector<pair<int,int>> C[3030];

int dfs(int cur,int pre,int id) {
	num[id][cur]=1;
	P[id][cur]=pre;
	if(cur!=pre) {
		L[id][cur]=L[id][pre]+1;
		C[L[id][cur]].push_back({id,cur});
	}
	
	
	FORR(e,E[cur]) if(e!=pre) num[id][cur]+=dfs(e,cur,id);
	return num[id][cur];
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N-1) {
		cin>>x>>y;
		E[x-1].push_back(y-1);
		E[y-1].push_back(x-1);
	}
	FOR(i,N) dfs(i,i,i);
	
	ll ma=0;
	FORR(c,C[1]) {
		x=c.first,y=c.second;
		dp[x][y]=num[x][y]*num[y][x];
		ma=max(ma,dp[x][y]);
	}
	for(i=2;i<=3000;i++) FORR(c,C[i]) {
		x=c.first,y=c.second;
		dp[x][y]=max(dp[x][y],dp[x][P[x][y]]+num[x][y]*num[y][x]);
		dp[x][y]=max(dp[x][y],dp[P[y][x]][y]+num[x][y]*num[y][x]);
		ma=max(ma,dp[x][y]);
	}
	cout<<ma<<endl;
	
	
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}