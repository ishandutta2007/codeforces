#include <bits/stdc++.h>
using namespace std;

multiset<int> all;
int n, s, f;
int a[200005];
int ans;

int main()
{
	scanf("%d%d", &n, &s); s--;
	for (int i = 0;i < n;i++) scanf("%d", a+i);
	if (a[s] != 0)
	{
		a[s] = 0;
		ans++;
	}
	sort(a, a+n);
	for (int i = 1;i < n;i++) if (a[i] == 0)
		a[i] = n;
	for (int i = 0;i < n;i++) all.insert(a[i]);
	for (int i = 0;i < n;i++)
	{
		if (all.empty()) break;
		if (all.find(i) != all.end()) continue;
		if (i > *all.rbegin()) break;
		ans++;
		all.erase(--all.end());
	}
	printf("%d\n", ans);
	return 0;
}