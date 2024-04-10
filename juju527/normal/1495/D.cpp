#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=405,maxm=605,mod=998244353;
int n,m;
struct Edge{int to,nxt;}e[2*maxm];
int cnt;
int head[maxn];
int read(){
    int x=0,y=1;
    char ch=getchar();
    while(ch<48||ch>57){if(ch==45)y=-1;ch=getchar();}
    while(ch>=48&&ch<=57)x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
    return x*y;
}
void add(int u,int v){
	e[cnt]=(Edge){v,head[u]};
	head[u]=cnt++;
	return ;
}
int d[maxn];
queue<int> q;
int dis[maxn][maxn];
bool num[maxn][maxn];
void bfs(int s){
	memset(d,0x3f,sizeof(d));
	q.push(s);d[s]=0;num[s][s]=0;
	while(q.size()){
		int k=q.front();
		q.pop();
		for(int i=head[k];i!=-1;i=e[i].nxt){
			int tmp=e[i].to;
			if(d[tmp]<d[k]+1)continue;
			if(d[tmp]==d[k]+1)num[s][tmp]=1;
			else num[s][tmp]=num[s][k];
			d[tmp]=d[k]+1;
			q.push(tmp);
		}
	}
	for(int i=1;i<=n;i++)dis[s][i]=d[i];
	return ;
}
int rd[maxn];
int main(){
	n=read();m=read();
	memset(head,-1,sizeof(head));
	for(int i=1;i<=m;i++){
		int u,v;
		u=read();v=read();
		add(u,v),add(v,u);
	}
	for(int i=1;i<=n;i++)bfs(i);
    for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(num[i][j]){printf("0 ");continue;}
			for(int k=1;k<=n;k++)rd[k]=0;
			for(int k=1;k<=n;k++){
				for(int l=head[k];l!=-1;l=e[l].nxt){
					int tmp=e[l].to;
					if(dis[i][k]-dis[i][tmp]==1&&dis[j][k]-dis[j][tmp]==1)rd[k]++;
				}
			}
			int res=1;
			for(int k=1;k<=n;k++){
				if(k==i||dis[i][k]+dis[j][k]==dis[i][j])continue;
				res=1ll*res*rd[k]%mod;
			}
			printf("%d ",res);
		}
		puts("");
	}
	return 0;
}