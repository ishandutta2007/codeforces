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
int B;

int D[5050],C[5050],X[5050],V[5050];
vector<int> E[5050];
int dp[5100][5100][2];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>B;
	FOR(i,N) {
		cin>>C[i]>>D[i];
		D[i]=C[i]-D[i];
		if(i) {
			cin>>X[i];
			X[i]--;
			E[X[i]].push_back(i);
		}
	}
	
	for(i=N-1;i>=0;i--) {
		FOR(y,N+1) dp[i][y][0]=dp[i][y][1]=1000000007;
		dp[i][0][0]=0;
		dp[i][1][0]=C[i];
		dp[i][1][1]=D[i];
		V[i]=1;
		FORR(e,E[i]) {
			for(j=V[i];j>=0;j--) {
				for(x=1;x<=V[e];x++) {
					dp[i][x+j][0]=min(dp[i][x+j][0],dp[i][j][0]+dp[e][x][0]);
					dp[i][x+j][1]=min(dp[i][x+j][1],dp[i][j][1]+min(dp[e][x][0],dp[e][x][1]));
				}
			}
			V[i]+=V[e];
		}
		/*
		cout<<i<<endl;
		FOR(j,V[i]+1) cout<<dp[i][j][0]<<" ";
		cout<<endl;
		FOR(j,V[i]+1) cout<<dp[i][j][1]<<" ";
		cout<<endl;
		*/
	}
	
	
	
	
	for(y=N;y>=0;y--) if(dp[0][y][0]<=B || dp[0][y][1]<=B) break;
	cout<<y<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}