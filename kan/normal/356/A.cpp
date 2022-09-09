#include <iostream>
#include <cstdio>
#include <set>

using namespace std;

const int maxn = 300005;

int ans[maxn];
set<int> cur;
int n, m;

typedef set<int>::iterator siter;

int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) cur.insert(i);
	for (int i = 0; i < m; i++)
	{
		int l, r, x;
		scanf("%d%d%d", &l, &r, &x);
		l--, r--, x--;
		siter wh = cur.lower_bound(l);
		siter prev = wh;
		while (wh != cur.end() && *wh <= r)
		{
			if (*wh != x)
			{
//				cout << *wh << ' ' << x << endl;
				ans[*wh] = x;
			}
			wh++;
		}
		cur.erase(prev, wh);
		cur.insert(x);
		ans[x] = -1;
	}
	for (int i = 0; i < n; i++) printf("%d ", ans[i] + 1);
	printf("\n");
	return 0;
}