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

const int maxn = 1 << 21;
const int inf = 1e9;

int n, q;
int a[maxn];

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif

	//ios_base::sync_with_stdio(0);
    while (scanf("%d%d", &n, &q) == 2) {
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
            a[i + n] = a[i];
        }
        /*for (int i = 0; i < 2 * n; i++) {
            sum[i] = a[i];
            if (i) sum[i] += a[i - 1];
        }
        sum[2 * n] = 8e8;*/

        for (int it = 0; it < q; it++) {
            ll b;
            cin >> b;

            int cans = 0;
            int l, r;
            for (l = 0; l < n; l++) {
                ll csum = 0;
                r = l;
                while (r < 2 * n && csum + a[r] <= b) {
                    csum += a[r++];
                }
                l = r - 1;
                cans++;
            }

            cans = 0;
            int l0 = l % n;
            for (l = l0; l - l0 < n; l++) {
                ll csum = 0;
                r = l;
                while (r < 2 * n && csum + a[r] <= b) {
                    csum += a[r++];
                }
                l = r - 1;
                cans++;
            }
            printf("%d\n", cans);
        }
    }


	return 0;
}