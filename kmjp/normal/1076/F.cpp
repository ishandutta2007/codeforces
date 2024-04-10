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
int A[303030],B[303030];

ll dp[303030][2];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	scanf("%d%d",&N,&K);
	FOR(i,N) scanf("%d",&A[i]);
	FOR(i,N) scanf("%d",&B[i]);
	
	FOR(i,N) {
		dp[i+1][0]=dp[i+1][1]=K+1;
		ll miT=1+(B[i]/K);
		ll maT=1LL*(B[i]+1)*K;
		ll miF=1+(B[i]/K);
		ll maF=1LL*(B[i]+1)*K;
		if(dp[i][0]<=K) {
			x=K-dp[i][0];
			// T->T
			ll mi=(B[i]+K-1)/K;
			ll mai=1LL*(B[i]-1)*K+x;
			if(A[i]>=mi) dp[i+1][0]=min(dp[i+1][0],max(1LL,A[i]-mai));
			
			mi=(A[i]+dp[i][0]+K-1)/K;
			mai=1LL*A[i]*K;
			if(B[i]>=mi) dp[i+1][1]=min(dp[i+1][1],max(1LL,B[i]-mai));
			
		}
		if(dp[i][1]<=K) {
			x=K-dp[i][1];
			// F->F
			ll mi=(A[i]+K-1)/K;
			ll mai=1LL*(A[i]-1)*K+x;
			
			if(B[i]>=mi) dp[i+1][1]=min(dp[i+1][1],max(1LL,B[i]-mai));
			
			mi=(B[i]+dp[i][1]+K-1)/K;
			mai=1LL*B[i]*K;
			if(A[i]>=mi) dp[i+1][0]=min(dp[i+1][0],max(1LL,A[i]-mai));
		}
		
		//cout<<dp[i+1][0]<<" "<<dp[i+1][1]<<endl;
	}
	if(dp[N][0]>K && dp[N][1]>K) cout<<"NO"<<endl;
	else cout<<"YES"<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}