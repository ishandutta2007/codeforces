#include <cstdio>
#include <list>
#include <algorithm>

using namespace std;

int a[200];
int ans;
int k;
int n;

int main()
{
	ans = -2000000;
	scanf("%d%d", &n, &k);
	for (int i = 0;i < n;i++)
		scanf("%d", a+i);
	for (int i = 0;i < n;i++) for (int j = i+1;j <= n;j++)
	{
		list<int> x, y;
		for (int o = i;o < j;o++)
			x.push_back(a[o]);
		for (int o = 0;o < i;o++)
			y.push_back(a[o]);
		for (int o = j;o < n;o++)
			y.push_back(a[o]);
		x.sort(); y.sort();
		int q = min((int) min(x.size(), y.size()), k);
		for (int o = 0;o < q;o++) if (y.back() > x.front())
		{
			x.pop_front(); x.push_back(y.back());
			y.pop_back();
		}
		int tmp = 0;
		for (list<int>::iterator o = x.begin();o != x.end();o++)
			tmp += (*o);
		if (tmp > ans)
			ans = tmp;
	}
	printf("%d\n", ans);
	return 0;
}