#include<bits/stdc++.h>
using namespace std;
#define MAXN 100005
#define ll long long
int n,m,i;
ll x,y,a[MAXN],s[MAXN];
int main()
{
	scanf("%d",&n);
	for(i=1;i<=n;i++)scanf("%I64d",a+i);
	sort(a+1,a+n+1);
	for(i=1;i<n;i++)a[i]=a[i+1]-a[i];
	a[n]=1LL<<60;
	sort(a+1,a+n+1);
	for(i=1;i<=n;i++)s[i]=s[i-1]+a[i];
	scanf("%d",&m);
	while(m--)
	{
		scanf("%I64d%I64d",&x,&y);
		x=y-x+1;
		i=lower_bound(a+1,a+n+1,x)-a-1;
		cout<<s[i]+x*(n-i)<<' ';
	}
	return 0;
}