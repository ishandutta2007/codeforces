// Hydro submission #614b2f9c03550f6f2d6d28d2@1632323174383
#include<bits/stdc++.h>
using namespace std;
#define int long long
inline int read()
{
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')
			f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	return x*f;
}
int n,m,i,j,k,t;
int l,r,mid;
int a[200010];

int findx(int l,int r,int k)//>=k
{
	if(a[l]>=k) return l;
	while(l<r)
	{
		mid=l+r>>1;
		if(a[mid]>=k) r=mid;
		else l=mid+1;
	}
	return l;
}

int findy(int l,int r,int k)//<=k
{
	if(a[r]<=k) return r;
	while(l<r)
	{
		mid=l+r+1>>1;
		if(a[mid]<=k) l=mid;
		else r=mid-1;
	}
	return l;
}

signed main()
{
//	freopen("tiaoshi.in","r",stdin);
//	freopen("tiaoshi.out","w",stdout);
//	std::ios::sync_with_stdio(false);
	t=read();
	while(t--)
	{
		n=read();l=read();r=read();
		for(i=1;i<=n;++i)
			a[i]=read();
		sort(a+1,a+n+1);
		for(i=1,k=0;i<n;++i)
			if(a[n]+a[i]>=l&&a[i+1]+a[i]<=r)
				k+=(findy(i+1,n,r-a[i])-findx(i+1,n,l-a[i])+1);
		printf("%lld\n",k);
	}
	return 0;
}