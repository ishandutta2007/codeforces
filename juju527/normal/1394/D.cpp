#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=2e5+5;
const ll inf=0x3f3f3f3f3f3f3f3f;
struct Edge{int to,nxt;}e[2*maxn];
int cnt;
int head[maxn];
int a[maxn],b[maxn];
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
ll f[maxn][2];
int val[maxn];
void dfs(int x,int fa){
	int v=0,w=0,len=0;
	ll sum=0;
	for(int i=head[x];i!=-1;i=e[i].nxt){
		int tmp=e[i].to;
		if(tmp==fa)continue;
		dfs(tmp,x);
	}
	for(int i=head[x];i!=-1;i=e[i].nxt){
		int tmp=e[i].to;
		if(tmp==fa)continue;
		if(b[x]<b[tmp])w++,sum+=f[tmp][1];
		else if(b[x]>b[tmp])v++,sum+=f[tmp][0];
		else v++,sum+=f[tmp][0],val[++len]=f[tmp][1]-f[tmp][0];
	}
	sort(val+1,val+len+1);
	f[x][0]=f[x][1]=inf;
	for(int i=0;i<=len;i++){
		f[x][0]=min(f[x][0],sum+1ll*max(v,w+(x!=1))*a[x]);
		f[x][1]=min(f[x][1],sum+1ll*max(v+(x!=1),w)*a[x]);
		v--;w++;
		sum+=val[i+1];
	}
	return ;
}
int main(){
	int n;
	n=read();
	for(int i=1;i<=n;i++)a[i]=read();
	for(int i=1;i<=n;i++)b[i]=read();
	memset(head,-1,sizeof(head));
	for(int i=1;i<n;i++){
		int u,v;
		u=read();v=read();
		add(u,v),add(v,u);
	}
	dfs(1,0);
	printf("%lld\n",f[1][0]);
    return 0;
}