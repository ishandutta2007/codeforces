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
string S[2020];
int R[2020][2020];
int D[2020][2020];
const ll mo=1000000007;
ll dp[2020][2020][2];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W;
	FOR(y,H) {
		cin>>S[y];
		for(x=W-1;x>=0;x--) {
			R[y][x]=R[y][x+1];
			if(S[y][x]=='R') R[y][x]++;
		}
	}
	FOR(x,W) {
		for(y=H-1;y>=0;y--) {
			D[y][x]=D[y+1][x];
			if(S[y][x]=='R') D[y][x]++;
		}
	}
	if(H==1 && W==1) return _P("1\n");
	dp[0][0][0]=dp[0][0][1]=1;
	dp[0][1][0]=mo-1;
	dp[1][0][1]=mo-1;
	FOR(y,H) FOR(x,W) {
		if(x) {
			dp[y][x][0]+=dp[y][x-1][0];
		}
		if(y) {
			dp[y][x][1]+=dp[y-1][x][1];
		}
		dp[y][x][0]%=mo;
		dp[y][x][1]%=mo;
		// down
		int tar=H-1-D[y+1][x];
		dp[y+1][x][1]+=dp[y][x][0];
		dp[tar+1][x][1]+=mo-dp[y][x][0];
		tar=W-1-R[y][x+1];
		dp[y][x+1][0]+=dp[y][x][1];
		dp[y][tar+1][0]+=mo-dp[y][x][1];
	}
	cout<<(dp[H-1][W-1][0]+dp[H-1][W-1][1])%mo<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}