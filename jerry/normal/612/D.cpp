#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int> > ans;
pair<int, int> seg[2000005];
int n, k;

int main()
{
	scanf("%d%d", &n, &k);
	for (int i = 0;i < n;i++) scanf("%d%d", &seg[i*2].first, &seg[i*2+1].first), seg[i*2+1].second = 1;
	sort(seg, seg+2*n);
	for (int i = 0, j = 0;i < 2*n;i++)
		if (seg[i].second == 0 && ++j == k)
			ans.emplace_back(seg[i].first, -1);
		else if (seg[i].second == 1 && j-- == k)
			ans.back().second = seg[i].first;
	printf("%d\n", ans.size());
	for (auto u: ans) printf("%d %d\n", u.first, u.second);
	return 0;
}