#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=1e5+5;
int n;
struct Edge{int to,nxt;}e[2*maxn];
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
int X=0,Y=0,lf,leaf;
int siz[maxn],f[maxn];
void dfs(int x,int fa){
	siz[x]=1;f[x]=fa;
	bool flag=0;
	for(int i=head[x];i!=-1;i=e[i].nxt){
		int tmp=e[i].to;
		if(tmp==fa)continue;
		dfs(tmp,x);
		siz[x]+=siz[tmp];
		if(siz[tmp]>n-siz[tmp])flag=1;
	}
	if(siz[x]==1)leaf=x;
	if(n-siz[x]<=siz[x]&&!flag){
		if(X)Y=x;
		else X=x,lf=leaf;
	}
	return ;
}
int main(){
	int T;
	T=read();
	while(T--){
		n=read();
		cnt=0;for(int i=1;i<=n;i++)head[i]=-1;
		for(int i=1;i<n;i++){
			int u,v;
			u=read();v=read();
			add(u,v),add(v,u);
		}
		X=0,Y=0;dfs(1,0);
//		cerr<<"*"<<X<<" "<<Y<<endl;
		if(!Y)printf("%d %d\n%d %d\n",e[0].to,e[1].to,e[0].to,e[1].to);
		else printf("%d %d\n%d %d\n",lf,f[lf],lf,Y);
	}
    return 0;
}