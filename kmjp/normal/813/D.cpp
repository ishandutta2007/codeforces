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
int A[5050],B[5050];
short cand[5050][5050][3];
int dp[5050][5050];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) cin>>A[i], B[i]=A[i]%7;
	
	for(x=1;x<=N;x++) {
		dp[0][x]=1;
		cand[0][x][0]=cand[0][x][1]=cand[0][x][2]=x;
		cand[x][N+1][0]=cand[x][N+1][1]=cand[x][N+1][2]=N+1;
		for(y=N;y>x;y--) {
			cand[x][y][0]=cand[x][y+1][0];
			cand[x][y][1]=cand[x][y+1][1];
			cand[x][y][2]=cand[x][y+1][2];
			if(A[x-1]-A[y-1]==1) cand[x][y][0]=y;
			if(A[x-1]-A[y-1]==-1) cand[x][y][1]=y;
			if(B[x-1]==B[y-1]) cand[x][y][2]=y;
		}
	}
	
	int ma=0;
	for(y=0;y<N+1;y++) {
		FOR(x,y) {
			dp[x][y]=max(dp[x][y],dp[0][x]+1);
			ma=max(ma,dp[x][y]);
			FOR(i,3) {
				j=cand[x][y+1][i];
				if(j<=N) dp[y][j]=max(dp[y][j],dp[x][y]+1);
				j=cand[y][y+1][i];
				if(j<=N) dp[x][j]=max(dp[x][j],dp[x][y]+1);
			}
		}
	}
	cout<<ma<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}