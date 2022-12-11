#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

const int MAXN=11;

LL cnt[MAXN][65][1<<MAXN];

LL solve(int b,LL x)
{
	if (x==0) return 0;
	vector <int> d;
	while (x)
	{
		d.push_back(x%b);
		x/=b;
	}
	LL ans=0;
	for (int i=(int)d.size()-2;i>=0;i--)
	{
		for (int j=1;j<b;j++)
			ans+=cnt[b][i][1<<j];
	}
	int now=0;
	for (int i=d.size()-1;i>=0;i--)
	{
		if (i==d.size()-1)
			for (int j=1;j<d[i];j++)
				ans+=cnt[b][i][now^(1<<j)];
		else
			for (int j=0;j<d[i];j++)
				ans+=cnt[b][i][now^(1<<j)];
		now^=(1<<d[i]);
	}
	if (now==0) ans++;
	return ans;
}

int main()
{
	for (int i=2;i<=10;i++)
	{
		cnt[i][0][0]=1;
		for (int j=1;j<65;j++)
			for (int k=0;k<(1<<i);k++)
			{
				for (int l=0;l<i;l++)
					cnt[i][j][k]+=cnt[i][j-1][k^(1<<l)];
			}
	}
	int q;
	scanf("%d",&q);
	while (q--)
	{
		int b;
		LL l,r;
		scanf("%d%lld%lld",&b,&l,&r);
		printf("%lld\n",solve(b,r)-solve(b,l-1));
	}
	return 0;
}