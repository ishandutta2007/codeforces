#include <bits/stdc++.h>
using namespace std;

const int dx[] = {-1, -1, -1, 0, 1, 1, 1, 0};
const int dy[] = {-1, 0, 1, 1, 1, 0, -1, -1};
set<pair<int, int> > ans;
int n, a[32];

void rec(int dep, int x, int y, int d)
{
	if (dep == n)
	{
		ans.insert(make_pair(x, y));
		return;
	}
	int X = x+a[dep]*dx[d], Y = y+a[dep]*dy[d];
	rec(dep+1, X, Y, (d+1)&7);
	set<pair<int, int> > nxt;
	for (auto u: ans)
	{
		nxt.insert(u);
		nxt.insert(make_pair(-(u.second-Y)+X, (u.first-X)+Y));
	}
	for (int i = 1;i <= a[dep];i++) nxt.insert(make_pair(x+i*dx[d], y+i*dy[d]));
	ans = nxt;
}

int main()
{
	scanf("%d", &n);
	for (int i = 0;i < n;i++) scanf("%d", a+i);
	rec(0, 0, 0, 1);
	printf("%d\n", ans.size());
	return 0;
}