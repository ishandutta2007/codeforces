#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <unordered_map>
#include <set>
#include <iostream>
#include <cstring>
#include <bitset>
#include <ctime>
#include <functional>
#include <numeric>

typedef int64_t LL;
typedef uint64_t uLL;
typedef __int128_t sLL;
#define fir first
#define sec second
#define eb emplace_back
#define em emplace
#define pb pop_back
#define pii std::pair<int, int>
#define mkp(a, b) std::make_pair(a, b)
#define bitcount(x) __builtin_popcount(x)
#define bitcountll(x) __builtin_popcountll(x)

int read() {
    int s = 0, w = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9') {
        if (ch == '-')
            w = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') s = s * 10 + ch - '0', ch = getchar();
    return s * w;
}

LL readl() {
    LL s = 0, w = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9') {
        if (ch == '-')
            w = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') s = s * 10 + ch - '0', ch = getchar();
    return s * w;
}

///////////////////////////////////// wanna become a grandmaster

// #include <ext/pb_ds/tree_policy.hpp>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/hash_policy.hpp>
// using namespace __gnu_pbds;
// using rbtree = tree<int, null_type, std::less<int>, rb_tree_tag, tree_order_statistics_node_update> ;
// order_of_key() rank (return int) start from 0
// find_by_order() kth (return iterator) start from 0

const int maxn = 1e5 + 10;

struct Edge {
    int u, v, w;
};

int n, m, q;
Edge e[maxn];
int f[30][maxn];
int f2[30][maxn];
int can[30][maxn];

int ufind(int *f, int x) {
    return x == f[x] ? x : f[x] = ufind(f, f[x]);
}

int main() {
    n = read();
    m = read();
    for (int i = 1 ; i <= m ; i++ ) {
        e[i].u = read();
        e[i].v = read();
        e[i].w = read();
    }
    for (int i = 0 ; i < 30 ; i++ ) {
        for (int j = 1 ; j <= n ; j++ ) {
            f[i][j] = j;
            f2[i][j] = j;
        }
    }
    for (int i = 1 ; i <= m ; i++ ) {
        for (int j = 0 ; j < 30 ; j++ ) {
            if (e[i].w & (1 << j)) {
                int fu = ufind(f[j], e[i].u);
                int fv = ufind(f[j], e[i].v);
                if (fu != fv) {
                    f[j][fu] = fv;
                }
            }
        }
    }
    for (int i = 1 ; i <= m ; i++ ) {
        if (e[i].w & 1) {
            for (int j = 1 ; j < 30 ; j++ ) {
                if (e[i].w & (1 << j)) {
                    int fu = ufind(f2[j], e[i].u);
                    int fv = ufind(f2[j], e[i].v);
                    // printf("merge %d %d at %d\n", e[i].u, e[i].v, j);
                    if (fu != fv) {
                        f2[j][fu] = fv;
                    }
                }
            }
        }
    }
    for (int i = 1 ; i <= m ; i++ ) {
        if (e[i].w % 2 == 0) {
            for (int j = 0 ; j < 30 ; j++ ) {
                int fu = ufind(f2[j], e[i].u);
                int fv = ufind(f2[j], e[i].v);
                // printf("j = %d, f2 = %d, u = %d, v = %d, fu = %d, fv = %d\n", j, ufind(f2[j], 2), e[i].u, e[i].v, fu, fv);
                can[j][fu] = 1;
                can[j][fv] = 1;
            }
        }
    }
    q = read();
    while (q-- ) {
        int u = read(), v = read();
        bool ok = false;
        for (int i = 0 ; i < 30 ; i++ ) {
            if (ufind(f[i], u) == ufind(f[i], v)) {
                ok = true;
                break;
            }
        }
        if (ok) {
            printf("0\n");
            continue;
        }
        int cnt = 0;
        for (int i = 0 ; i < 30 ; i++ ) {
            cnt += can[i][ufind(f2[i], u)];
        }
        printf("%d\n", cnt ? 1 : 2);
    }
    return 0;
}