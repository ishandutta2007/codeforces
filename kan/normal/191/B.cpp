#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <string>
#include <vector>
#include <cstdio>

using namespace std;

typedef long long ll;
typedef long double ld;

#ifdef WIN32
	#define LLD "%I64d"
#else
	#define LLD "%lld"
#endif

const int maxn=100005;

pair<int,int> b[maxn];
int a[maxn];
ll sum[maxn];
int wh[maxn];
int n,k;
ll maxsum;

int main()
{
	scanf("%d%d",&n,&k);
	scanf(LLD,&maxsum);
	for (int i=0;i<n;i++) scanf("%d",&a[i]);
	if (k==1)
	{
		for (int i=0;i<n-1;i++) if (a[i]>maxsum)
		{
			printf("%d\n",i+1);
			return 0;
		}
		printf("%d\n",n);
		return 0;
	}
	for (int i=0;i<n-1;i++) b[i].first=a[i],b[i].second=i;
	sort(b,b+(n-1));
	reverse(b,b+(n-1));
	sum[0]=b[0].first;
	wh[b[0].second]=0;
	for (int i=1;i<n-1;i++)
	{
		wh[b[i].second]=i;
		sum[i]=sum[i-1]+b[i].first;
	}
	for (int i=0;i<n-1;i++)
	{
		ll can=sum[k-2];
		if (wh[i]<k-1) can=sum[k-1]-a[i];
// 		cerr << i << ' ' << can << endl;
		if (can+a[i]>maxsum)
		{
			printf("%d\n",i+1);
			return 0;
		}
	}
	printf("%d\n",n);
	return 0;
}