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

int N,P,K;
int A[101010];
int S[101010][7];

pair<int,int> B[101010];

ll dp[101010][1<<7];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	scanf("%d%d%d",&N,&P,&K);
	FOR(i,N) {
		scanf("%d",&A[i]);
		B[i]={A[i],i};
	}
	FOR(i,N) FOR(j,P) scanf("%d",&S[i][j]);
	
	sort(B,B+N);
	reverse(B,B+N);
	FOR(i,N+1) FOR(j,1<<P) dp[i][j]=-1LL<<60;
	dp[0][0]=0;
	FOR(i,N) {
		int mask;
		FOR(mask,1<<j) {
			int al=i-__builtin_popcount(mask);
			if(al<K) dp[i+1][mask]=max(dp[i+1][mask],dp[i][mask]+B[i].first);
			else dp[i+1][mask]=max(dp[i+1][mask],dp[i][mask]);
			if(al<K) dp[i+1][mask]=max(dp[i+1][mask],dp[i][mask]+B[i].first);
			FOR(j,P) if((mask&(1<<j))==0) dp[i+1][mask|(1<<j)]=max(dp[i+1][mask|(1<<j)],dp[i][mask]+S[B[i].second][j]);
		}
	}
	cout<<dp[N][(1<<P)-1]<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}