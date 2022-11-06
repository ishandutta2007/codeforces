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
	int sum,mx,tag;
} tree[8010100];
struct node{
	int top,fa,siz,hson,dep;
} E[2010100];
int sum,K,H[2010100],dfn[2010100],e[2010100],a[2010100],b[2010100],d[2010100],ans;
int u,v,cnt,n,m,i,T,x,y,id;
bool exist[2010100];
void add(int x,int y)
{
	cnt++;a[cnt]=y;b[cnt]=d[x];d[x]=cnt;
}
void pushup(int x)
{
	tree[x].sum=tree[x*2].sum+tree[x*2+1].sum;
}
void pushdown(int x,int l,int r)
{
	int mid=(l+r)/2;
	if (tree[x].tag==1) tree[x*2].sum=0,tree[x*2].tag=1;
	if (tree[x].tag==1) tree[x*2+1].sum=0,tree[x*2+1].tag=1;
}
void build(int x,int l,int r)
{
	if (l==r)
	    {
	    	if (r!=dfn[n]) tree[x].sum=1;
			return ;
		}
	int mid=(l+r)/2;
	build(x*2,l,mid);build(x*2+1,mid+1,r);
	pushup(x);
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
void modify(int x,int l,int r,int tl,int tr)
{
	if ((l>=tl)&&(r<=tr))
	     { 
	     tree[x].tag=1;
	     tree[x].sum=0;
	     return ;
		 }
	pushdown(x,l,r);
	int mid=(l+r)/2;
	if (mid>=tl) modify(x*2,l,mid,tl,tr);
	if (mid<tr) modify(x*2+1,mid+1,r,tl,tr);
	pushup(x);
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
	n=read();K=read();K=n-K;
	for (i=1;i<n;i++) 
	    {
	    	x=read();y=read();
	    	add(x,y);add(y,x);
		 } 
	for (i=1;i<=n;i++) e[i]=1;
	E[n].dep=1;build1(n,0);build2(n,0);
	for (i=1;i<=n;i++) H[dfn[i]]=i;
	build(1,1,n);sum=1;
	for (i=n-1;i>=1;i--)
	     {
			     	ans=0;
			     	//cout<<E[E[v].top].fa<<endl;
			     	u=i;v=n;
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
					ans=ans+query_sum(1,1,n,dfn[u],dfn[v]);
					if (sum+ans<=K)
					    {
					    	u=i;v=n;
						while (E[u].top!=E[v].top)
	     	     	     {
	     	     	     	if (E[E[u].top].dep>E[E[v].top].dep)
	     	     	     	    { 
	     	     	     	      modify(1,1,n,dfn[E[u].top],dfn[u]);
	     	     	     	       u=E[E[u].top].fa;
								   }
							else
							    {
							    	modify(1,1,n,dfn[E[v].top],dfn[v]);v=E[E[v].top].fa;
								}
						   }
					if (dfn[u]>dfn[v]) swap(u,v);
					modify(1,1,n,dfn[u],dfn[v]);
					    	sum+=ans;
						}
		 }
	for (i=1;i<=n;i++)
	   if (query_sum(1,1,n,dfn[i],dfn[i])==1)
	       printf("%d ",i);
	puts("");
 return 0;
}