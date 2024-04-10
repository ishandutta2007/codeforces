#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <map>

using namespace std;

const int N=100005;

long long a[N],s[N];

int main()
{
	#ifdef LOCAL_TEST
		freopen("b.in","r",stdin);
		freopen("b.out","w",stdout);
	#endif
	int n; scanf("%d",&n);
	for (int i=0;i<n;i++) scanf("%I64d",&a[i]);
	sort(a,a+n);
	for (int l=0,r=n-1;l<=r;l++,r--) swap(a[l],a[r]);
	for (int i=n-1;i>=0;i--) s[i]=s[i+1]+a[i];
	long long tmp=0;
	for (int i=0;i<n;i++) tmp+=a[i]*i;
	int q; scanf("%d",&q);
	while (q--)
	{
		int k; scanf("%d",&k);
		if (k==1) printf("%I64d\n",tmp);
		else
		{
			long long ans=0,count=1,j=k;
			for (int i=1;;)
			{
				long long r=i+j-1;
				if (r>=n) r=n-1;
				ans+=(s[i]-s[r+1])*count;
				if (r==n-1) break;
				count++;
				i=r+1;
				j=j*k;
			}
			printf("%I64d ",ans);
		}
	}
	printf("\n");
	return 0;
}