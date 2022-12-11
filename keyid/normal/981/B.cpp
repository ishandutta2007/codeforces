#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair <int,int> pii;

#define fi first
#define sc second
#define mp make_pair
#define pb push_back

map <int,int> ms;

int main()
{
	int n;
	scanf("%d",&n);
	for (int i=0;i<n;i++)
	{
		int a,x;
		scanf("%d%d",&a,&x);
		ms[a]=x;
	}
	scanf("%d",&n);
	for (int i=0;i<n;i++)
	{
		int a,x;
		scanf("%d%d",&a,&x);
		ms[a]=max(ms[a],x);
	}
	LL ans=0;
	for (auto v:ms)
		ans+=v.sc;
	printf("%lld",ans);
	return 0;
}