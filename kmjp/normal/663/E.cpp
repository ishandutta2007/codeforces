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

ll dp[21][1<<20];
string S[21];
int H,W;

void solve() {
	int i,j,k,l,r,x,y; string s;
	cin>>H>>W;
	FOR(y,H) cin>>S[y];
	FOR(x,W) {
		r=0;
		FOR(y,H) r |= (S[y][x]-'0')<<y;
		dp[0][r]++;
	}
	for(k=1;k<=H;k++) {
		FOR(r,1<<H) {
			if(k>=2) dp[k][r] = (k-2-H)*dp[k-2][r];
			FOR(i,H) dp[k][r] += dp[k-1][r ^ (1<<i)];
			assert(dp[k][r]%k==0);
			dp[k][r]/=k;
		}
	}
	ll mi=1LL<<60;
	FOR(r,1<<H) {
		ll tot=0;
		FOR(i,H) tot += min(i,H-i)*dp[i][r];
		mi=min(mi,tot);
	}
	cout<<mi<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}