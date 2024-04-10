#include <cstdio>
#include <cstring>
#include <algorithm>
const int Maxn=600;
const int Inf=0x3f3f3f3f;
int dis[Maxn+5];
bool vis[Maxn+5];
int n,m;
int g[Maxn+5][Maxn+5];
int val[Maxn+5];
void solve_val(int u,int t){
	static int f[Maxn<<1|5];
	for(int i=0;i<=(n<<1);i++){
		f[i]=Inf;
	}
	for(int i=0;i<n;i++){
		if(g[u][i]==-1){
			continue;
		}
		f[(i+t)%n]=std::min(f[(i+t)%n],g[u][i]);
	}
	for(int i=1;i<=(n<<1);i++){
		f[i]=std::min(f[i],f[i-1]+1);
	}
	for(int i=0;i<n;i++){
		val[i]=std::min(f[i],f[i+n]);
	}
}
void solve_dis(int u){
	memset(dis,0x3f,sizeof dis);
	memset(vis,0,sizeof vis);
	dis[u]=0;
	for(int t=0;t<n;t++){
		u=-1;
		for(int i=0;i<n;i++){
			if(vis[i]){
				continue;
			}
			if(u==-1||dis[i]<dis[u]){
				u=i;
			}
		}
		if(u==-1||dis[u]==Inf){
			break;
		}
		vis[u]=1;
		solve_val(u,dis[u]%n);
		for(int v=0;v<n;v++){
			if(dis[u]+val[v]<dis[v]){
				dis[v]=dis[u]+val[v];
			}
		}
	}
}
int main(){
	scanf("%d%d",&n,&m);
	memset(g,-1,sizeof g);
	for(int i=1;i<=m;i++){
		int u,v,c;
		scanf("%d%d%d",&u,&v,&c);
		g[u][v]=c;
	}
	for(int i=0;i<n;i++){
		solve_dis(i);
		for(int j=0;j<n;j++){
			printf("%d ",dis[j]);
		}
		puts("");
	}
	return 0;
}