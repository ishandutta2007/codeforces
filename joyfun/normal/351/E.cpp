#include<iostream>
#include<stdio.h>
#include<string>
#include<string.h>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;

#define ll long long

ll read()
{
    ll x=0,f=1;char c=getchar();
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
    return x*f;
}

inline void out (int x)
{
	if (x>9) out(x/10);
	putchar (x%10+'0');
}

int n;
int a[2010],b[2010];
int ans;

void work (int x)
{
	int l,r; l=r=0;
	for (int i=1;i<x;i++)
	  if (a[x]>a[i]) l++;
	for (int i=x+1;i<=n;i++)
	  if (a[x]>a[i]) r++;
	if (l>r) b[x]=a[x];
	else b[x]=-a[x];
}

void doing ()
{
	ans=0;
	for (int i=1;i<=n;i++)
	{
		a[i]=read();
		if (a[i]<0) a[i]=-a[i];
	}
	for (int i=1;i<=n;i++)
	  work(i);
	for (int i=1;i<=n;i++)
	  for (int j=i+1;j<=n;j++)
	    if (b[i]>b[j]) ans++;
	cout<<ans<<endl;
}

int main ()
{
	//freopen("xx.in","r",stdin);
	//freopen("xx.out","w",stdout);
	while (~scanf("%d",&n))
	  doing ();
	return 0;
}