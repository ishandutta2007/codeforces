#include <bits/stdc++.h>
using namespace std;

const int MAXN=5000000;

int cnt[MAXN+5];
long long sum[MAXN+5];

inline void preprocess()
{
	for (int i=2;i<=MAXN;i++)
		if (!cnt[i])
			for (int j=i,c=1;j<=MAXN;j+=i,c++)
			{
				int t=c;
				for (;;)
				{
					cnt[j]++;
					if (t%i) break;
					t/=i;
				}
			}
	for (int i=2;i<=MAXN;i++) sum[i]=sum[i-1]+cnt[i];
}

int main()
{
	preprocess();
	int t;
	scanf("%d",&t);
	while (t--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		printf("%I64d\n",sum[a]-sum[b]);
	}
	return 0;
}