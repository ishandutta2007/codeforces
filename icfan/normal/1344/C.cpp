#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;
void read(int &a){
	a=0;
	char c=getchar();
	while(c<'0'||c>'9'){
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		a=(a<<1)+(a<<3)+(c^48);
		c=getchar();
	}
}
const int Maxn=200000;
int n,m;
int u[Maxn+5],v[Maxn+5];
int a[Maxn+5];
int head[Maxn+5],arrive[Maxn+5],nxt[Maxn+5],tot;
void add_edge(int from,int to){
	arrive[++tot]=to;
	nxt[tot]=head[from];
	head[from]=tot;
}
int deg[Maxn+5];
bool vis[Maxn+5];
int que[Maxn+5],que_f,que_t;
bool check(){
	for(int i=1;i<=m;i++){
		deg[v[i]]++;
	}
	que_f=1;
	que_t=0;
	for(int i=1;i<=n;i++){
		if(deg[i]==0){
			que[++que_t]=i;
		}
		vis[i]=0;
	}
	while(que_f<=que_t){
		int u=que[que_f++];
		vis[u]=1;
		for(int i=head[u];i;i=nxt[i]){
			int v=arrive[i];
			deg[v]--;
			if(deg[v]==0){
				que[++que_t]=v;
			}
		}
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			return 0;
		}
	}
	return 1;
}
vector<int> g_a[Maxn+5],g_b[Maxn+5];
bool vis_a[Maxn+5],vis_b[Maxn+5];
void color_a(int u){
	if(vis_a[u]){
		return;
	}
	vis_a[u]=1;
	for(int i=0;i<(int)g_a[u].size();i++){
		int v=g_a[u][i];
		color_a(v);
	}
}
void color_b(int u){
	if(vis_b[u]){
		return;
	}
	vis_b[u]=1;
	for(int i=0;i<(int)g_b[u].size();i++){
		int v=g_b[u][i];
		color_b(v);
	}
}
int main(){
	read(n),read(m);
	for(int i=1;i<=m;i++){
		read(u[i]),read(v[i]);
		add_edge(u[i],v[i]);
		g_a[u[i]].push_back(v[i]);
		g_b[v[i]].push_back(u[i]);
	}
	if(!check()){
		puts("-1");
		return 0;
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		if(!vis_a[i]&&!vis_b[i]){
			a[i]=1;
			ans++;
		}
		color_a(i);
		color_b(i);
	}
	printf("%d\n",ans);
	for(int i=1;i<=n;i++){
		if(a[i]==1){
			putchar('A');
		}
		else{
			putchar('E');
		}
	}
	puts("");
	return 0;
}