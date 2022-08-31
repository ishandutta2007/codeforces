#include<cstdio>
#include<algorithm>
#include<cassert>
#include<cstring>
#include<iostream>
#include<cstdlib>
#include<cmath>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<bitset>
using namespace std;
typedef long long ll;
typedef double db;
void gn(int &x){
	int sg=1;char c;while(((c=getchar())<'0'||c>'9')&&c!='-');
	if(c=='-')sg=-1,x=0;else x=c-'0';
	while((c=getchar())>='0'&&c<='9')x=x*10+c-'0';
	x*=sg;
}
void gn(ll &x){
	int sg=1;char c;while(((c=getchar())<'0'||c>'9')&&c!='-');
	if(c=='-')sg=-1,x=0;else x=c-'0';
	while((c=getchar())>='0'&&c<='9')x=x*10+c-'0';
	x*=sg;
}
int qp(int a,ll b,int mo){int ans=1;do{if(b&1)ans=1ll*ans*a%mo;a=1ll*a*a%mo;}while(b>>=1);return ans;}
int gcd(int a,int b){return b?gcd(b,a%b):a;}
const int mo=1000000007;

int g[100005];
int qu[100005];
struct edge{
	int v,next;
}e[200005];int etot=0;
void ae(int u,int v){
	e[etot].v=v;e[etot].next=g[u];g[u]=etot++;
}
struct node{
	int a[11];int tot;
}a[100005],up[100005][20];


node operator+(const node&a,const node&b){
	int i=0,j=0;
	int nc=0;
	node c;
	while(i!=a.tot || j!=b.tot){
		if(i==a.tot || (j!=b.tot && b.a[j+1]<a.a[i+1]))c.a[++nc]=b.a[++j];
		else c.a[++nc]=a.a[++i];
		if(nc==10)break;
	}
	c.tot=nc;
	return c;
}
int pre[100005][20]={0};int h[100005];
int n,m,q;
void bfs(){
	int p=0,q=0;
	p=q=0;
	qu[q++]=1;pre[1][0]=0;
	while(p!=q){
		int u=qu[p++];
		for (int i=g[u];~i;i=e[i].next)if(pre[u][0]!=e[i].v){
			pre[qu[q++]=e[i].v][0]=u;
			h[e[i].v]=h[u]+1;
		}
	}
	for (int i=1;i<=n;i++)up[i][0]=a[i];
	for (int i=1;i<=19;i++)
		for (int u=1;u<=n;u++){
			pre[u][i]=pre[pre[u][i-1]][i-1];
			up[u][i]=up[u][i-1]+up[pre[u][i-1]][i-1];
		}
}

node get(int u,int v){
	node ans;
	ans.tot=0;
	if(h[u]<h[v])swap(u,v);
	for (int i=0;h[u]-h[v];i++)if(h[u]-h[v]&1<<i){
		ans=ans+up[u][i];
		u=pre[u][i];
	}
	if(u==v)return ans+a[u];

	for (int i=19;i>=0;i--)if(pre[u][i]!=pre[v][i]){
		ans=ans+up[u][i];
		u=pre[u][i];
		ans=ans+up[v][i];
		v=pre[v][i];
	}
	ans=ans+a[u];
	ans=ans+a[v];
	ans=ans+a[pre[u][0]];
	return ans;
}

int main()
{
	memset(g,-1,sizeof(g));
	gn(n);gn(m);gn(q);
	for (int i=1;i<n;i++){
		int x,y;gn(x);gn(y);
		ae(x,y);
		ae(y,x);
	}
	for (int i=1;i<=m;i++){
		int x;gn(x);
		if(a[x].tot<10)a[x].a[++a[x].tot]=i;
	}
	bfs();
	while(q--){
		int u,v,a;
		gn(u);gn(v);gn(a);
		node t=get(u,v);

		int k=min(a,t.tot);
		printf("%d",k);
		for (int i=1;i<=k;i++)printf(" %d",t.a[i]);
		printf("\n");
	}
	return 0;
}