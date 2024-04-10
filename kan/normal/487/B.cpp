#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <string>
#include <vector>
#include <cstdio>
#include <cassert>
#include <ctime>
#include <deque>

using namespace std;

typedef long long ll;
typedef long double ld;

#ifdef WIN32
	#define LLD "%I64d"
#else
	#define LLD "%lld"
#endif

const int maxn = 100005;
const int inf = 1e9;

int a[maxn], ans[maxn];
deque<pair<int, int>> stans, stmax, stmin;
int n, s, l;

int main()
{
	scanf("%d%d%d", &n, &s, &l);
	for (int i = 0; i < n; i++) scanf("%d", &a[i]);
	int left = -1;
	for (int i = 0; i < n; i++)
	{
		if (i + 1 >= l)
		{
			while (!stans.empty() && stans.back().second >= ans[i + 1 - l]) stans.pop_back();
			stans.push_back({i + 1 - l, ans[i + 1 - l]});
		}
		while (!stmax.empty() && stmax.front().second > a[i] + s)
		{
			left = max(left, stmax.front().first);
			stmax.pop_front();
		}
		while (!stmin.empty() && stmin.front().second < a[i] - s)
		{
			left = max(left, stmin.front().first);
			stmin.pop_front();
		}
		while (!stans.empty() && stans.front().first <= left) stans.pop_front();
		if (!stans.empty())
		{
			ans[i + 1] = stans.front().second + 1;
// 			cout << "from " << stans.front().first << endl;
		} else ans[i + 1] = inf;
// 		cout << i + 1 << ' ' << left << ' ' << ans[i + 1] << endl;
		while (!stmax.empty() && stmax.back().second <= a[i]) stmax.pop_back();
		stmax.push_back({i, a[i]});
		while (!stmin.empty() && stmin.back().second >= a[i]) stmin.pop_back();
		stmin.push_back({i, a[i]});
	}
	if (ans[n] >= inf) ans[n] = -1;
	cout << ans[n] << endl;
	return 0;
}