#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

struct query
{
	int x, y, i;
} qu[200005];
int n, m, a[200005];
vector<pii> sol;
int ans[200005];

int bit[200005];
void upd(int at) { for (;at<200005;at+=at&-at) bit[at]++; }
int slv(int at) { int ret = 0; for (;at;at-=at&-at) ret += bit[at]; return ret; }

int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 0;i < n;i++)
	{
		int x; scanf("%d", &x);
		a[x] = i;
	}
	for (int i = 1;i <= n;i++) for (int j = i;j <= n;j+=i)
		sol.emplace_back(min(a[i], a[j]), max(a[i], a[j]));
	for (int i = 0;i < m;i++)
	{
		scanf("%d%d", &qu[i].x, &qu[i].y);
		qu[i].x--, qu[i].y--;
		qu[i].i = i;
	}
	sort(sol.begin(), sol.end(), [](pii x, pii y) -> bool {
		if (x.second != y.second) return (x.second > y.second);
		return (x.first > y.first);
	});
	sort(qu, qu+m, [](query x, query y) -> bool {
		if (x.y != y.y) return (x.y < y.y);
		return (x.x < y.x);
	});
	for (int i = 0;i < m;i++)
	{
		while (!sol.empty() && sol.back().second <= qu[i].y)
		{
			upd(200003-sol.back().first);
			sol.pop_back();
		}
		ans[qu[i].i] = slv(200003-qu[i].x);
	}
	for (int i = 0;i < m;i++) printf("%d\n", ans[i]);
	return 0;
}