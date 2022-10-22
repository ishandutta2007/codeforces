#include<bits/stdc++.h>
using namespace std;
const int INF=0x3f3f3f3f;
const int Mod=998244353;
int n,m,dis[410][410];
vector<int> vec[410];
int calc(int x,int y){
	int tot=0,res=1;
	for (int u=1;u<=n;u++)
		if (dis[x][u]+dis[u][y]==dis[x][y]) tot++;
		else{
			int tmp=0;
			for (int v:vec[u])
				if (dis[x][v]+1==dis[x][u]&&dis[y][v]+1==dis[y][u]) tmp++;
			res=1ll*res*tmp%Mod;
		}
	if (tot!=dis[x][y]+1) return 0;
	return res;
}
int main(){
	scanf("%d%d",&n,&m); int u,v;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
			dis[i][j]=(i==j?0:INF);
	for (int i=1;i<=m;i++){
		scanf("%d%d",&u,&v);
		vec[u].push_back(v);
		vec[v].push_back(u);
		dis[u][v]=1; dis[v][u]=1;
	}
	for (int k=1;k<=n;k++)
		for (int i=1;i<=n;i++)
			for (int j=1;j<=n;j++)
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
	for (int i=1;i<=n;i++){
		for (int j=1;j<=n;j++)
			printf("%d ",calc(i,j));
		putchar('\n');
	}
	return 0;
}