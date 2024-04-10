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
struct Node{
	int a,b;
};
struct SegmentTree{
	int mx,id;
} tree[6001010];
struct node{
	int siz,hson,dep;
} E[4010100];
vector<pair<int,int>> Asking[301010];
int j,Answer[4000101],n,i,x,Testing,y,cnt,up,G,a[2001010],H[2001010],Val[2001010],b[2001010],d[2001010],dfn[2001010],id;
bool AAA[4001010],exist[2001010];
void add(int x,int y)
{
	cnt++;a[cnt]=y;b[cnt]=d[x];d[x]=cnt;
}
void build1(int x,int fa)
{
	int j;
	id++;dfn[x]=id;
	E[x].siz=1;int mx=0;E[x].hson=0;
	for (int i=d[x];i;i=b[i])
	   if (a[i]!=fa)
	     {
	     	E[a[i]].dep=E[x].dep+1;
			build1(a[i],x);E[x].siz+=E[a[i]].siz; 
			if (E[a[i]].siz>mx) mx=E[a[i]].siz,E[x].hson=a[i];    	
		 }
	if (E[x].hson!=0) exist[E[x].hson]=true;
}
void build(int x,int l,int r)
{
	if (l==r)
	    {
	    	   tree[x].id=l;return ;
		}
	int mid=(l+r)/2;
	build(x*2,l,mid);build(x*2+1,mid+1,r);
	tree[x].id=tree[x*2].id;
}
void modify(int x,int l,int r,int tl,int tr,int val)
{
	if ((l>=tl)&&(r<=tr))
	   { 
	      tree[x].mx+=val;return ;
	   }
	int mid=(l+r)/2;
	if (mid>=tl) modify(x*2,l,mid,tl,tr,val);
	if (mid<tr) modify(x*2+1,mid+1,r,tl,tr,val);
	if (tree[x*2].mx>=tree[x*2+1].mx) tree[x].id=tree[x*2].id;
	else tree[x].id=tree[x*2+1].id;
	tree[x].mx=max(tree[x*2].mx,tree[x*2+1].mx);
	/*tree[x].mx=max(tree[x*2].mx,tree[x*2+1].mx);
	if (tree)*/
}
Node find(int x,int l,int r,int tl,int tr)
{
	if ((l>=tl)&&(r<=tr)) return (Node){tree[x].mx,tree[x].id};
	int mid=(l+r)/2;
	Node lft,rit;
	lft.a=lft.b=rit.a=rit.b=-1;
	if (mid>=tl) lft=find(x*2,l,mid,tl,tr);
	if (mid<tr) rit=find(x*2+1,mid+1,r,tl,tr);
    if (tree[x*2].mx>=tree[x*2+1].mx) tree[x].id=tree[x*2].id;
	else tree[x].id=tree[x*2+1].id;
	tree[x].mx=max(tree[x*2].mx,tree[x*2+1].mx);
	if ((lft.b==-1)) return rit;
	else if (rit.b==-1) return lft;
	else 
	   { 
	   if (lft.a>=rit.a) return lft;
	   else return rit;
	   }
}
void delet(int x)
{
	   for (int i=dfn[x];i<=dfn[x]+E[x].siz-1;i++) modify(1,1,n,E[H[i]].dep,E[H[i]].dep,-1);
}
void insert(int x,int fa)
{
for (int i=dfn[x];i<=dfn[x]+E[x].siz-1;i++) modify(1,1,n,E[H[i]].dep,E[H[i]].dep,1);
}
void sc(int x,int fa)
{
	int i;
	for (i=d[x];i;i=b[i])
	     if (a[i]!=fa)
	         if (a[i]!=E[x].hson)
	            {
	            sc(a[i],x);
	            delet(a[i]);
	            }
	if (E[x].hson!=0)
	    {
	    sc(E[x].hson,x);
    	for (i=d[x];i;i=b[i])
	     if (a[i]!=fa)
	         if (a[i]!=E[x].hson)
	            insert(a[i],x);
	   }
	modify(1,1,n,E[x].dep,E[x].dep,1);
	Answer[x]=find(1,1,n,E[x].dep,n).b-E[x].dep;
}
int main()
{
    n=read();
    for (i=1;i<n;i++)
        {
        	x=read();y=read();
        	add(x,y);add(y,x);
		}
	E[1].dep=1;build1(1,0);build(1,1,n);
	for (i=1;i<=n;i++) H[dfn[i]]=i;
    sc(1,0);
    for (i=1;i<=n;i++) printf("%d\n",Answer[i]);
 return 0;
}