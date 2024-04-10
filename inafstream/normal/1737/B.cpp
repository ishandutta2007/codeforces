#include <bits/stdc++.h>
#define rep(i,n) for (int i=1;i<=(n);i++)
#define per(i,n) for (int i=(n);i>=1;i--)
using namespace std;

long long l,r;

long long solve(long long n)
{
	long long m=sqrt(n);
	while(m*m>n) m--;
	while((m+1)*(m+1)<=n) m++;

	long long ans=m*3-2;
	if(m*(m+1)<=n) ans++;
	if(m*(m+2)<=n) ans++;
	return ans;
}

void solve()
{
	scanf("%lld%lld",&l,&r);
	printf("%lld\n",solve(r)-solve(l-1));
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		solve();
	}
	return 0;
}