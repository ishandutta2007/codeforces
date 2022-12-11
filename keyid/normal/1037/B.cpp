#include <bits/stdc++.h>
using namespace std;

#define fi first
#define sc second
#define mp make_pair
#define pb push_back

typedef long long LL;
typedef pair <int,int> pii;

const int MAXN=200005;

int a[MAXN];

int main()
{
	//freopen("read.txt","r",stdin);
	int n,s;
	scanf("%d%d",&n,&s);
	for (int i=0;i<n;i++)
		scanf("%d",&a[i]);
	sort(a,a+n);
	int k=n/2;
	LL ans=abs(a[k]-s);
	for (int i=0;i<k;i++)
		if (a[i]>s)
			ans+=a[i]-s;
	for (int i=k+1;i<n;i++)
		if (a[i]<s)
			ans+=s-a[i];
	printf("%lld",ans);
	return 0;
}