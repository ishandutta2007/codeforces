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
string S[2];

int dp[101][4];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>S[0]>>S[1];
	N=S[0].size();
	
	dp[0][1]=dp[0][2]=dp[0][3]=-1010;
	
	FOR(i,N) {
		x=(S[0][i]=='0')+(S[1][i]=='0')*2;
		FOR(j,4) dp[i+1][j]=-1010;
		FOR(j,4) {
			dp[i+1][x]=max(dp[i+1][x],dp[i][j]);
			
			if(j==3) {
				if(x&1) dp[i+1][x^1]=max(dp[i+1][x^1],dp[i][j]+1);
				if(x&2) dp[i+1][x^2]=max(dp[i+1][x^2],dp[i][j]+1);
			}
			if(j && x==3) dp[i+1][0]=max(dp[i+1][0],dp[i][j]+1);
		}
	}
	
	cout<<max({dp[N][0],dp[N][1],dp[N][2],dp[N][3]})<<endl;;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}