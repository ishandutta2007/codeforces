#include <bits/stdc++.h>
#define rep(i,n) for (int i=1;i<=(n);i++)
#define per(i,n) for (int i=(n);i>=1;i--)
using namespace std;

int n,m;
int a[500005];

void solve()
{
	scanf("%d%d",&n,&m);
	rep(i,n)
	{
		int x;
		scanf("%d",&x);
		a[x]++;
	}
	rep(i,m-1)
	{
		if(a[i]%(i+1)!=0)
		{
			puts("No");
			return;
		}
		a[i+1]+=a[i]/(i+1);
	}
	puts("Yes");
}



int main()
{
	int t=1;
//	scanf("%d",&t);
	while(t--)
	{
		solve();
	}
	return 0;
}