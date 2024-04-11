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
ll mo=1000000007;

ll dp[405][405];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	dp[0][0]=1;
	for(i=1;i<=400;i++) {
		FOR(x,404) FOR(y,404) if(x+y<404) {
			ll pat=dp[i-1][x]*dp[i-1][y]%mo;
			//take 0 and connect 1
			(dp[i][x+y] += pat*(1+2*(x+y)))%=mo;
			//connect 2
			if(x+y>0) (dp[i][x+y-1] += pat*((x+y)*(x+y-1)))%=mo;
			//new
			dp[i][x+y+1] += pat;
			if(dp[i][x+y+1]>=mo) dp[i][x+y+1]-=mo;
		}
	}
	cin>>N;
	cout<<dp[N][1]<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}