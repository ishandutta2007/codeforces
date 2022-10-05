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
int A[101010];
int F[101010];
int dp[101010][6];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) cin>>A[i];
	MINUS(dp);
	FOR(i,5) dp[N-1][i]=0;
	for(i=N-2;i>=0;i--) {
		FOR(x,5) FOR(y,5) if(dp[i+1][y]>=0) {
			if(A[i]==A[i+1] && x!=y) dp[i][x]=y;
			if(A[i]<A[i+1] && x<y) dp[i][x]=y;
			if(A[i]>A[i+1] && x>y) dp[i][x]=y;
		}
	}
	
	FOR(i,5) if(dp[0][i]>=0) {
		FOR(x,N) {
			cout<<(i+1)<<" ";
			i=dp[x][i];
		}
		cout<<endl;
		return;
		
	}
	cout<<-1<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}