#include <bits/stdc++.h>
using namespace std;

int a[7];

void solve()
{
	int n,sum=0;
	scanf("%d",&n);
	for (int i=0;i<7;i++)
	{
		scanf("%d",&a[i]);
		sum+=a[i];
	}
	int wk=n/sum,res=n-wk*sum;
	if (res==0)
	{
		wk--;
		res+=sum;
	}
	int ans=INT_MAX;
	for (int i=0;i<7;i++)
	{
		int now=wk*7,t=res;
		for (int j=0;;j++)
		{
			now++;
			t-=a[(i+j)%7];
			if (t==0)
			{
				ans=min(ans,now);
				break;
			}
		}
	}
	printf("%d\n",ans);
}

int main()
{
	#ifdef local
		freopen("read.txt","r",stdin);
	#endif
	int T;
	scanf("%d",&T);
	while (T--) solve();
	return 0;
}