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

const int maxn = 2e5 + 10;

int n;
int a[maxn];
int ans[maxn];

int main() {
    int T = read();
    while (T-- ) {
        n = read();
        LL sum = 0;
        for (int i = 1 ; i <= n ; i++ ) {
            a[i] = read();
            sum += a[i];
        }
        int pre = sum / n;
        std::vector<int> vec;
        for (int i = n ; i >= 1 ; i-- ) {
            if (pre) {
                // printf("pre = %d\n", pre);
                int num = 1;
                int z = i - pre;
                int ned = i - z;
                if (vec.size() >= ned) {
                    int lens = vec.size();
                    num += vec[lens - ned] - i - 1;
                } else {
                    num += n - i;
                }
                // printf("num = %d\n", num);
                if (num + i - 1 == a[i]) {
                    ans[i] = 1;
                    --pre;
                } else {
                    ans[i] = 0;
                    vec.eb(i);
                }
            } else {
                ans[i] = 0;
            }
        }
        for (int i = 1 ; i <= n ; i++ ) {
            printf("%d%c", ans[i], " \n" [i == n]);
        }
    }
    return 0;
}