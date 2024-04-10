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
pair<int,int> P[101];

ll dp[101010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,N) cin>>P[i].first>>P[i].second;
	sort(P,P+N);
	/*
	vector<pair<int,int>> V;
	FOR(i,N) {
		if(V.size()&&V.back().first+V.back().second>=P[i].first+P[i].second) continue;
		while(V.size() && P[i].first-P[i].second<=V.back().first-V.back().second) V.pop_back();
		V.push_back(P[i]);
	}
	N=V.size();
	*/
	FOR(j,M+1) dp[j+1]=1LL<<60;
	FOR(i,N) {
		for(j=0;j<P[i].first-P[i].second;j++) {
			dp[min(M,P[i].first+(P[i].first-j-1))]=min(dp[min(M,P[i].first+(P[i].first-j-1))],dp[j]+(P[i].first-j-1-P[i].second));
		}
		for(j=max(0,P[i].first-P[i].second-1);j<=min(M,P[i].first+P[i].second);j++) {
			dp[min(M,P[i].first+P[i].second)]=min(dp[min(M,P[i].first+P[i].second)],dp[j]);
		}
		for(j=1;j<M;j++) dp[j+1]=min(dp[j+1],dp[j]+1);
		for(j=M-1;j>=1;j--) dp[j]=min(dp[j+1],dp[j]);
		
	}
	cout<<dp[M]<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}