#include <cstdio>
#include <cstring>
void read(int &a){
	a=0;
	char c=getchar();
	while((c<'0'||c>'9')&&c!='-'){
		c=getchar();
	}
	int f=1;
	if(c=='-'){
		f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		a=(a<<1)+(a<<3)+(c^48);
		c=getchar();
	}
	if(f==-1){
		a=-a;
	}
}
const int Maxn=300000;
int head[Maxn+5],arrive[Maxn<<1|5],nxt[Maxn<<1|5],tot;
void add_edge(int from,int to){
	arrive[++tot]=to;
	nxt[tot]=head[from];
	head[from]=tot;
}
bool chos[Maxn<<1|5];
int d[Maxn+5];
int n,m;
bool vis[Maxn+5];
int ans=0;
int dfs(int u){
	vis[u]=1;
	for(int i=head[u];i;i=nxt[i]){
		int v=arrive[i];
		if(vis[v]){
			continue;
		}
		if(dfs(v)==1){
			chos[i]=1;
			ans++;
			if(d[u]!=-1){
				d[u]^=1;
			}
		}
	}
	return d[u];
}
int main(){
	read(n),read(m);
	int u,v;
	int root=0;
	for(int i=1;i<=n;i++){
		read(d[i]);
		if(d[i]==-1){
			root=i;
		}
	}
	for(int i=1;i<=m;i++){
		read(u),read(v);
		add_edge(u,v);
		add_edge(v,u);
	}
	if(root==0){
		if(dfs(1)==1){
			puts("-1");
			return 0;
		}
	}
	else{
		dfs(root);
	}
	printf("%d\n",ans);
	for(int i=1;i<=tot;i+=2){
		if(chos[i]||chos[i+1]){
			printf("%d ",((i+1)>>1));
		}
	}
	puts("");
	return 0;
}