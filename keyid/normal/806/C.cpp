#include <bits/stdc++.h>
using namespace std;

#define pb push_back

typedef long long LL;

const int MAXN=100005;

LL a[MAXN];
vector <LL> b;
int cnt[40],cnt2[40];

int main()
{
	int n;
	scanf("%d",&n);
	for (int i=0;i<n;i++)
		scanf("%lld",&a[i]);
	for (int i=0;i<n;i++)
	{
		bool flag=false;
		for (int j=0;j<40;j++)
			if (a[i]==(1LL<<j))
			{
				cnt[j]++;
				flag=true;
				break;
			}
		if (!flag) b.pb(a[i]);
	}
	int l=cnt[0],r=cnt[0];
	for (int i=1;i<=cnt[0];i++)
	{
		int j;
		for (j=1;j<40&&cnt[j];j++);j--;
		cnt2[j]++;
		for (int k=1;k<=j;k++) cnt[k]--;
	}
	for (int i=1;i<40;i++)
		for (int j=0;j<cnt[i];j++)
			b.pb(1LL<<i);
	sort(b.begin(),b.end(),greater <LL> ());
	for (int i=0;i<b.size();i++)
		{
			int j=39;
			while (j>=0&&cnt2[j]==0) j--;
			if (1LL<<(j+1)<b[i])
			{
				printf("-1");
				return 0;
			}
			cnt2[j]--;
		}
	int sum=0;
	for (int i=0;i<40;i++)
		sum+=cnt2[i];
	for (int i=0;i<40;i++)
	{
		while (cnt2[i]--)
		{
			for (int j=0;j<=i;j++)
			{
				int k=39;
				while (k>=0&&cnt2[k]<=0) k--;
				if (k<0) goto label;
				cnt2[k]--;
			}
			l--;
		}
	}
	label:
	for (int i=l;i<=r;i++)
		printf("%d ",i);
	return 0;
}