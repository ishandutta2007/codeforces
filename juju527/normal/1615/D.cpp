#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=2e5+5;
int n,m;
struct Edge{int to,w,nxt;}e[2*maxn];
int cnt;
int head[maxn];
int f[2*maxn];
int find(int x){return (f[x]==x)?x:(f[x]=find(f[x]));}
void merge(int u,int v){
	u=find(u),v=find(v);
	if(u==v)return ;
	f[u]=v;
	return ;
}
int read(){
    int x=0,y=1;
    char ch=getchar();
    while(ch<48||ch>57){if(ch==45)y=-1;ch=getchar();}
    while(ch>=48&&ch<=57)x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
    return x*y;
}
void add(int u,int v,int w){
	e[cnt]=(Edge){v,w,head[u]};
	head[u]=cnt++;
	return ;
}
void dfs(int x,int fa){
	for(int i=head[x];i!=-1;i=e[i].nxt){
		int tmp=e[i].to;
		if(tmp==fa)continue;
		int res=0;
		if(e[i].w==-1){
			if(find(x)==find(tmp+n)||find(tmp)==find(x+n))res=1,merge(x,tmp+n),merge(tmp,x+n);
			else res=0,merge(x,tmp),merge(x+n,tmp+n);
		}
		else res=e[i].w;
		printf("%d %d %d\n",x,tmp,res);
		dfs(tmp,x);
	}
	return ;
}
int main(){
	int T;
	T=read();
	while(T--){
		n=read();m=read();
		cnt=0;for(int i=1;i<=n;i++)head[i]=-1;
		for(int i=1;i<=2*n;i++)f[i]=i;
		for(int i=1;i<n;i++){
			int u,v,w;
			u=read();v=read();w=read();
			add(u,v,w),add(v,u,w);
			if(w>=0){
				if(__builtin_parity(w))merge(u,v+n),merge(v,u+n);
				else merge(u,v),merge(u+n,v+n);
			}
		}
		for(int i=1;i<=m;i++){
			int u,v,w;
			u=read();v=read();w=read();
			if(w)merge(u,v+n),merge(v,u+n);
			else merge(u,v),merge(u+n,v+n);
		}
		bool tag=0;
		for(int i=1;i<=n;i++)if(find(i)==find(i+n))tag=1;
		if(tag){puts("NO");continue;}
		puts("YES");
		dfs(1,0);
	}
    return 0;
}