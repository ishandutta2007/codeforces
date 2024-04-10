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
struct node{
	int siz,hson,dep;
} E[510100];
vector<pair<int,int>> Asking[301010];
int j,Answer[300101],n,i,x,Testing,y,cnt,up,G,a[1001010],H[201010],Val[1001010],b[1001010],d[1001010],dfn[1001010],id,F[100101][22];
bool AAA[301010],exist[1001010];
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
            F[a[i]][0]=x;
            for (j=1;j<=20;j++) F[a[i]][j]=F[F[a[i]][j-1]][j-1];
			build1(a[i],x);E[x].siz+=E[a[i]].siz; 
			if (E[a[i]].siz>mx) mx=E[a[i]].siz,E[x].hson=a[i];    	
		 }
	if (E[x].hson!=0) exist[E[x].hson]=true;
}
void delet(int x)
{
	   for (int i=dfn[x];i<=dfn[x]+E[x].siz-1;i++) Val[E[H[i]].dep]--;
}
void insert(int x,int fa)
{
for (int i=dfn[x];i<=dfn[x]+E[x].siz-1;i++) Val[E[H[i]].dep]++;
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
	Val[E[x].dep]++;
	for (int i=0;i<Asking[x].size();i++)
	     Answer[Asking[x][i].second]=Val[E[x].dep+Asking[x][i].first];
}
int main()
{
    n=read();
	for (i=1;i<=n;i++) 
	    {
	    	x=read();
	    	if (x==0) x=n+1;
	    	add(x,i);
		 } 
	E[n+1].dep=1;build1(n+1,0);
	for (i=1;i<=n+1;i++) H[dfn[i]]=i;
	Testing=read();
	for (j=1;j<=Testing;j++)
	    { 
	       x=read();y=read();
	       up=-1;G=y;
	       for (i=20;i>=0;i--)
	            if ((F[x][i])&&(G>=(1<<i)))
	                x=F[x][i],G-=(1<<i);
	        if ((G==0)&&(x!=-1)&&(x!=n+1)) 
			    Asking[x].push_back(make_pair(y,j)),AAA[j]=true;
		}
	sc(n+1,0);
  for (i=1;i<=Testing;i++)
     if (AAA[i]) printf("%d ",Answer[i]-1);
     else printf("0 ");
     puts("");
 return 0;
}