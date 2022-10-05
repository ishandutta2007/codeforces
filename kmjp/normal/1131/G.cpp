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
vector<int> A[303030],CT[303030];
int Q;
int H[10101010];
ll C[10101010];
ll dp[10101010];

int L[10101010],R[10101010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	scanf("%d%d",&N,&M);
	FOR(i,N) {
		scanf("%d",&x);
		A[i].resize(x);
		CT[i].resize(x);
		FOR(j,x) scanf("%d",&A[i][j]);
		FOR(j,x) scanf("%d",&CT[i][j]);
	}
	scanf("%d",&Q);
	int cur=1;
	FOR(i,Q) {
		scanf("%d%d",&x,&y);
		FOR(j,A[x-1].size()) {
			dp[cur]=1LL<<60;
			H[cur]=A[x-1][j];
			C[cur]=CT[x-1][j]*1LL*y;
			cur++;
		}
	}
	deque<pair<int,int>> D;
	for(i=1;i<=M;i++) {
		int LM=i-(H[i]-1);
		while(D.size() && D.back().second>=LM) LM=min(LM,D.back().first), D.pop_back();
		L[i]=max(1,LM);
		D.push_back({L[i],i});
	}
	D.clear();
	for(i=M;i>=1;i--) {
		int RM=i+H[i]-1;
		while(D.size() && D.back().second<=RM) RM=max(RM,D.back().first), D.pop_back();
		R[i]=min(M,RM);
		D.push_back({R[i],i});
	}
	
	deque<pair<int,ll>> Q;
	for(i=1;i<=M;i++) {
		dp[i]=dp[L[i]-1]+C[i];
		while(Q.size()&&Q.back().first<i) Q.pop_back();
		if(Q.size()) dp[i]=min(dp[i],Q.back().second);
		
		ll co=dp[i-1]+C[i];
		if(Q.empty()||co<Q.back().second) Q.push_back({R[i],co});
		
		
	}
	cout<<dp[M]<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}