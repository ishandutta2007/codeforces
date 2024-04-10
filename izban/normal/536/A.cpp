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

    int A, B, n;
    while (scanf("%d%d%d", &A, &B, &n) == 3) {
        for (int i = 0; i < n; i++) {
            int l, t, m;
            scanf("%d%d%d", &l, &t, &m);

            int L = l - 1, R = 3e6;
            while (R - L > 1) {
                int X = (L + R) >> 1;
                bool ok = 0;

                int cnt = X - l + 1;
                ll all = 0;
                all += 1LL * cnt * A;
                all += 1LL * (l - 1) * B * cnt;
                all += 1LL * B * cnt * (cnt - 1) / 2;
                ll mx = A + 1LL * (X - 1) * B;
                if (mx * min(m, cnt) >= all) {
                    ok = mx <= t;
                } else {
                    ll need = all / m + !!(all % m);
                    ok = need <= t;
                }

                if (ok) L = X;
                else R = X;
            }
            int ans = L == l - 1 ? -1 : L;
            printf("%d\n", ans);
        }
    }

	return 0;
}