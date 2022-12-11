#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair <int,int> pii;

#define mp make_pair
#define fi first
#define sc second
#define pb push_back

const int MAXN=300005;

pii c[MAXN];
LL sum[MAXN],mx[MAXN];
vector <int> ans1,ans2;

bool work(int n,int x1,int x2)
{
	for (int i=0;i<n;i++)
	{
		int t=(x1-1)/c[i].fi+1;
		if (i+t<n)
		{
			if (mx[i+t]>=x2)
			{
				for (int j=i;j<i+t;j++)
					ans1.pb(c[j].sc);
				for (int k=i+t;k<n;k++)
					if (sum[k]>=x2)
					{
						for (int l=k;l<n;l++)
							ans2.pb(c[l].sc);
						break;
					}
				return true;
			}
		}
	}
	return false;
}

int main()
{
	int n,x1,x2;
	scanf("%d%d%d",&n,&x1,&x2);
	for (int i=0;i<n;i++)
	{
		scanf("%d",&c[i].fi);
		c[i].sc=i;
	}
	sort(c,c+n);
	for (int i=n-1;i>=0;i--)
	{
		sum[i]=(LL)c[i].fi*(n-i);
		mx[i]=max(mx[i+1],sum[i]);
	}
	bool flag=true;
	if (!work(n,x1,x2))
		if (work(n,x2,x1))
			swap(ans1,ans2);
		else
			flag=false;
	if (flag)
	{
		puts("Yes");
		printf("%u %u\n",ans1.size(),ans2.size());
		for (int x:ans1)
			printf("%d ",x+1);
		puts("");
		for (int x:ans2)
			printf("%d ",x+1);
	}
	else
		puts("No");
	return 0;
}