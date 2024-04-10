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

int NR,NG,NB;
int R[2020],G[2020],B[2020];
ll dp[202][202][202];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>NR>>NG>>NB;
	FOR(i,NR) cin>>R[i];
	FOR(i,NG) cin>>G[i];
	FOR(i,NB) cin>>B[i];
	sort(R,R+NR);
	sort(G,G+NG);
	sort(B,B+NB);
	
	ll ret=0;
	dp[NR][NG][NB]=0;
	for(int r=NR;r>=0;r--) for(int g=NG;g>=0;g--) for(int b=NB;b>=0;b--) {
		ret=max(ret,dp[r][g][b]);
		if(r&&g) dp[r-1][g-1][b]=max(dp[r-1][g-1][b],dp[r][g][b]+R[r-1]*G[g-1]);
		if(r&&b) dp[r-1][g][b-1]=max(dp[r-1][g][b-1],dp[r][g][b]+R[r-1]*B[b-1]);
		if(g&&b) dp[r][g-1][b-1]=max(dp[r][g-1][b-1],dp[r][g][b]+G[g-1]*B[b-1]);
	}
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}