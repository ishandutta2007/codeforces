#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <string>
#include <vector>
#include <cstdio>
#include <cassert>

using namespace std;

typedef long long ll;
typedef long double ld;

#ifdef WIN32
	#define LLD "%I64d"
#else
	#define LLD "%lld"
#endif

const int maxn = 2005;

bool can[maxn];
int n, me;
int a[maxn];
int next[maxn];

int main()
{
	scanf("%d%d", &n, &me);
	me--;
	for (int i = 0; i < n; i++) next[i] = -1;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
		a[i]--;
		if (a[i] != -1)
		{
			next[a[i]] = i;
		}
	}
	for (int i = 0; i <= n; i++) can[i] = false;
	can[0] = true;
	int whme = -1;
	for (int i = 0; i < n; i++) if (a[i] == -1)
	{
		int cur = i;
		int cnt = 0;
		bool isme = false;
		while (cur != -1)
		{
			cnt++;
			if (cur == me)
			{
				isme = true;
				whme = cnt;
			}
			cur = next[cur];
		}
		if (isme) continue;
// 		cout << "from " << i << ' ' << cnt << endl;
		for (int j = n; j >= 0; j--) can[j + cnt] = can[j + cnt] || can[j];
	}
	assert(whme != -1);
	for (int i = 0; i <= n; i++) if (can[i]) printf("%d\n", i + whme);
	return 0;
}