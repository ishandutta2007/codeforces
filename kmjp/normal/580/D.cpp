#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int N,M,K;
ll A[20];
ll mat[20][20];
ll dp[1<<18][18];

void solve() {
	int i,j,k,l,r,x,y; string s;
	ll ma=0;
	
	cin>>N>>M>>K;
	FOR(i,N) {
		cin>>A[i];
		dp[1<<i][i]=A[i];
		ma=max(ma,A[i]);
	}
	FOR(i,K) {
		cin>>x>>y>>r;
		mat[x-1][y-1]=r;
	}
	
	for(int mask=1;mask<1<<N;mask++) if(__builtin_popcount(mask)<M) {
		FOR(i,N) if(mask&(1<<i)) {
			FOR(x,N) if((mask&(1<<x))==0) {
				dp[mask | (1<<x)][x] = max(dp[mask | (1<<x)][x], dp[mask][i] + A[x] + mat[i][x]);
				ma=max(ma,dp[mask | (1<<x)][x]);
			}
		}
	}
	
	cout<<ma<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}