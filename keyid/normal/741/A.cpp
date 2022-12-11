#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

const int MAXN=105;

int to[MAXN];
bool d[MAXN];

LL gcd(LL a,LL b)
{
	return b?gcd(b,a%b):a;
}

int main()
{
	int n;
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&to[i]);
		if (d[to[i]])
		{
			printf("-1");
			return 0;
		}
		d[to[i]]=true;
	}
	fill(d+1,d+n+1,false);
	LL ans=1;
	for (int i=1;i<=n;i++)
		if (!d[i])
		{
			d[i]=true;
			int cnt=1;
			for (int j=to[i];j!=i;j=to[j])
			{
				d[j]=true;
				cnt++;
			}
			if (cnt%2==0) cnt>>=1;
			ans=ans/gcd(ans,cnt)*cnt;
		}
	printf("%lld",ans);
	return 0;
}