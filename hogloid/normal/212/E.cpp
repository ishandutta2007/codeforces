#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<vector>
#include<set>
#define REP(i,m) for(int i=0;i<m;++i)
#define REPN(i,m,in) for(int i=in;i<m;++i)
#define ALL(t) (t).begin(),(t).end()
#define pb push_back
#define mp make_pair
#define fr first
#define sc second
#define dump(x)  cerr << #x << " = " << (x) << endl
#define prl cerr<<"called:"<< __LINE__<<endl
using namespace std;
static const int INF =500000000; 
template<class T> void debug(T a,T b){ for(;a!=b;++a) cerr<<*a<<' ';cerr<<endl;}
typedef long long int lint;
typedef pair<int,int> pi;
int n;
vector<int> g[5005];
int able[5005];
int size[5005];
void dfs(int v,int p){
	size[v]=1;
	REP(i,g[v].size()){
		int to=g[v][i];
		if(to==p) continue;
		dfs(to,v);
		size[v]+=size[to];
	}
}
int dp[5005];
int main(){
	scanf("%d",&n);
	REP(i,n-1){
		int a,b;scanf("%d%d",&a,&b);--a;--b;
		g[a].pb(b);g[b].pb(a);
	}
	REP(i,n){
		dfs(i,-1);
		memset(dp,0,sizeof(dp));
		dp[0]=1;
		REP(j,g[i].size()){
			int to=g[i][j];
			for(int k=n;k>=0;--k) if(dp[k]){
				dp[k+size[to]]=1;
			}
		}
		REPN(i,n-1,1) if(dp[i]) able[i]=1;
	}
	printf("%d\n",(int)count(able,able+n,1));
	REP(i,n) if(able[i]){
		printf("%d %d\n",i,n-i-1);
	}
	return 0;
}