#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair <int,int> pii;

#define fi first
#define sc second
#define mp make_pair

const int MAXN=100005;

pii ans[MAXN];

int main()
{
	#ifdef KeyID
		freopen("read.txt","r",stdin);
	#endif
	int n,q;
	deque <int> dq;
	scanf("%d%d",&n,&q);
	int mx=0;
	for (int i=0;i<n;i++)
	{
		int a;
		scanf("%d",&a);
		mx=max(mx,a);
		dq.push_back(a);
	}
	int m;
	for (m=0;;m++)
	{
		if (dq[0]==mx)
			break;
		ans[m].fi=dq.front();
		dq.pop_front();
		ans[m].sc=dq.front();
		dq.pop_front();
		int a=min(ans[m].fi,ans[m].sc),b=max(ans[m].fi,ans[m].sc);
		dq.push_front(b);
		dq.push_back(a);
	}
	while (q--)
	{
		LL x;
		scanf("%lld",&x);
		x--;
		if (x<m)
			printf("%d %d\n",ans[x].fi,ans[x].sc);
		else
			printf("%d %d\n",mx,dq[(x-m)%(n-1)+1]);
	}
	return 0;
}