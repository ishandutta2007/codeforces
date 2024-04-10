#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
template<class T> bool chmax(T &a, const T &b) { if(a<b){a=b;return 1;}return 0;}
template<class T> bool chmin(T &a, const T &b) { if(a>b){a=b;return 1;}return 0;}
//-------------------------------------------------------

int N,M,Q;
int U[404040],V[404040],W[404040];
vector<pair<int,int>> E[404040];
ll dp[606][606];
ll S[606][606];
ll C[606][606];
ll D[660];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(x,N) FOR(y,N) S[x][y]=dp[x][y]=(x==y)?0:1LL<<60;
	FOR(x,N) S[x][x]=1LL<<60;
	FOR(i,M) {
		cin>>U[i]>>V[i]>>W[i];
		U[i]--,V[i]--;
		dp[U[i]][V[i]]=dp[V[i]][U[i]]=W[i];
		S[U[i]][V[i]]=S[V[i]][U[i]]=W[i];
	}
	FOR(k,N) FOR(x,N) FOR(y,N) dp[x][y]=min(dp[x][y],dp[x][k]+dp[k][y]);
	
	FOR(x,N) FOR(y,N) C[x][y]=-1;
	cin>>Q;
	FOR(i,Q) {
		cin>>x>>y>>k;
		C[x-1][y-1]=C[y-1][x-1]=k;
	}
	
	int num=0;
	FOR(i,N) FOR(y,N) {
		ll ma=-1;
		FOR(j,N) ma=max(ma,C[i][j]-dp[y][j]);
		FOR(x,N) if(S[x][y]+dp[i][x]<=ma) {
			num++;
			S[x][y]=S[y][x]=1LL<<60;
		}
	}
	
	cout<<num<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}