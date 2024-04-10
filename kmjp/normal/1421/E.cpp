#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int N;
ll A[202020];
ll dp[202020][3][2][2];

void solve() {
	int i,j,k,l,r,x,y;
	
	memset(dp,-100,sizeof(dp));
	
	cin>>N;
	FOR(i,N) cin>>A[i];
	
	if(N==1) {
		cout<<A[0]<<endl;
		return;
	}
	
	
	dp[0][0][0][0]=A[0];
	dp[0][1][1][0]=-A[0];
	int m,p,s;
	for(i=1;i<N;i++) {
		FOR(m,3) FOR(p,2) FOR(s,2) {
			// plus
			dp[i][m][0][s|(p==0)]=max(dp[i][m][0][s|(p==0)],dp[i-1][m][p][s]+A[i]);
			//minus
			dp[i][(m+1)%3][1][s|(p==1)]=max(dp[i][(m+1)%3][1][s|(p==1)],dp[i-1][m][p][s]-A[i]);
		}
	}
	ll ret=max(dp[N-1][((1-N)%3+3)%3][0][1],dp[N-1][((1-N)%3+3)%3][1][1]);
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}