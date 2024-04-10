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
#include <queue>

using namespace std;

typedef long long ll;
typedef long double ld;

#ifdef WIN32
	#define LLD "%I64d"
#else
	#define LLD "%lld"
#endif

const int maxn = 205;
const ll inf = 1e18;

priority_queue<int> good;
priority_queue<int, vector<int>, greater<int> > bad;
int n, k;
int a[maxn];

int main()
{
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i++) scanf("%d", &a[i]);
	ll answer = -inf;
	for (int l = 0; l < n; l++)
	{
		for (int r = l; r < n; r++)
		{
			while (!bad.empty()) bad.pop();
			while (!good.empty()) good.pop();
			ll cursum = 0;
			for (int i = 0; i < n; i++)
			{
				if (i >= l && i <= r)
				{
					cursum += a[i];
					bad.push(a[i]);
				} else good.push(a[i]);
			}
			int curk = k;
			while (curk > 0 && !good.empty() && good.top() > bad.top())
			{
				cursum -= bad.top();
				cursum += good.top();
				bad.pop();
				bad.push(good.top());
				good.pop();
				curk--;
			}
			answer = max(answer, cursum);
		}
	}
	cout << answer << endl;
	return 0;
}