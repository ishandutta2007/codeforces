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

int N,M;
int A[404];

int dp[404][404][404];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	for(i=1;i<=N;i++) cin>>A[i];
	
	FOR(i,404) FOR(x,404) FOR(y,404) dp[i][x][y]=1<<30;
	FOR(y,404) FOR(x,y+1) dp[x][y][0]=A[y]-A[x];
	for(i=1;i<=400;i++) {
		for(x=1;x<=N;x++) {
			r=x;
			for(y=x+i+1;y<=N;y++) {
				while(max(dp[x][r][i-1],dp[r][y][0])>=max(dp[x][r+1][i-1],dp[r+1][y][0])) r++;
				dp[x][y][i]=max(dp[x][r][i-1],dp[r][y][0]);
			}
		}
	}
	
	ll ma=0;
	FOR(i,M) {
		cin>>x>>y>>j>>k;
		k=min(k,y-x-1);
		x=dp[x][y][k];
		ma=max(ma,1LL*x*j);
	}
	cout<<ma<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}