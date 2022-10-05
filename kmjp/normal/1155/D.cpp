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

int N,X;
ll dp[303030][5];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>X;
	ll ret=0;
	FOR(i,N) {
		cin>>x;
		
		dp[i+1][0]=dp[i][0];
		dp[i+1][1]=max(dp[i][0],dp[i][1])+x;
		dp[i+1][2]=max({dp[i][0],dp[i][1],dp[i][2]})+1LL*x*X;
		dp[i+1][3]=max({dp[i][0],dp[i][1],dp[i][2],dp[i][3]})+x;
		dp[i+1][4]=max({dp[i][0],dp[i][1],dp[i][2],dp[i][3],dp[i][4]});
	}
	cout<<max({dp[N][0],dp[N][1],dp[N][2],dp[N][3],dp[N][4]})<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}