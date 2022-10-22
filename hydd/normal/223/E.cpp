#include<cstdio>
#include<map>
#include<utility>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
int n,m,q,k,a[110000],cnt,tmp[110000];
int edgenum=1,vet[610000],val[610000],Next[610000],Head[110000];
double ang[610000]; bool vis[110000];
map<pii,int> rnk;
vector<ll> sum[110000];
struct node{
	int x,y;
	node(){}
	node(int _x,int _y):x(_x),y(_y){}
} p[110000];
node operator-(const node &a,const node &b){ return node(a.x-b.x,a.y-b.y);}
char Getchar(){
	static char now[1<<20],*S,*T;
	if (T==S){
		T=(S=now)+fread(now,1,1<<20,stdin);
		if (T==S) return EOF;
	}
	return *S++;
}
int read(){
	int x=0,f=1;
	char ch=Getchar();
	while (ch<'0'||ch>'9'){
		if (ch=='-') f=-1;
		ch=Getchar();
	}
	while (ch<='9'&&ch>='0') x=x*10+ch-'0',ch=Getchar();
	return x*f;
}
void addedge(int u,int v){
    vet[++edgenum]=v;
    Next[edgenum]=Head[u];
	Head[u]=edgenum;
}
int dfs(int u){
	vis[u]=true;
	int flow=1,tmp;
	for (int e=Head[u];e;e=Next[e])
		if (!vis[vet[e]]){
			tmp=dfs(vet[e]);
			val[e]+=tmp; val[e^1]-=tmp;
			flow+=tmp;
		}
	return flow;
}
inline bool cmp(int a,int b){ return ang[a]<ang[b];}
inline ll cross(node x,node y){ return 1ll*x.x*y.y-1ll*x.y*y.x;}
int main(){
	n=read(); m=read(); int u,v;
	for (int i=1;i<=m;i++){
		u=read(); v=read();
		addedge(u,v); addedge(v,u);
	}
	for (int i=1;i<=n;i++) p[i].x=read(),p[i].y=read();
	int rt=1;
	for (int i=2;i<=n;i++)
		if (p[i].x<p[rt].x) rt=i;
	addedge(n+1,rt);
	dfs(n+1);
	for (int u=1;u<=n;u++){
		cnt=0;
		for (int e=Head[u];e;e=Next[e]){
			tmp[++cnt]=e; v=vet[e];
			ang[e]=atan2(p[v].y-p[u].y,p[v].x-p[u].x);
		}
		sort(tmp+1,tmp+cnt+1,cmp);
		sum[u].push_back(0);
		for (int i=1;i<=cnt;i++){
			rnk[pii(u,vet[tmp[i]])]=i;
			sum[u].push_back(sum[u].back()+val[tmp[i]]);
		}
	}
	q=read(); int l,r;
	while (q--){
		k=read();
		for (int i=1;i<=k;i++) a[i]=read();
		ll s=0,ans=k;
		for (int i=2;i<k;i++) s+=cross(p[a[i]]-p[a[1]],p[a[i+1]]-p[a[1]]);
		if (s<0) reverse(a+1,a+k+1);
		//
		a[0]=a[k]; a[k+1]=a[1];
		for (int i=1;i<=k;i++){
			l=rnk[pii(a[i],a[i+1])];
			r=rnk[pii(a[i],a[i-1])];
			ans+=sum[a[i]][r]-sum[a[i]][l-1];
			if (l>r) ans+=sum[a[i]][(int)sum[a[i]].size()-1];
		}
		printf("%lld\n",ans);
	}
	return 0;
}