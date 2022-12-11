#include <bits/stdc++.h>
using namespace std;

typedef pair <int,int> pii;

const int MAXN=100005;

int h[MAXN];

void solve()
{
	puts("YES");
	int n,m,x;
	scanf("%d%d%d",&n,&m,&x);
	priority_queue <pii,vector<pii>,greater<pii>> pq;
	for (int i=1;i<=m;i++)
		pq.push(make_pair(0,i));
	for (int i=1;i<=n;i++)
	{
		int h;
		scanf("%d",&h);
		pii t=pq.top();
		pq.pop();
		printf("%d ",t.second);
		pq.push(make_pair(t.first+h,t.second));
	}
	puts("");
}

int main()
{
#ifdef KeyID
	freopen("read.txt","r",stdin);
#endif
	int T;
	scanf("%d",&T);
	while (T--) solve();
	return 0;
}