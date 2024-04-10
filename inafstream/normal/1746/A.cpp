#include <bits/stdc++.h>
#define rep(i,n) for (int i=1;i<=(n);i++)
#define per(i,n) for (int i=(n);i>=1;i--)
using namespace std;

int n,m,a[55];

void solve()
{
	scanf("%d%d",&n,&m);

	int flg=0;
	rep(i,n)
	{
		int x;
		scanf("%d",&x);
		if(x) flg=1;
	}

	if(flg) puts("YES"); else puts("NO");
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