#include <cstdio>
#include <cstring>
#define int long long

int t,n,m,a[3001],head[3001],nxt[6001],b[6001],k,f[3001][3001][2],size[3001],tem[3001][2];
void push(int s,int t){
	nxt[++k]=head[s];
	head[s]=k;
	b[k]=t;
}
void dfs(int x,int F){
	size[x]=1;
	for(int i=0;i<=n;i++)f[x][i][0]=0,f[x][i][1]=-1000000000000000ll;
	f[x][0][0]=0;
	f[x][0][1]=a[x];
	for(int i=head[x];i;i=nxt[i])
		if(b[i]!=F){
			dfs(b[i],x);
			for(int a=0;a<size[x]+size[b[i]];a++)tem[a][0]=0,tem[a][1]=-1000000000000000ll;
			for(int a=0;a<size[x];a++)
				for(int j=0;j<=size[b[i]];j++)
					if(tem[a+j][0]<f[x][a][0]+f[b[i]][j][0]||(tem[a+j][0]==f[x][a][0]+f[b[i]][j][0]&&tem[a+j][1]<f[x][a][1]+f[b[i]][j][1])){
						tem[a+j][0]=f[x][a][0]+f[b[i]][j][0];
						tem[a+j][1]=f[x][a][1]+f[b[i]][j][1];
					}
			for(int a=0;a<size[x]+size[b[i]];a++)f[x][a][0]=tem[a][0],f[x][a][1]=tem[a][1];
			size[x]+=size[b[i]];
		}
	for(int i=size[x];i;i--){
		if(f[x][i][0]<(f[x][i-1][0]+(f[x][i-1][1]>0))||(f[x][i][0]==(f[x][i-1][0]+(f[x][i-1][1]>0))&&f[x][i][1]<0))
			f[x][i][0]=f[x][i-1][0]+(f[x][i-1][1]>0),f[x][i][1]=0;
	}
}
signed main(){
	scanf("%I64d",&t);
	for(int fd=1;fd<=t;fd++){
		scanf("%I64d%I64d",&n,&m);
		for(int i=1;i<=n;i++)scanf("%I64d",a+i);
		for(int i=1,tem;i<=n;i++)scanf("%I64d",&tem),a[i]=tem-a[i];
		memset(head,0,sizeof head);
		k=0;
		for(int i=1,u,v;i<n;i++){
			scanf("%I64d%I64d",&u,&v);
			push(u,v);
			push(v,u);
		}
		dfs(1,0);
		printf("%I64d\n",f[1][m-1][0]+(f[1][m-1][1]>0));
	}
}