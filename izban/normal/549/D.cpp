#include <sstream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <string>
#include <cassert>
#include <ctime>
#include <map>
#include <math.h>
#include <cstdio>
#include <set>
#include <deque>
#include <memory.h>
#include <queue>

#pragma comment(linker, "/STACK:64000000")
typedef long long ll;

using namespace std;

const int MAXN = 128;

int n, m;

ll t[MAXN][MAXN];

ll get (int x, int y)
{
	ll result = 0;
	for (int i = x; i >= 0; i = (i & (i+1)) - 1)
		for (int j = y; j >= 0; j = (j & (j+1)) - 1)
			result += t[i][j];
	return result;
}

void inc (int x, int y, ll delta)
{
	for (int i = x; i < n; i = (i | (i+1)))
		for (int j = y; j < m; j = (j | (j+1)))
			t[i][j] += delta;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif

	while (cin >> n >> m) {
	//n = m = 100; {
		memset(t, 0, sizeof(t));
		vector<string> a(n);
		for (int i = 0; i < n; i++) cin >> a[i];
		//for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) if ((i + j) % 2) a[i] += 'W'; else a[i] += 'B';

		vector<vector<int> > b(n, vector<int>(m));
		for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) if (a[i][j] == 'W') b[i][j] = 1; else b[i][j] = -1;

		int ans = 0;
		for (int sum = n + m - 2; sum >= 0; sum--) {
			for (int i = 0; i < n; i++) {
				int j = sum - i;
				if (j < 0 || j >= m) continue;

				ll added = get(n - i - 1, m - j - 1);
				ll need = a[i][j] == 'W' ? 1 : -1;

				if (added != need) {
					ans++;
					inc(n - i - 1, m - j - 1, need - added);
				}
			}
		}
		cout << ans << endl;
	}

	return 0;
}