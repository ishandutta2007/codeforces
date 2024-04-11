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

int N;
int A[202020];
int dp[202020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) dp[i]=1<<30;
	FOR(i,N) cin>>A[i], A[i]--;
	
	dp[0]=0;
	queue<int> Q;
	Q.push(0);
	while(Q.size()) {
		int cur=Q.front();
		Q.pop();
		
		if(cur && dp[cur-1]>dp[cur]+1) {
			dp[cur-1]=dp[cur]+1;
			Q.push(cur-1);
		}
		if(cur<N-1 && dp[cur+1]>dp[cur]+1) {
			dp[cur+1]=dp[cur]+1;
			Q.push(cur+1);
		}
		if(dp[A[cur]]>dp[cur]+1) {
			dp[A[cur]]=dp[cur]+1;
			Q.push(A[cur]);
		}
	}
	FOR(i,N) _P("%d%s",dp[i],(i==N-1)?"\n":" ");
	
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}