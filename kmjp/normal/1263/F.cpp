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
int M[2];
int P[2][2010];
vector<int> E[2][2010];
int R[2][2010];
int D[2][2010];

int dif[2][2010][2010];
int dp[2010][2010];

void dfs(int id,int cur,int d) {
	D[id][cur]=d;
	FORR(e,E[id][cur]) dfs(id,e,d+1);
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(x,2) {
		cin>>M[x];
		FOR(i,M[x]-1) {
			cin>>P[x][i+2];
			E[x][P[x][i+2]].push_back(i+2);
		}
		dfs(x,1,0);
		FOR(i,N) {
			cin>>R[x][i];
		}
		
		FOR(i,N) {
			dif[x][0][i+1]=D[x][R[x][i]];
		}
		FOR(j,N) FOR(i,j) {
			int a=R[x][i];
			int b=R[x][j];
			while(D[x][a]>D[x][b]) a=P[x][a];
			while(D[x][a]<D[x][b]) b=P[x][b];
			while(a!=b) {
				a=P[x][a];
				b=P[x][b];
			}
			dif[x][i+1][j+1]=D[x][R[x][j]]-D[x][b];
		}
	}
	FOR(x,N+1) FOR(y,N+1) dp[x][y]=101010;
	dp[0][1]=dif[1][0][1];
	dp[1][0]=dif[0][0][1];
	int mi=1<<20;
	if(N==1) mi=min(dp[0][1],dp[1][0]);
	FOR(x,N+1) FOR(y,N+1) if(x!=y) {
		int nex=max(x,y)+1;
		dp[x][nex]=min(dp[x][nex],dp[x][y]+dif[1][y][nex]);
		dp[nex][y]=min(dp[nex][y],dp[x][y]+dif[0][x][nex]);
		if(nex==N) mi=min({mi,dp[x][nex],dp[nex][y]});
	}
	cout<<(M[0]+M[1]-2)-mi<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}