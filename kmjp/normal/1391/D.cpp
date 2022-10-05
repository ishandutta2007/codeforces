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

int H,W;
string S[1010101];
int dp[1010101][8];
int mask[1010101];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W;
	FOR(y,H) cin>>S[y];
	
	if(H>=4&&W>=4) {
		cout<<-1<<endl;
		return;
	}
	if(H==1) {
		cout<<0<<endl;
		return;
	}
	
	FOR(x,W) {
		FOR(y,H) if(S[y][x]=='1') mask[x]|=1<<y;
	}
	
	FOR(y,1<<H) dp[0][y]=__builtin_popcount(mask[0]^y);
	for(x=1;x<W;x++) {
		FOR(y,1<<H) {
			dp[x][y]=1<<25;
			FOR(i,1<<H) {
				j=i^y;
				if(H>=2&&__builtin_popcount(j&3)!=1)continue;
				if(H>=3&&__builtin_popcount(j&6)!=1)continue;
				dp[x][y]=min(dp[x][y],dp[x-1][i]+__builtin_popcount(mask[x]^y));
			}
		}
	}
	int ret=1<<30;
	FOR(y,1<<H) ret=min(ret,dp[W-1][y]);
	cout<<ret<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}