#include <bits/stdc++.h>
#define rep(i,n) for (int i=1;i<=(n);i++)
#define per(i,n) for (int i=(n);i>=1;i--)
using namespace std;

int n,k;
int c[35];

void solve()
{
	scanf("%d%d\n",&n,&k);
	memset(c,0,sizeof(c));
	rep(i,n)
	{
		char x;
		scanf("%c",&x);
		c[x-'a']++;
	}
	rep(i,k)
	{
		int s=0;
		while(c[s]&&s<n/k) c[s]--,s++;
		putchar('a'+s);
	}
	puts("");
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