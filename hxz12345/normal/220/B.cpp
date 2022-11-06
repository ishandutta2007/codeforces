#include<bits/stdc++.h>
using namespace std;
struct hxz{
	int l,r,id;
};
struct ppp{
	int x,y;
};
ppp aa[2000000];
hxz b[2000000];
long long  e[2000000],a[2000000];
long long h[2000000],c[2000000],ans;
long long nn,l,r,mid,K,m,piece,L,R,curR,curL,n,i;
inline int read()			
{
  int x=0,f=1;char ch=getchar();
  while(!isdigit(ch)&&ch!='-')ch=getchar();
  if(ch=='-')f=-1,ch=getchar();
  while(isdigit(ch))x=(x<<1)+(x<<3)+ch-'0',ch=getchar();
  return x*f;
}
bool cmp(hxz a,hxz b)
{
	if (a.l/piece==b.l/piece) return a.r<b.r;
	else return a.l<b.l;
}
void del(int x)
{
	if (e[aa[x].x]==aa[x].y+1) ans++;
	if (e[aa[x].x]==aa[x].y) ans--;
	e[aa[x].x]--;
}
void ins(int x)
{
	if (e[aa[x].x]==aa[x].y) ans--;
	if (e[aa[x].x]==aa[x].y-1) ans++;
	e[aa[x].x]++;
 } 
int main()
{
	n=read();m=read();piece=sqrt(n);
	for (i=1;i<=n;i++) a[i]=read(),c[i]=a[i];
	sort(c+1,c+n+1);
	for (i=1;i<=n;i++)
	   if (c[i]!=c[i-1]) c[++nn]=c[i];
	for (i=1;i<=n;i++)
	     {
	     	l=1;r=nn;
	     	while (l<=r)
	     	    {
	     	    	mid=(l+r)/2;
	     	    	if (c[mid]==a[i]) 
	     	    	   {
	     	    	   	ans=mid;break;
						}
					else if (c[mid]>a[i]) r=mid-1;
					else l=mid+1;
				 }
			aa[i].x=mid;aa[i].y=a[i];
		 }
	for (i=1;i<=m;i++) b[i].l=read(),b[i].r=read(),b[i].id=i;
	sort(b+1,b+m+1,cmp);curL=1;ans=0;
	for (i=1;i<=m;i++)
	     {
	     	L=b[i].l;R=b[i].r;
	     	while (curR>R) del(curR),curR--;
	     	while (curL<L) del(curL),curL++;
	     	while (curR<R) curR++,ins(curR);
	     	while (curL>L) curL--,ins(curL);
	     	h[b[i].id]=ans;
		 }
	for (i=1;i<=m;i++)
	   printf("%d\n",h[i]);
	return 0;
}