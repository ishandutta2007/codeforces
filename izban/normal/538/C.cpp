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

#pragma comment(linker, "/STACK:50000000")
typedef long long ll;

using namespace std;

const int maxn = -1;
const int inf = 1e9;


int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif

	//ios_base::sync_with_stdio(0);

    int n, m;
    while (scanf("%d%d", &n, &m) == 2) {
        vector<int> d(m), h(m);
        for (int i = 0; i < m; i++) scanf("%d%d", &d[i], &h[i]);

        int ans = 0;
        ans = max(ans, h[0] + (d[0] - 1));
        ans = max(ans, h[m - 1] + (n - d[m - 1]));
        bool ok = 1;
        for (int i = 1; i < m; i++) {
            if (abs(h[i] - h[i - 1]) > d[i] - d[i - 1]) {
                ok = 0;
            } else {
                ans = max(ans, max(h[i], h[i - 1]) + (d[i] - d[i - 1] - abs(h[i] - h[i - 1])) / 2);
            }
        }
        if (!ok) cout << "IMPOSSIBLE" << endl;
        else cout << ans << endl;
    }

	return 0;
}