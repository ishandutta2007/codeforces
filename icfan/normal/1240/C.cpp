#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
#define Maxn 500000
#define ll long long
template<typename Elem>
void read(Elem &a){
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
int n,k;
int head[Maxn+5],arrive[Maxn<<1|5],nxt[Maxn<<1|5],val[Maxn<<1|5],tot;
void add_edge(int from,int to,int v){
	arrive[++tot]=to;
	nxt[tot]=head[from];
	val[tot]=v;
	head[from]=tot;
}
ll f[Maxn+5][2];
bool vis[Maxn+5];
ll a[Maxn+5];
int len;
bool cmp(int p,int q){
	return p>q;
}
void init(){
	for(int i=1;i<=n;i++){
		f[i][0]=f[i][1]=-1;
		head[i]=0;
		vis[i]=0;
	}
	tot=0;
}
void dfs(int u,int fa){
	for(int i=head[u];i;i=nxt[i]){
		if(arrive[i]==fa){
			continue;
		}
		dfs(arrive[i],u);
	}
	len=0;
	ll sum=0;
	for(int i=head[u];i;i=nxt[i]){
		int v=arrive[i];
		if(v==fa){
			continue;
		}
		sum+=f[v][0];
		a[++len]=f[v][1]+val[i]-f[v][0];
	}
	sort(a+1,a+1+len,cmp);
	/*printf("%d\n",u);
	for(int i=1;i<=len;i++){
		cout<<a[i]<<' ';
	}
	puts("");
	puts("");*/
	for(int i=1;i<k&&i<=len;i++){
		if(a[i]<=0){
			break;
		}
		sum+=a[i];
	}
	f[u][1]=sum;
	if(k<=len&&a[k]>0){
		sum+=a[k];
	}
	f[u][0]=sum;
}
int main(){
	int t;
	read(t);
	int u,v,w;
	while(t--){
		read(n),read(k);
		init();
		for(int i=1;i<n;i++){
			read(u),read(v),read(w);
			add_edge(u,v,w);
			add_edge(v,u,w);
		}
		dfs(1,0);
		cout<<f[1][0]<<endl;
	}
	return 0;
}