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

int N,K;
int A[101010];
vector<int> E[202];
vector<int> dp[202];
int ma=0;

void dfs(int cur,int pre) {
	int i;
	FOR(i,E[cur].size()) if(E[cur][i]==pre) {
		E[cur].erase(E[cur].begin()+i);
		break;
	}
	dp[cur].resize(N,0);
	vector<int> S(N,0);
	FORR(e,E[cur]) {
		dfs(e,cur);
		FOR(i,N) S[i]+=dp[e][i];
	}
	dp[cur][0]=A[cur]+S[K-1];
	
	ma=max(ma,dp[cur][0]);
	
	
	FORR(e,E[cur]) {
		FOR(i,N) S[i]-=dp[e][i];
		
		for(int a=1;a<N;a++) {
			int b=max(a,K-a);
			dp[cur][a]=max(dp[cur][a],dp[e][a-1]+S[b-1]);
			ma=max(ma,dp[cur][a]);
		}
		
		FOR(i,N) S[i]+=dp[e][i];
	}
	for(i=N-2;i>=0;i--) dp[cur][i]=max(dp[cur][i],dp[cur][i+1]);
	
	
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K;
	K++;
	FOR(i,N) {
		cin>>A[i];
		ma=max(ma,A[i]);
	}
	if(K>=N) {
		cout<<ma<<endl;
		return;
	}
	FOR(i,N-1) {
		cin>>x>>y;
		E[x-1].push_back(y-1);
		E[y-1].push_back(x-1);
	}
	
	
	dfs(0,-1);
	
	
	cout<<ma<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}