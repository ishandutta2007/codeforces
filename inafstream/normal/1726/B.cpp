#include <bits/stdc++.h>
#define rep(i,n) for (int i=1;i<=(n);i++)
#define per(i,n) for (int i=(n);i>=1;i--)
using namespace std;

int n,m;

void solve()
{
	scanf("%d",&n);
	scanf("%d",&m);
	if(m<n){puts("No");return;}
	if(n%2==1||n==m)
	{
		puts("Yes");
		rep(i,n-1) printf("1 ");
		printf("%d\n",m-(n-1));
		return;
	}
	if(m%2==0)
	{
		puts("Yes");
		rep(i,n-2) printf("1 ");
		printf("%d %d\n",(m-(n-2))/2,(m-(n-2))/2);
		return;
	}
	puts("No");
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