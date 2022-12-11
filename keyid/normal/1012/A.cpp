#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair <int,int> pii;

#define fi first
#define sc second
#define mp make_pair
#define pb push_back

const int MAXN=100005;

int a[MAXN*2];

int main()
{
	int n;
	scanf("%d",&n);
	for (int i=0;i<n*2;i++)
		scanf("%d",&a[i]);
	sort(a,a+n*2);
	LL ans=(LL)(a[n-1]-a[0])*(a[2*n-1]-a[n]);
	for (int i=n;i+1<2*n;i++)
		ans=min(ans,(LL)(a[i]-a[i-n+1])*(a[2*n-1]-a[0]));
	printf("%lld",ans);
	return 0;
}