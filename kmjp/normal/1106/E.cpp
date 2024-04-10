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

int S[101010],T[101010],D[101010],W[101010];

int to[101010],cost[101010];
vector<int> add[101010],del[101010];

ll dp[101010][202];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	multiset<pair<int,int>> cand;
	cin>>N>>M>>K;
	
	FOR(i,K) {
		cin>>S[i]>>T[i]>>D[i]>>W[i];
		add[S[i]].push_back(i);
		del[T[i]].push_back(i);
	}
	
	FOR(i,N+2) FOR(j,M+1) dp[i][j]=1LL<<60;
	
	
	for(i=1;i<=N;i++) {
		FORR(a,add[i]) cand.insert({W[a],D[a]});
		if(cand.empty()) {
			to[i]=-1;
		}
		else {
			to[i]=cand.rbegin()->second+1;
			cost[i]=cand.rbegin()->first;
		}
		
		FORR(a,del[i]) cand.erase(cand.find({W[a],D[a]}));
	}
	
	dp[1][M]=0;
	for(i=1;i<=N;i++) {
		if(to[i]==-1) {
			FOR(j,M+1) dp[i+1][j]=min(dp[i+1][j],dp[i][j]);
		}
		else {
			FOR(j,M+1) {
				dp[to[i]][j]=min(dp[to[i]][j],dp[i][j]+cost[i]);
				if(j) dp[i+1][j-1]=min(dp[i+1][j-1],dp[i][j]);
			}
		}
	}
	
	
	ll ret=1LL<<60;
	FOR(i,M+1) ret=min(ret,dp[N+1][i]);
	cout<<ret<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}