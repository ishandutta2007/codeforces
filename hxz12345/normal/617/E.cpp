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
struct hxz{
	long long l,r,id;
};
hxz a[100100];
long long i,n,K,m,piece,c[101000],f[10001000];
long long b[1001000],L,R,curR,curL;
long long ans;
bool cmp(hxz a,hxz b)
{
	if ((a.l/piece==b.l/piece)) return a.r<b.r;
	else return a.l<b.l;
}
void ins(int x)
{
	ans=ans+f[c[x]^K];
	f[c[x]]++;
}
void del(int x)
{
	f[c[x]]--;
	ans=ans-f[c[x]^K];
}
int main()
{
	n=read();m=read();K=read();piece=sqrt(n);
	for (i=1;i<=n;i++) 
	    {
		c[i]=read();c[i]=c[i-1]^c[i];
	    }
	for (i=1;i<=m;i++) a[i].l=read(),a[i].r=read(),a[i].id=i;
	sort(a+1,a+m+1,cmp);
	curL=0;curR=-1;
	for (i=1;i<=m;i++)
	     {
	     	L=a[i].l-1;R=a[i].r;
	     	while (curR<R) curR++,ins(curR);
	     	while (curR>R) del(curR),curR--;
	     	while (curL>L) curL--,ins(curL);
	     	while (curL<L) del(curL),curL++;
	     	b[a[i].id]=ans;
		 }
	for (i=1;i<=m;i++) printf("%lld\n",b[i]);
return 0;
}