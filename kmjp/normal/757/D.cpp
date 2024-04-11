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
string S;
ll mo=1000000007;
int val[101][101];

int dp[76][1<<20];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>S;
	FOR(y,N) FOR(x,y+1) for(i=x;i<=y;i++) val[x][y]=min(100,val[x][y]*2+(S[i]-'0'));
	FOR(i,N) {
		dp[i][0]=1;
		FOR(j,1<<20) if(dp[i][j]) {
			for(x=i;x<N;x++) {
				y = val[i][x];
				if(y<=20 && y>0) {
					int mask=j | (1<<(y-1));
					dp[x+1][mask] += dp[i][j];
					if(dp[x+1][mask]>=mo) dp[x+1][mask]-=mo;
				}
			}
		}
	}
	ll ret=0;
	FOR(i,N+1) {
		for(j=1;j<=20;j++) ret += dp[i][(1<<j)-1];
	}
	cout<<ret%mo<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}