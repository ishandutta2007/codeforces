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
int A[202020];
vector<int> E[202020];
int dp[202020];
int ret[202020];
set<int> S[202020];

void dfs(int cur,int pre) {
	dp[cur]=__gcd(dp[pre],A[cur]);
	ret[cur]=dp[pre];
	S[cur].insert(dp[pre]);
	FORR(r,S[pre]) {
		int x=__gcd(A[cur],r);
		ret[cur]=max(ret[cur],x);
		S[cur].insert(x);
	}
	FORR(e,E[cur]) if(e!=pre) dfs(e,cur);
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) cin>>A[i];
	FOR(i,N-1) {
		cin>>x>>y;
		E[x-1].push_back(y-1);
		E[y-1].push_back(x-1);
	}
	
	ret[0]=dp[0]=A[0];
	S[0].insert(0);
	FORR(e,E[0]) dfs(e,0);
	
	FOR(i,N) _P("%d%c",ret[i],(i==N-1)?'\n':' ');
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}