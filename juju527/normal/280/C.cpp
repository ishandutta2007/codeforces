#include <bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
struct Edge{
	int to,nxt;
}e[2*maxn];
int cnt;
int head[maxn];
int dep[maxn];
int read(){
    int x=0,y=1;
    char ch=getchar();
    while(ch<48||ch>57){if(ch==45)y=-1;ch=getchar();}
    while(ch>=48&&ch<=57)x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
    return x*y;
}
void add(int u,int v){
	e[cnt].to=v;
	e[cnt].nxt=head[u];
	head[u]=cnt++;
	return ;
}
void dfs(int x,int fa){
	dep[x]=dep[fa]+1;
	for(int i=head[x];i!=-1;i=e[i].nxt){
		int tmp=e[i].to;
		if(tmp==fa)continue;
		dfs(tmp,x);
	}
	return ;
}
int main(){
//    freopen("CF280C.in","r",stdin);
//    freopen("CF280C.out","w",stdout);
   	int n;
	n=read();
	memset(head,-1,sizeof(head));
	for(int i=1;i<n;i++){
		int u,v;
		u=read();v=read();
		add(u,v);
		add(v,u);
	}
	dfs(1,0);
	double ans=0;
	for(int i=1;i<=n;i++)ans+=1.0/dep[i];
	printf("%.9f",ans);
    return 0;
}