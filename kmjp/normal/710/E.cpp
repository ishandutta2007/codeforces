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

ll N,X,Y;
ll dp[11000000];
int up[11000000];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>X>>Y;
	for(i=0;i<=10000000;i++) dp[i]=1LL<<60;
	dp[0]=0;up[0]=1;
	FOR(x,13) {
		for(j=0;j<2*N;j++) {
			if(j<=N) i=j;
			else i=2*N-j;
			if(up[i]==0) continue;
			up[i]=0;
			if(i && dp[i-1]>dp[i]+X) dp[i-1]=dp[i]+X, up[i-1]=1;
			if(i<N && dp[i+1]>dp[i]+X) dp[i+1]=dp[i]+X, up[i+1]=1;
			
			if(i*2<=N) {
				if(dp[i*2]>dp[i]+Y) dp[i*2]=dp[i]+Y,up[i*2]=1;
			}
			else {
				if(dp[N]>dp[i]+Y+(i*2-N)*X) dp[N]=dp[i]+Y+(i*2-N)*X, up[N]=1;
			}
		}
	}
	
	
	cout<<dp[N]<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}