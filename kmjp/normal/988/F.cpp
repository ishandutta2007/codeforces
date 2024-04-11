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

int N,M,A;
int rain[2020];
vector<int> U[2020];
int P[2020];

ll dp[2020][2020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>A>>N>>M;
	FOR(i,N) {
		cin>>x>>y;
		while(x<y) rain[x++]=1;
	}
	FOR(i,A) U[i].push_back(0);
	FOR(i,M) {
		cin>>x>>P[i+1];
		U[x].push_back(i+1);
	}
	FOR(x,2010) FOR(y,2010) dp[x][y]=1LL<<60;
	dp[0][0]=0;
	FOR(i,A) {
		ll mi=1LL<<60;
		FOR(x,M+1) mi=min(mi,dp[i][x]);
		FORR(u,U[i]) dp[i][u]=mi;
		FOR(x,M+1) {
			if(rain[i] && x==0) continue;
			dp[i+1][x]=min(dp[i+1][x],dp[i][x]+P[x]);
		}
	}
	ll mi=1LL<<60;
	FOR(x,M+1) mi=min(mi,dp[A][x]);
	if(mi==1LL<<60) mi=-1;
	
	cout<<mi<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}