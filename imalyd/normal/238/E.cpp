#include<bits/stdc++.h>
using namespace std;
const int N=105,inf=1e9;
int n,d[N][N],c,m,s[N],t[N],v[N],g[N][N],p[N],q[N],e[N][N];
int dfs(int a,int k){
	if(v[a]==c)return q[a];
	v[a]=c,q[a]=-1;
	for(int i=1;i<=n;i++)if(d[a][i]==1&&d[a][t[k]]==d[i][t[k]]+1)q[a]=max(q[a],dfs(i,k));
	if(!(~q[a]))q[a]=inf;
		//printf("dfs(%d,%d)=%d\n",a,k,min(q[a],p[a]));
	return q[a]=min(q[a],p[a]);
}
int main(){
	//freopen("input.txt","r",stdin);
	scanf("%d%d%d%d",&n,&m,&s[0],&t[0]);
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)d[i][j]=inf;
	for(int i=1;i<=n;i++)d[i][i]=0;	
	while(m--){
		int a,b;
		scanf("%d%d",&a,&b);
		d[a][b]=1;
	}
	for(int k=1;k<=n;k++)for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
	scanf("%d",&m);
	for(int i=1;i<=m;i++){
		scanf("%d%d",&s[i],&t[i]);
		for(int j=1;j<=n;j++)if(d[s[i]][t[i]]==d[s[i]][j]+d[j][t[i]]&&d[s[i]][j]!=inf)g[i][d[s[i]][j]]++;
		for(int j=1;j<=n;j++)if(d[s[i]][t[i]]==d[s[i]][j]+d[j][t[i]]&&d[s[i]][j]!=inf&&g[i][d[s[i]][j]]==1)e[i][j]=1;
	}
	for(int i=1;i<=n;i++)p[i]=q[i]=inf;p[t[0]]=0;
	int f=1;
	while(f){
		f=0;
		for(int i=1;i<=m;i++){
			if(d[s[i]][t[i]]==inf)continue;
			for(int j=1;j<=n;j++)if(e[i][j]){
				c++;
				int tmp=dfs(j,i)+1;
				if(tmp<p[j])f=1,p[j]=tmp;
				//printf("----------c=%d i=%d j=%d p[j]=%d----------\n",c,i,j,p[j]);
			}
		}
	}
	if(p[s[0]]==inf)p[s[0]]=-1;
	printf("%d",p[s[0]]);
	return 0;
}