#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<algorithm>
#define fo(i,a,b) for(int i=a;i<=b;i++)
#define fod(i,a,b) for(int i=a;i>=b;i--)
using namespace std;
typedef long long LL;
const int N=1050,maxlongint=2147483640;
int read(int &n)
{
	char ch=' ';int q=0,w=1;
	for(;(ch!='-')&&((ch<'0')||(ch>'9'));ch=getchar());
	if(ch=='-')w=-1,ch=getchar();
	for(;ch>='0' && ch<='9';ch=getchar())q=q*10+ch-48;n=q*w;return n;
}
int m,n,ans;
int a[N*N],a0[N*N],b[N*N];
bool PX(int q,int w){return q>w;}
int gcd(int x,int y){return(y?gcd(y,x%y):x);}
int ef(int q)
{
	int l=1,r=m;
	while(l<r)
	{
		int mid=(l+r)/2;
		if(a[mid]>q)l=mid+1;
			else r=mid;
	}
	return l;
}
int main()
{
//	freopen("!.in","r",stdin);
//	freopen("1.out","w",stdout);
	int q,w,e;
	read(n);
	fo(i,1,n*n)read(b[i]);
	sort(b+1,b+1+n*n,PX);
	m=0;
	fo(i,1,n*n)
		if(a[m]==b[i])a0[m]++;
			else a[++m]=b[i],a0[m]=1;
	fill(b,b+n*n+2,0);n=0;
	fo(i,1,m)if(a0[i])
	{
		q=0;
		fo(j,1,n)q+=(b[j]%a[i])==0;
		w=sqrt(4*q*q+4*a0[i])/2-q;
		q=0;
		fo(j,1,n)
		{
			if(b[j]!=b[j-1])q=gcd(b[j],a[i]);
			a0[ef(q)]-=2*w;
		}
		fo(j,n+1,n+w)b[j]=a[i];n+=w;
	}
	fo(i,1,n)printf("%d ",b[i]);
	return 0;
}