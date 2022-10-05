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

int N,M;
const ll mo=998244353;
vector<int> V[400];
ll dp[400][400];
int D[400],vis[404];;
int S[404][404];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(y,N) FOR(x,N) S[y][x]=(y==x)?0:500;
	FOR(i,M) {
		cin>>x>>y;
		V[x-1].push_back(y-1);
		V[y-1].push_back(x-1);
		S[x-1][y-1]=S[y-1][x-1]=1;
	}
	FOR(k,N) FOR(x,N) FOR(y,N) S[x][y]=min(S[x][y],S[x][k]+S[k][y]);
	
	FOR(y,N) FOR(x,y+1) {
		ll ret=1;
		FOR(i,N) if(S[x][i]+S[i][y]==S[x][y]) D[S[x][i]]=i;
		ZERO(vis);
		FOR(i,S[x][y]+1) vis[D[i]]=1;
		FOR(i,N) if(vis[i]==0) {
			int pat=0;
			FORR(e,V[i]) if(S[e][x]==S[i][x]-1&&S[e][y]==S[i][y]-1) pat++;
			ret=ret*pat%mo;
		}
		
		dp[y][x]=dp[x][y]=ret;
	}
	
	FOR(y,N) {
		FOR(x,N) cout<<dp[y][x]<<" ";
		cout<<endl;
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}