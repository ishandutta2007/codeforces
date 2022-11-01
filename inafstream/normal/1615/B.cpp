#include <bits/stdc++.h>
#define rep(i,n) for ((i)=1;(i)<=(n);(i)++)
#define per(i,n) for ((i)=n;(i)>=(1);(i)--)
using namespace std;

int n,m;

int s(int n,int b)
{
	if(n<(1<<(b+1))) return min((1<<b),n+1);
	return (1<<b)*(n>>(b+1))+s((n&((1<<(b+1))-1)),b);
}

void solve()
{
	int l,r,ans=0x7fffffff,i;
	scanf("%d%d",&l,&r);
	for(i=0;i<20;i++) ans=min(ans,s(r,i)-s(l-1,i));
	printf("%d\n",ans);
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--) solve();
	return 0;
}