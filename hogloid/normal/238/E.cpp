#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<vector>
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
int n,m,a,b,k;
int g[105][105];
int g2[105][105][105];
pi bus[105];
int fastest[105];
int need[105][105];
int cost[105][105];
int done[105][105];
void renew(int p,int b){
	if(need[b][p]) REP(i,k) cost[p][i]=min(cost[p][i],cost[p][b]+1);
	REP(i,n) if(g[i][p]==1 && g[bus[b].fr][i]+1+g[p][bus[b].sc]==fastest[b]){
		int tmp=-1;
		REP(j,n) if(g[i][j]==1 && g[bus[b].fr][i]+1+g[j][bus[b].sc]==fastest[b]) tmp=max(tmp,cost[j][b]);
		cost[i][b]=min(tmp,cost[i][b]);
	}
}

int main(){
	cin>>n>>m>>a>>b;--a;--b;
	REP(i,n) REP(j,n) g[i][j]=INF;
	REP(i,n) g[i][i]=0;

	REP(i,n) REP(j,n) REP(k,n) g2[i][j][k]=INF;
	REP(i,n) REP(j,n) g2[i][j][j]=0;
	REP(i,m){
		int u,v;cin>>u>>v;--u;--v;
		g[u][v]=1;
		REP(j,n) if(j!=u && j!=v) g2[j][u][v]=1;
	}
	REP(i,n) REP(j,n) REP(k,n) g[j][k]=min(g[j][k],g[j][i]+g[i][k]);
	REP(l,n) REP(i,n) REP(j,n) REP(k,n) g2[l][j][k]=min(g2[l][j][k],g2[l][j][i]+g2[l][i][k]);
	cin>>k;
	REP(i,k){
		cin>>bus[i].fr>>bus[i].sc;--bus[i].fr;--bus[i].sc;
		fastest[i]=g[bus[i].fr][bus[i].sc];
		REP(j,n) if(g2[j][bus[i].fr][bus[i].sc]!=fastest[i]) need[i][j]=1;
	}
	REP(i,n) REP(j,k) cost[i][j]=INF;
	REP(i,k) if(fastest[i]==g[bus[i].fr][b]+g[b][bus[i].sc]){
		cost[b][i]=0;
		renew(b,i);
		done[b][i]=1;
	}
	while(1){
		int mini=INF;
		pi who;
		REP(i,n) REP(j,k) if(fastest[j]==g[bus[j].fr][i]+g[i][bus[j].sc] && !done[i][j] && mini>cost[i][j]){
			mini=cost[i][j];
			who=mp(i,j);
		}
		if(mini>=INF) break;
		renew(who.fr,who.sc);
		done[who.fr][who.sc]=1;
	}
	int res=INF;
	REP(i,k) if(need[i][a]) res=min(res,cost[a][i]);
	if(res>=INF) res=-2;
	printf("%d\n",res+1);
	return 0;
}