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

int N,H,L,R;
int A[2020];
int S[2020];

int dp[2020][2020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>H>>L>>R;
	FOR(i,N) {
		cin>>A[i];
		S[i+1]=S[i]+A[i];
	}
	FOR(x,N+1) FOR(y,N+1) dp[x][y]=-1<<20;
	dp[0][0]=0;
	FOR(x,N) {
		FOR(y,N) {
			// long
			int t=S[x+1]-y;
			dp[x+1][y]=max(dp[x+1][y],dp[x][y]+(L<=t%H&&t%H<=R));
			// short
			t=S[x+1]-y-1;
			dp[x+1][y+1]=max(dp[x+1][y+1],dp[x][y]+(L<=t%H&&t%H<=R));
		}
	}
	int ma=0;
	FOR(i,N+1) ma=max(ma,dp[N][i]);
	cout<<ma<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}