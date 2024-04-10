#include <bits/stdc++.h>
#define rep(i,n) for ((i)=1;(i)<=(n);(i)++)
#define per(i,n) for ((i)=n;(i)>=(1);(i)--)
using namespace std;

int x,y;

void solve()
{
	scanf("%d%d",&x,&y);
	
	if(x==y)
	{
		printf("%d\n",x);
		return;
	}
	
	if(x>y)
	{
		printf("%d\n",x+y);
		return;
	}
	
	int t=y/x*x;
	printf("%d\n",(t+y)/2);
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