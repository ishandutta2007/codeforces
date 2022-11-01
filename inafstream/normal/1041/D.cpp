#include <bits/stdc++.h>
#define rdst(st,len) {char ss[len];scanf("%s",ss);(st)=ss;}
using namespace std;
long long n,m,i,j,ans,a[200005],l[200005],r[200005];
int main()
{
	scanf("%I64d%I64d",&n,&m);
	ans=m;
	for (i=1;i<=n;i++)
	{
		scanf("%I64d%I64d",&l[i],&r[i]);
	}
	for (i=1;i<n;i++)
	{
		a[i]=l[i+1]-r[i];
		a[i]+=a[i-1];
	}
	a[n]=1ll<<50;
	for (i=1;i<=n;i++)
	{
		long long t=lower_bound(a+i,a+n+1,a[i-1]+m)-a;
		if (a[t]-a[i-1]>=m) t--;
		ans=max(ans,m-(a[t]-a[i-1])+r[t+1]-l[i]);
	}
	cout<<ans<<endl;
	return 0;
}