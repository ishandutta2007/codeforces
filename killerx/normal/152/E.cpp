#include<bits/stdc++.h>
#define pii pair<int,int>
#define MP make_pair
#define F first
#define S second
#define ll long long
using namespace std;
const int inf=0x3f3f3f3f;
int n,m,k,mx[7],my[7];
int cst[105][105];
int dp[205][1<<7];
pii prvv[205][1<<7];
int dis[205][205];
int prv[205][205];
int id[105][105];
int g[205][205];
char anss[105][105];
const int dx[]={0,0,-1,1},dy[]={-1,1,0,0};
void dij(int s){
	memset(dis[s],0x3f,sizeof dis[s]);
	priority_queue<pii,vector<pii>,greater<pii> >pq;
	pq.push(MP(cst[s/m][s%m],s));dis[s][s]=cst[s/m][s%m];
	while(!pq.empty()){
		pii p=pq.top();pq.pop();
		int u=p.S,d=p.F;
		if(d!=dis[s][u])continue;
		for(int v=0;v<n*m;++v){
			int w=g[u][v];
			if(dis[s][v]>d+w){
				dis[s][v]=d+w;
				prv[s][v]=u;
				pq.push(MP(dis[s][v],v));
			}
		}
	}
}
void paintpath(int x,int y){
	while(y!=x){
		anss[y/m][y%m]='X';
		y=prv[x][y];
	}
	anss[x/m][x%m]='X';
}
void paint(int p,int msk){
	if(__builtin_popcount(msk)==1){
		int i=__builtin_ctz(msk);
		paintpath(p,id[mx[i]][my[i]]);
		return;
	}
	int p0=p,msk0=prvv[p][msk].F,p1=prvv[p][msk].S,msk1=msk^msk0;
	paint(p0,msk0);paint(p1,msk1);paintpath(p0,p1);
}
int main(){
	scanf("%d%d%d",&n,&m,&k);
	for(int i=0;i<n;++i)for(int j=0;j<m;++j)scanf("%d",&cst[i][j]);
	for(int i=0;i<k;++i)scanf("%d%d",&mx[i],&my[i]),--mx[i],--my[i];
	for(int i=0;i<n;++i)for(int j=0;j<m;++j)id[i][j]=i*m+j;
	memset(g,0x3f,sizeof g);
	for(int i=0;i<n;++i)for(int j=0;j<m;++j){
		for(int d=0;d<4;++d){
			int ni=i+dx[d],nj=j+dy[d];
			if(ni<0||nj<0||ni>=n||nj>=m)continue;
			g[id[i][j]][id[ni][nj]]=cst[ni][nj];
		}
	}
	for(int i=0;i<n*m;++i)dij(i);
	memset(dp,0x3f,sizeof dp);
	for(int i=0;i<k;++i)for(int j=0;j<n*m;++j)
		dp[j][1<<i]=dis[id[mx[i]][my[i]]][j];
	for(int msk=0;msk<(1<<k);++msk){
		if(__builtin_popcount(msk)<=1)continue;
		for(int p0=0;p0<n*m;++p0){
			for(int msk0=msk&(msk-1);msk0;msk0=msk&(msk0-1))if(dp[p0][msk0]<inf){
				int msk1=msk^msk0;
				for(int p1=0;p1<n*m;++p1)if(dp[p1][msk1]<inf){
					ll nw=dp[p0][msk0]+dp[p1][msk1]+dis[p0][p1]-cst[p0/m][p0%m]-cst[p1/m][p1%m];
					if(nw<dp[p0][msk]){
						dp[p0][msk]=nw;
						prvv[p0][msk]=MP(msk0,p1);
					}
				}
			}
		}
	}
	int ans=inf,ansi=-1;
	for(int i=0;i<n*m;++i){
		if(dp[i][(1<<k)-1]<ans){
			ans=dp[i][(1<<k)-1];
			ansi=i;
		}
	}
	printf("%d\n",ans);
	for(int i=0;i<n;++i)for(int j=0;j<m;++j)anss[i][j]='.';
	paint(ansi,(1<<k)-1);
	for(int i=0;i<n;++i)for(int j=0;j<m;++j){
		putchar(anss[i][j]);
		if(j+1==m)putchar('\n');
	}
	return 0;
}