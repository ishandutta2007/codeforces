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
ll mo=998244353;

ll dp[101010][202][3]; //0up 1same 2down


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) cin>>A[i+1];
	
	for(x=1;x<=200;x++) {
		if(A[1]==-1 || A[1]==x) dp[1][x][0]=1;
	}
	
	for(i=2;i<=N;i++) {
		ll up=0;
		for(x=1;x<=200;x++) {
			if(A[i]==-1 || A[i]==x) {
				(dp[i][x][1]=dp[i-1][x][0]+dp[i-1][x][1]+dp[i-1][x][2])%=mo;
				(dp[i][x][0]=up)%=mo;
			}
			(up+=dp[i-1][x][0]+dp[i-1][x][1]+dp[i-1][x][2])%=mo;
		}
		ll down=0;
		for(x=200;x>=1;x--) {
			if(A[i]==-1 || A[i]==x) dp[i][x][2]=down;
			(down+=dp[i-1][x][1]+dp[i-1][x][2])%=mo;
		}
	}
	
	ll ret=0;
	for(x=1;x<=200;x++) ret+=dp[N][x][1]+dp[N][x][2];
	cout<<ret%mo<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}