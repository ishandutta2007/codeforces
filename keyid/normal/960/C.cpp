#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair <int,int> pii;

#define fi first
#define sc second
#define mp make_pair
#define pb push_back

vector <LL> ans;

int main()
{
	int x,d;
	scanf("%d%d",&x,&d);
	d+=1000000000;
	LL now=1;
	while (x)
	{
		int k=1;
		while ((1<<k)-1<=x) k++;
		k--;
		x-=(1<<k)-1;
		for (int i=0;i<k;i++)
			ans.pb(now);
		now+=d;
	}
	printf("%u\n",ans.size());
	for (LL v:ans)
		printf("%lld ",v);
	return 0;
}