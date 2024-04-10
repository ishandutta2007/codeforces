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

ll N;
ll R[3],D;
ll A[1010101];

ll dp[1010101][2];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	scanf("%d%d%d%d%d",&x,&y,&i,&j,&k);
	N=x;
	R[0]=y;
	R[1]=i;
	R[2]=j;
	D=k;
	FOR(i,N) {
		scanf("%d",&x);
		A[i]=x;
	}
	
	dp[0][0]=0;
	dp[0][1]=1LL<<60;
	ll ret=1LL<<60;
	FOR(i,N) {
		dp[i+1][0]=dp[i+1][1]=1LL<<60;
		
		dp[i+1][0]=min(dp[i+1][0],dp[i][0]+1LL*A[i]*R[0]+R[2]+D);
		dp[i+1][0]=min(dp[i+1][0],dp[i][1]+1LL*A[i]*R[0]+R[2]+3*D);
		dp[i+1][0]=min(dp[i+1][0],dp[i][1]+min((ll)R[1]+R[0],1LL*(A[i]+2)*R[0])+3*D);
		if(i==N-1) ret=min(ret,dp[i][1]+1LL*A[i]*R[0]+R[2]+D);
		dp[i+1][1]=min(dp[i+1][1],dp[i][0]+min((ll)R[1]+R[0],1LL*(A[i]+2)*R[0])+D);
	}
	ret=min(ret,dp[N][0]-D);
	ret=min(ret,dp[N][1]+D);
	cout<<ret<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}