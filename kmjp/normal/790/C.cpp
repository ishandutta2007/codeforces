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
int dp[80][80][80][2];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>S;
	int tnum[3]={};
	FORR(c,S) {
		if(c=='V') c=0;
		else if(c=='K') c=1;
		else c=2;
		tnum[c]++;
	}
	
	memset(dp,0x3f,sizeof(dp));
	dp[0][0][0][0]=0;
	FOR(i,80) FOR(j,80) FOR(k,80) {
		if(dp[i][j][k][0]<101010) {
			int num[3]={};
			FORR(c,S) {
				num[c]++;
				if(c==0 && num[c]==i+1) dp[i+1][j][k][1]=min(dp[i+1][j][k][1],dp[i][j][k][0]+max(num[1]-j,0)+max(num[2]-k,0));
				if(c==1 && num[c]==j+1) dp[i][j+1][k][0]=min(dp[i][j+1][k][0],dp[i][j][k][0]+max(num[0]-i,0)+max(num[2]-k,0));
				if(c==2 && num[c]==k+1) dp[i][j][k+1][0]=min(dp[i][j][k+1][0],dp[i][j][k][0]+max(num[0]-i,0)+max(num[1]-j,0));
			}
		}
		if(dp[i][j][k][1]<101010) {
			int num[3]={};
			FORR(c,S) {
				num[c]++;
				if(c==0 && num[c]==i+1) dp[i+1][j][k][1]=min(dp[i+1][j][k][1],dp[i][j][k][1]+max(num[1]-j,0)+max(num[2]-k,0));
				if(c==2 && num[c]==k+1) dp[i][j][k+1][0]=min(dp[i][j][k+1][0],dp[i][j][k][1]+max(num[0]-i,0)+max(num[1]-j,0));
			}
		}
	}
	cout<<min(dp[tnum[0]][tnum[1]][tnum[2]][0],dp[tnum[0]][tnum[1]][tnum[2]][1])<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}