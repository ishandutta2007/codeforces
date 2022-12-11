#include <bits/stdc++.h>
using namespace std;

const int MAXN=500005;

int sum1[MAXN],sum2[MAXN];
char s[MAXN];

int main()
{
	int n,a,b,T;
	scanf("%d%d%d%d%s",&n,&a,&b,&T,s);
	int p1=1;
	if (s[0]=='w') p1+=b;
	if (T<p1)
	{
		printf("0");
		return 0;
	}
	T-=p1;
	for (int i=1;i<n;i++)
	{
		sum1[i]=sum1[i-1]+1+a;
		if (s[i]=='w') sum1[i]+=b;
	}
	for (int i=n-1;i>=1;i--)
	{
		sum2[n-i]=sum2[n-1-i]+1+a;
		if (s[i]=='w') sum2[n-i]+=b;
	}
	int ans=1;
	for (int i=n-1;i>=1;i--)
		if (sum1[i]<=T||sum2[i]<=T)
		{
			ans=i+1;
			break;
		}
	for (int i=1;i<=n;i++)
	{
		int t=T-sum1[i]-i*a;
		if (t<=0) break;
		int k=upper_bound(sum2,sum2+n,t)-sum2;
		ans=max(ans,i+k);
	}
	for (int i=1;i<=n;i++)
	{
		int t=T-sum2[i]-i*a;
		if (t<=0) break;
		int k=upper_bound(sum1,sum1+n,t)-sum1;
		ans=max(ans,i+k);
	}
	printf("%d",min(ans,n));
	return 0;
}