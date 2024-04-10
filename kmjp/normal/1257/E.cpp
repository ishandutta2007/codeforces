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


int N[3],M;
int P[202020];
int dp[202020][3];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	FOR(i,3) cin>>N[i];
	M=N[0]+N[1]+N[2];
	FOR(i,3) {
		FOR(j,N[i]) {
			cin>>x;
			P[x]=i;
		}
	}
	FOR(i,M+1) FOR(j,3) dp[i][j]=1<<20;
	dp[0][0]=0;
	for(i=1;i<=M;i++) {
		for(x=0;x<=2;x++) for(y=x;y<=2;y++) {
			dp[i][y]=min(dp[i][y],dp[i-1][x]+(P[i]!=y));
		}
	}
	
	cout<<min({dp[M][0],dp[M][1],dp[M][2]})<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}