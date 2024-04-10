#include <bits/stdc++.h>
#define rep(i,n) for ((i)=1;(i)<=(n);(i)++)
#define per(i,n) for ((i)=n;(i)>=(1);(i)--)
using namespace std;

long long tmp[100005];
int n,a[100005],m;

void solve()
{
	int i;
	scanf("%d",&n);
	rep(i,n) scanf("%d",&a[i]);
	
	rep(i,min(n,m))
	{
		if(a[i]%tmp[i]==0)
		{
			puts("NO");
			return;
		}
	}
	
	puts("YES");
}

int main()
{
	int i;
	tmp[1]=2;
	for(i=2;tmp[i-1]<=1000000000;i++)
	{
		tmp[i]=tmp[i-1]/__gcd((long long)i+1,tmp[i-1])*(i+1);
	}
	m=i-1;
	
	int t;
	scanf("%d",&t);
	while(t--)
	{
		solve();
	}
	return 0;
}