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
string S;
int A[101010];
ll dp[5][101010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>S;
	FOR(i,N) cin>>A[i];
	FOR(i,N+1) FOR(j,5) dp[j][i]=1LL<<60;
	dp[0][0]=0;
	FOR(i,N) {
		FOR(j,4) dp[j][i+1]=min(dp[j][i]+A[i],(j==0)?1LL<<60:dp[j-1][i]);
		dp[0][i+1]=min(dp[0][i+1],dp[0][i]+(S[i]=='h')*A[i]);
		dp[1][i+1]=min(dp[1][i+1],dp[1][i]+(S[i]=='a')*A[i]);
		dp[2][i+1]=min(dp[2][i+1],dp[2][i]+(S[i]=='r')*A[i]);
		dp[3][i+1]=min(dp[3][i+1],dp[3][i]+(S[i]=='d')*A[i]);
	}
	
	cout<<min({dp[0][N],dp[1][N],dp[2][N],dp[3][N]})<<endl;;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}