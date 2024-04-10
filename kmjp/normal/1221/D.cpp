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

int Q;
int N;
ll A[303030],B[303030];
ll dp[303030][3];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>Q;
	while(Q--) {
		cin>>N;
		FOR(i,N) cin>>A[i]>>B[i];
		FOR(i,N+1) dp[i][0]=dp[i][1]=dp[i][2]=1LL<<60;
		dp[0][0]=0;
		dp[0][1]=B[0];
		dp[0][2]=2*B[0];
		for(i=1;i<N;i++) FOR(x,3) FOR(y,3) {
			if(A[i-1]+x==A[i]+y) continue;
			dp[i][y]=min(dp[i][y],dp[i-1][x]+y*B[i]);
		}
		cout<<min({dp[N-1][0],dp[N-1][1],dp[N-1][2]})<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}