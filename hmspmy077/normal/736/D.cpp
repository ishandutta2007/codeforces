#include <algorithm>
#include <bitset>
#include <cassert>
#include <cstdio>
#include <cstring>
#include <climits>
//#include <vector>

const int N = 2000;
const int M = 500000;

using Bitset = std::bitset<N + N>;

int x[M], y[M];
Bitset a[N];

int main()
{
#ifdef LOCAL_JUDGE
    freopen("D.in", "r", stdin);
#endif
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; ++ i) {
        scanf("%d%d", x + i, y + i);
        x[i] --;
        y[i] --;
        a[x[i]].set(y[i]);
    }
    for (int i = 0; i < n; ++ i) {
        a[i].set(n + i);
    }
    for (int k = 0; k < n; ++ k) {
        int pivot = k;
        while (pivot < n && !a[pivot].test(k)) {
            pivot ++;
        }
        assert(pivot < n);
        std::swap(a[k], a[pivot]);
        for (int i = 0; i < n; ++ i) {
            if (i != k && a[i].test(k)) {
                a[i] ^= a[k];
            }
        }
    }
    // for (int i = 0; i < n; ++ i) {
    //     for (int j = 0; j < n + n; ++ j) {
    //         printf("%d", a[i].test(j));
    //     }
    //     puts("");
    // }
    for (int i = 0; i < m; ++ i) {
        puts(a[y[i]].test(n + x[i]) ? "NO" : "YES");
    }
}