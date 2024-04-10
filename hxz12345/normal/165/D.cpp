#include<bits/stdc++.h>
using namespace std;
inline long long read()
{
  long long x=0,f=1;char ch=getchar();
  while(!isdigit(ch)&&ch!='-')ch=getchar();
  if(ch=='-')f=-1,ch=getchar();
  while(isdigit(ch))x=(x<<1)+(x<<3)+ch-'0',ch=getchar();
  return x*f;
}
long long pow(long long x,long long y,long long p)
{
	long long ans=1;
	for (;y;y>>=1,x=x*x % p)
		if (y&1) ans=ans*x % p;
	return ans;
}
long long gcd(long long x,long long y)
{
	if (y==0) return x;
	long long ans=gcd(y,x % y);return ans;
}
//build1:find depth,father,size,height_son 
//build2:find height_son's top and height_son's id
struct SegmentTree{
	long long sum,mx,tag;
} tree[1010100];
struct node{
	long long top,fa,siz,hson,dep;
} E[1010100];
struct Edge{
	long long x,y;
} edge[301010];
long long u_lst,v_lst,opt,H[1010100],dfn[1010100],e[1010100],a[1010100],b[1010100],d[1010100],ans;
int u,v,cnt,n,m,i,T,x,y,id;
bool exist[1010100];
void add(int x,int y)
{
	cnt++;a[cnt]=y;b[cnt]=d[x];d[x]=cnt;
}
void pushup(int x)
{
	tree[x].sum=tree[x*2].sum+tree[x*2+1].sum;
	tree[x].mx=max(tree[x*2].mx,tree[x*2+1].mx);
}
void pushdown(int x,int l,int r)
{
	int mid=(l+r)/2;
	tree[x*2].sum+=tree[x].tag*(mid-l+1);tree[x*2].mx+=tree[x].tag;tree[x*2].tag+=tree[x].tag;
	tree[x*2+1].sum+=tree[x].tag*(r-mid);tree[x*2+1].mx+=tree[x].tag;tree[x*2+1].tag+=tree[x].tag;
	tree[x].tag=0;
}
void build1(int x,int fa)
{
	E[x].siz=1;int mx=0;E[x].hson=0;
	for (int i=d[x];i;i=b[i])
	   if (a[i]!=fa)
	     {
	     	E[a[i]].dep=E[x].dep+1;
            E[a[i]].fa=x;build1(a[i],x);E[x].siz+=E[a[i]].siz; 
			if (E[a[i]].siz>mx) mx=E[a[i]].siz,E[x].hson=a[i];    	
		 }
	if (E[x].hson!=0) exist[E[x].hson]=true;
}
void build2(int x,int fa)
{
	id++;dfn[x]=id;
	if (exist[x]==false) E[x].top=x;
	for (int i=d[x];i;i=b[i])
	    if (a[i]==E[x].hson)
	       {
	        	if (exist[a[i]]) E[a[i]].top=E[x].top;
	        	build2(a[i],x);
		    }
	for (int i=d[x];i;i=b[i])
	   if (a[i]!=E[x].hson)
	     if (a[i]!=fa)
	        {
	        	if (exist[a[i]]) E[a[i]].top=E[x].top;
	        	build2(a[i],x);
		    }
}
void modify(int x,int l,int r,int tl,int tr,int val)
{
	if ((l>=tl)&&(r<=tr))
	     { 
	     tree[x].tag+=(val-tree[x].sum);
	     tree[x].sum=val;tree[x].mx=val;
	     return ;
		 }
	pushdown(x,l,r);
	int mid=(l+r)/2;
	if (mid>=tl) modify(x*2,l,mid,tl,tr,val);
	if (mid<tr) modify(x*2+1,mid+1,r,tl,tr,val);
	pushup(x);
}
long long query_max(int x,int l,int r,int tl,int tr)
{
	if ((l>=tl)&&(r<=tr)) return tree[x].mx;
	pushdown(x,l,r);
	int mid=(l+r)/2;
	long long ans=-1e9;
	if (mid>=tl) ans=max(ans,query_max(x*2,l,mid,tl,tr));
	if (mid<tr) ans=max(ans,query_max(x*2+1,mid+1,r,tl,tr));
	pushup(x);
	return ans;
}
long long query_sum(int x,int l,int r,int tl,int tr)
{
	if ((l>=tl)&&(r<=tr)) return tree[x].sum;
	pushdown(x,l,r);
	int mid=(l+r)/2;
	long long ans=0;
	if (mid>=tl) ans=ans+query_sum(x*2,l,mid,tl,tr);
	if (mid<tr) ans=ans+query_sum(x*2+1,mid+1,r,tl,tr);
	pushup(x);
	return ans;
}
int main()
{
	//ios::sync_with_stdio(0);cin.tie();cout.tie();
	char s[1010];
	n=read();
	for (i=1;i<n;i++) 
	    {
	    	x=read();y=read();
	    	add(x,y);add(y,x);
	    	edge[i].x=x;edge[i].y=y;
		 } 
	E[1].dep=1;build1(1,0);build2(1,0);
	for (i=1;i<=n;i++) H[dfn[i]]=i;
	for (T=read();T;T--)
	     {
	     	opt=read();
	     	 if (opt<3)
	     	     {
	     	     	   id=read();
	     	     	   u=edge[id].x;v=edge[id].y;
	     	     	   if (dfn[u]>dfn[v]) swap(u,v);
	     	     	   if (opt==1) modify(1,1,n,dfn[v],dfn[v],0);
	     	     	   else modify(1,1,n,dfn[v],dfn[v],1);
	     	    }
	     	else
			     {
			     	ans=0;
			     	//cout<<E[E[v].top].fa<<endl;
			     	u=read();v=read();
			     	u_lst=u;v_lst=v;
	     	     	while (E[u].top!=E[v].top)
	     	     	     {
	     	     	     	if (E[E[u].top].dep>E[E[v].top].dep)
	     	     	     	    { 
	     	     	     	       ans=ans+query_sum(1,1,n,dfn[E[u].top],dfn[u]);
	     	     	     	       u=E[E[u].top].fa;
								   }
							else
							    {
							    	ans=ans+query_sum(1,1,n,dfn[E[v].top],dfn[v]);v=E[E[v].top].fa;
								}
						   }
					if (dfn[u]>dfn[v]) swap(u,v);
					ans=ans+query_sum(1,1,n,dfn[u]+1,dfn[v]);
					if (ans!=0) puts("-1");
					else printf("%lld\n",E[u_lst].dep+E[v_lst].dep-E[u].dep*2);
		}
		 }
 return 0;
}