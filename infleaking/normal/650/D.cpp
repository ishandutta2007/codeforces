#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#define low(x) (x&(-x))
using namespace std;
const int N=1e6+10;
struct nod{int x,fr;}d[N];
int n,m;
int a[N],cnt[N],f[N],g[N];
int tr[N];
void cmax(int &x,int y){x=x>y?x:y;}
void add(int x,int v){for (;x<=n+m;x+=low(x))cmax(tr[x],v);}
void query(int x,int &ans){ans=0;for (;x;x-=low(x))cmax(ans,tr[x]);}
int w[N],ne[N],la[N],t;
void link(int x,int y){
	w[++t]=y;
	ne[t]=la[x];
	la[x]=t;
}
int Q[N],gx,pre[N],suf[N],ans[N],lng;
bool comp(nod a,nod b){return a.x<b.x;}
int main(){
	cin>>n>>m;
	for (int i=1;i<=n;i++)scanf("%d",&a[i]);
	for (int i=1;i<=m;i++){
		scanf("%d%d",&gx,&Q[i]);
		link(gx,i);
	}t=0;
	for (int i=1;i<=n;i++)d[++t]=(nod){a[i],i};
	for (int i=1;i<=m;i++)d[++t]=(nod){Q[i],n+i};
	sort(d+1,d+t+1,comp);t=0;
	for (int i=1;i<=n+m;i++){
		if (i==1||d[i].x!=d[i-1].x)t++;
		if (d[i].fr>n)Q[d[i].fr-n]=t;
		else a[d[i].fr]=t;
	}
	for (int x=1;x<=n;x++){
		query(a[x]-1,f[x]);
		for (int y=la[x];y;y=ne[y])query(Q[w[y]]-1,pre[w[y]]);
		add(a[x],f[x]+1);
		lng=max(lng,f[x]);
	}
	memset(tr,0,sizeof tr);
	for (int i=1;i<=n;i++)a[i]=t-a[i]+1;
	for (int i=1;i<=m;i++)Q[i]=t-Q[i]+1;
	for (int x=n;x>=1;x--){
		query(a[x]-1,g[x]);
		for (int y=la[x];y;y=ne[y])query(Q[w[y]]-1,suf[w[y]]);
		add(a[x],g[x]+1);
		if (f[x]+g[x]==lng)cnt[f[x]]++;
	}
	for (int x=1;x<=n;x++){
		if (f[x]+g[x]==lng&&cnt[f[x]]==1)
			for (int y=la[x];y;y=ne[y])ans[w[y]]=-1;
	}
	for (int i=1;i<=m;i++)printf("%d\n",max(ans[i]+lng+1,pre[i]+suf[i]+1));
}