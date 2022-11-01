#include <bits/stdc++.h>
#define rep(i,n) for ((i)=1;(i)<=(n);(i)++)
#define per(i,n) for ((i)=n;(i)>=(1);(i)--)
using namespace std;

int n,m;

void solve()
{
	int i,j,sum=0;
	scanf("%d",&n);
	rep(i,n)
	{
		int x;scanf("%d",&x);
		sum+=x;
	}
	if(sum%n==0) puts("0"); else puts("1");
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--) solve();
	return 0;
}