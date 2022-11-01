#include <bits/stdc++.h>
using namespace std;

int n, a, c[100005], cnt;
map<int, int> hv;

int main()
{
	scanf("%d%d", &n, &a);
	for (int i = 0;i < n;i++) scanf("%d", c+i);
	for (int i = 0;i < n;i++)
		if (c[i] == a) cnt++;
		else if (hv[c[i]] < cnt) hv.erase(c[i]);
		else hv[c[i]]++;
	for (auto u: hv) if (u.second >= cnt)
	{
		printf("%d\n", u.first);
		return 0;
	}
	printf("-1\n");
	return 0;
}