#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define fi first
#define sc second
#define mp make_pair

typedef long long LL;

const int MAXN=100005;

struct city
{
	int a,c;
}p[MAXN];

int main()
{
#ifdef KeyID
	freopen("read.txt","r",stdin);
#endif
	int n;
	scanf("%d",&n);
	for (int i=0;i<n;i++)
		scanf("%d%d",&p[i].a,&p[i].c);
	sort(p,p+n,[](const city &x,const city &y) {
		return x.a<y.a;
	});
	LL ans=0;
	int h=p[0].a+p[0].c;
	for (int i=0;i<n;i++)
		ans+=p[i].c;
	for (int i=1;i<n;i++)
	{
		ans+=max(0,p[i].a-h);
		h=max(h,p[i].a+p[i].c);
	}
	printf("%lld\n",ans);
	return 0;
}