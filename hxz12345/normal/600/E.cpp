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
} tree[3010100];
struct node{
	long long col,top,fa,siz,hson,dep;
} E[510100];
long long col[1001010],up[1001010],Answer[1001010],opt,H[1010100],dfn[1010100],e[1010100],a[1010100],b[1010100],d[1010100],ans;
int u,v,cnt,n,m,i,T,x,y,id;
bool exist[1010100];
void add(int x,int y)
{
	cnt++;a[cnt]=y;b[cnt]=d[x];d[x]=cnt;
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
void delet(int x)
{
	//cout<<"-----"<<x<<"-----\n";
	for (int i=dfn[x];i<=dfn[x]+E[x].siz-1;i++)
	       col[E[H[i]].col]--;
}
void insert(int x,int fa)
{
	for (int i=dfn[x];i<=dfn[x]+E[x].siz-1;i++)
	       {
	       col[E[H[i]].col]++;
	       if (col[E[H[i]].col]>up[fa])
	             {
	             	up[fa]=col[E[H[i]].col];
	             	Answer[fa]=E[H[i]].col;
				 }
			else if (col[E[H[i]].col]==up[fa]) Answer[fa]+=E[H[i]].col;
	       }
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
	     sc(E[x].hson,x);Answer[x]=Answer[E[x].hson];up[x]=up[E[x].hson];
	     //cout<<"---"<<x<<"---:"<<Answer[x]<<endl;
	for (i=d[x];i;i=b[i])
	     if (a[i]!=fa)
	         if (a[i]!=E[x].hson)
	            insert(a[i],x);
	   }
	      col[E[x].col]++;
	      if (col[E[x].col]==up[x]) Answer[x]+=E[x].col;
	      else if (col[E[x].col]>up[x]) Answer[x]=E[x].col,up[x]=col[E[x].col];
}
int main()
{
	//ios::sync_with_stdio(0);cin.tie();cout.tie();
	char s[1010];
	n=read();
	for (i=1;i<=n;i++) E[i].col=read();
	for (i=1;i<n;i++) 
	    {
	    	x=read();y=read();
	    	add(x,y);add(y,x);
		 } 
	E[1].dep=1;build1(1,0);build2(1,0);
	for (i=1;i<=n;i++) H[dfn[i]]=i;
	sc(1,0);
	for (i=1;i<=n;i++) printf("%lld ",Answer[i]);
 return 0;
}