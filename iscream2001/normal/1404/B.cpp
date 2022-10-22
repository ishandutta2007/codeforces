#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int N=3e5+10;
const int inf=1e9;
int read(){
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
void print(LL x){
    if(x>9) print(x/10);
    putchar(x%10+'0');
}
int n,a,b,da,db,K,cnt=1;
int hed[N];
struct edge{
	int r,nxt;
}e[N<<1];
void insert(int u,int v){
	e[++cnt].r=v;e[cnt].nxt=hed[u];hed[u]=cnt;
}
int dis[N];
bool vis[N];
int q[N];
int main(){
	int T;scanf("%d",&T);
	int u,v,l,r;
	while(T--){
		scanf("%d%d%d%d%d",&n,&a,&b,&da,&db);cnt=1;
		for(int i=1;i<=n;++i) hed[i]=0;
		for(int i=1;i<n;++i){
			scanf("%d%d",&u,&v);
			insert(u,v);
			insert(v,u);
		}
		for(int i=1;i<=n;++i) {
			dis[i]=0;vis[i]=0;
		}
		l=1,r=1;
		q[1]=a;dis[a]=0;vis[a]=1;
		while(l<=r){
			u=q[l];++l;
			for(int i=hed[u];i;i=e[i].nxt)
				if(!vis[e[i].r]){
					dis[e[i].r]=dis[u]+1;
					vis[e[i].r]=1;
					q[++r]=e[i].r;
				}
		}
		if(dis[b]<=da||db<da+da+1){
			puts("Alice");continue;
		}
		u=1;
		for(int i=1;i<=n;++i) if(dis[i]>dis[u]) u=i;
		for(int i=1;i<=n;++i) {
			dis[i]=0;vis[i]=0;
		}
		l=1,r=1;
		q[1]=u;dis[u]=0;vis[u]=1;
		while(l<=r){
			u=q[l];++l;
			for(int i=hed[u];i;i=e[i].nxt)
				if(!vis[e[i].r]){
					dis[e[i].r]=dis[u]+1;
					vis[e[i].r]=1;
					q[++r]=e[i].r;
				}
		}
		u=1;
		for(int i=1;i<=n;++i) if(dis[i]>dis[u]) u=i;
		if(dis[u]<=da+da) {
			puts("Alice");continue;
		}
		puts("Bob");
	}
	return 0;
}