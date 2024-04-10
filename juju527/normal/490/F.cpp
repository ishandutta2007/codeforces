#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
int n,w;
struct node{
	int id,data;
	bool operator <(node i)const{return data<i.data;}
}a[maxn];
struct Edge{
	int to,nxt;
}e[2*maxn];
int cnt;
int head[maxn];
int val[maxn];
int read(){
	int x=0,y=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')y=-1;ch=getchar();}
	while(ch>='0'&&ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	return x*y;
}
void add(int u,int v){
	e[cnt]=(Edge){v,head[u]};
	head[u]=cnt++;
	return ;
}
struct seg{
	int ls,rs,f,g;
}t[20*maxn];
int tot;
int rt[maxn];
int newnode(){t[++tot]=(seg){0,0,0};return tot;}
void modify(int &k,int l,int r,int x,int v,int op){
	if(!k)k=newnode();
	if(op&1)t[k].f=max(t[k].f,v);
	if(op&2)t[k].g=max(t[k].g,v);
	if(l==r)return ;
	int mid=l+((r-l)>>1);
	if(x<=mid)modify(t[k].ls,l,mid,x,v,op);
	else modify(t[k].rs,mid+1,r,x,v,op);
	return ;
}
int query(int k,int l,int r,int x,int y,int op){
	if(!k)return 0;
	if(l>y||r<x)return 0;
	if(l>=x&&r<=y)return op==1?t[k].f:t[k].g;
	int mid=l+((r-l)>>1);
	return max(query(t[k].ls,l,mid,x,y,op),query(t[k].rs,mid+1,r,x,y,op));
}
int res=0;
int merge(int x,int y,int l,int r){
	if(!x||!y){
		res=max(res,max(t[x+y].f,t[x+y].g));
		return x+y;
	}
	int mid=l+((r-l)>>1);
	res=max(res,max(t[t[x].ls].f+t[t[y].rs].g,t[t[x].rs].g+t[t[y].ls].f));
	t[x].f=max(t[x].f,t[y].f);t[x].g=max(t[x].g,t[y].g);
	t[x].ls=merge(t[x].ls,t[y].ls,l,mid);
	t[x].rs=merge(t[x].rs,t[y].rs,mid+1,r);
	return x;
}
void dfs(int x,int fa){
	modify(rt[x],1,w,val[x],1,3);
	for(int i=head[x];i!=-1;i=e[i].nxt){
		int tmp=e[i].to;
		if(tmp==fa)continue;
		dfs(tmp,x);
		int v1=query(rt[tmp],1,w,1,val[x]-1,1);
		int v2=query(rt[tmp],1,w,val[x]+1,w,2);
		rt[x]=merge(rt[x],rt[tmp],1,w);
		modify(rt[x],1,w,val[x],v1+1,1);
		modify(rt[x],1,w,val[x],v2+1,2);
	}
	return ;
}
int main(){
	n=read();
	for(int i=1;i<=n;i++)a[i]=(node){i,read()};
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		if(a[i].data>a[i-1].data)w++;
		val[a[i].id]=w;
	}
	for(int i=1;i<=n;i++)head[i]=-1;
	for(int i=1;i<n;i++){
		int u,v;
		u=read();v=read();
		add(u,v);
		add(v,u);
	}
	dfs(1,0);
	printf("%d\n",res);
	return 0;
}