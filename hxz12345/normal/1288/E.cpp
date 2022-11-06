#include<bits/stdc++.h>
using namespace std;
inline int read()			
{
  int x=0,f=1;char ch=getchar();
  while(!isdigit(ch)&&ch!='-')ch=getchar();
  if(ch=='-')f=-1,ch=getchar();
  while(isdigit(ch))x=(x<<1)+(x<<3)+ch-'0',ch=getchar();
  return x*f;
}
struct hxz{
	int l,r,id;
};
hxz b[2000000];
int f[1001000],apr[2000000],e[2000000],a[2000000],c[2000000],exist[2000000];
int x,mm,n,m,i,j,ans,lft;
int lowbit(int x)
{
	return x & -x;
}
bool cmp(hxz a,hxz b)
{
	return a.r<b.r;
}
void add(int x,int y)
{
	for (;x<=m;x+=lowbit(x))
	    e[x]+=y;
}
int query(int x)
{
	int ans=0;
	for (;x;x-=lowbit(x))
	    ans+=e[x];
	return ans;
}
int main()
{
	n=read();mm=read();
	for (i=n;i>=1;i--) apr[i]=n-i+1,a[n-i+1]=i;
	for (i=1;i<=mm;i++)
	    {
	    	x=read();a[n+i]=x;f[x]=1;
	    	m++;b[m].l=apr[x];b[m].r=n+i-1;b[m].id=x;apr[x]=n+i;
		}
	for (i=1;i<=n;i++)
	     {
	     	m++;b[m].l=apr[i];b[m].r=mm+n;b[m].id=i;
		 }
	sort(b+1,b+m+1,cmp);
	lft=1;
	for (i=1;i<=m;i++)
	    {
	    	for (j=lft;j<=b[i].r;j++)
	    	    {
	    	    	if (exist[a[j]]!=0) add(exist[a[j]],-1);
	    	    	exist[a[j]]=j;
	    	    	add(exist[a[j]],1);
				}
			lft=b[i].r;
			c[b[i].id]=max(c[b[i].id],query(b[i].r)-query(b[i].l-1));
		}
	for (i=1;i<=n;i++) c[i]=max(c[i],i);
	for (i=1;i<=n;i++) if (f[i]==0) f[i]=i;
	for (i=1;i<=n;i++)
	  printf("%d %d\n",f[i],c[i]);
	return 0;
}