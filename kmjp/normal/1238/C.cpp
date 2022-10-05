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
int H,N;
int P[202020];
int dp[202020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>Q;
	while(Q--) {
		cin>>H>>N;
		int ret=0;
		FOR(i,N) {
			cin>>P[i];
			dp[i]=1<<30;
		}
		P[N]=0;
		dp[N]=1<<30;
		dp[0]=0;
		FOR(i,N) {
			if(i<N-1 && P[i+1]==P[i+2]+1) dp[i+2]=min(dp[i+2],dp[i]);
			dp[i+1]=min(dp[i+1],dp[i]+1);
		}
		cout<<min(dp[N-1],dp[N])<<endl;
		
		
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}