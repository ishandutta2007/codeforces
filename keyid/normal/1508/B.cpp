#include <bits/stdc++.h>
using namespace std;

#define pb push_back

typedef long long LL;

LL get_f(int n)
{
	n--;
	return n<60?1LL<<n:1LL<<60;
}

void dfs(int n,LL k,int offset)
{
	for (int i=1;i<=n;i++)
	{
		LL t=get_f(n-i);
		if (t>=k)
		{
			for (int j=i;j>=1;j--)
				printf("%d ",j+offset);
			dfs(n-i,k,offset+i);
			return;
		}
		k-=t;
	}
	for (int i=n;i>=1;i--)
		printf("%d ",i+offset);
}

void solve()
{
	int n;
	LL k;
	scanf("%d%lld",&n,&k);
	if (get_f(n)<k)
	{
		puts("-1");
		return;
	}
	dfs(n,k,0);
	puts("");
}

int main()
{
#ifdef KeyID
	freopen("read.txt","r",stdin);
#endif
	int T;
	scanf("%d",&T);
	while (T--) solve();
	return 0;
}