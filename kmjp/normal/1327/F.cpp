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

int N,K,M;
int L[505050],R[505050],X[505050];
int add[505050][30];
const ll mo=998244353;

vector<pair<int,int>> E[30];
ll dp[505050];


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	scanf("%d%d%d",&N,&K,&M);
	FOR(i,M) {
		scanf("%d%d%d",&L[i],&R[i],&X[i]);
		R[i]++;
		FOR(j,30) {
			if(X[i]&(1<<j)) add[L[i]][j]++,add[R[i]][j]--;
			else E[j].push_back({L[i],R[i]});
		}
	}
	
	FOR(j,30) {
		FOR(i,N) {
			add[i+1][j]+=add[i][j];
		}
	}
	
	
	ll ret=1;
	FOR(i,K) {
		vector<pair<int,int>> R;
		sort(ALL(E[i]));
		FORR(e,E[i]) {
			while(R.size() && e.second<=R.back().second) R.pop_back();
			if(R.empty() || R.back().first<e.first) R.push_back(e);
		}
		R.push_back({N+2,N+3});
		ZERO(dp);
		dp[0]=1;
		dp[1]=mo-1;
		int cur=0;
		FOR(j,N+1) {
			if(j) {
				dp[j]+=dp[j-1];
				if(dp[j]>=mo) dp[j]-=mo;
			}
			if(add[j][i]==0) {
				ll v=dp[j];
				while(R[cur].first<=j) cur++;
				dp[j+1]+=v;
				if(dp[j+1]>=mo) dp[j+1]-=mo;
				dp[R[cur].second]+=mo-v;
				if(dp[R[cur].second]>=mo) dp[R[cur].second]-=mo;
			}
		}
		dp[N+1]+=dp[N];
		ret=ret*dp[N+1]%mo;
	}
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}