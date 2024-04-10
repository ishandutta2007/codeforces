#include <functional>
#include <algorithm>
#include <iostream>
#include <numeric>
#include <cassert>
#include <cstdlib>
#include <string>
#include <cstdio>
#include <vector>
#include <ctime>
#include <queue>
#include <set>
#include <map>
using namespace std;
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define fore(i, b, e) for (int i = (int)(b); i <= (int)(e); ++i)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; --i)
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long long i64;
typedef unsigned long long u64;
const int inf = 1e9+100500;
const int K = 35;
const int L = 60;

// #warning maxn
const int maxn = 100500;

int n;
int a[maxn];
char nn[maxn/K+10][64];

int get(int l, int r) {
    int t = 0;
    int rb = (l%K == 0) ? l : ((l/K)*K+K);
    while (l != rb && l != r) {
        if (t%a[l] == 0) ++t;
        ++t, ++l;
    }
    if (l == r) return t;
    assert(l%K == 0);
    int b = l/K;
    int rbl = r/K;
    assert(b <= rbl);
    while (b != rbl) {
        t = t + K + nn[b][t%60];
        ++b;
    }
    l = b * K;
    while (l != r) {
        if (t%a[l] == 0) ++t;
        ++t, ++l;
    }
    return t;
}

void update(int i, int x) {
    a[i] = x;
    int b = i/K;
    int l = b*K, r = l+K;
    if (r >= n) return;

    forn(s, 60) {
        int t = s;
        int j = l;
        while (j != r) {
            if (t%a[j] == 0) ++t;
            ++t, ++j;
        }
        nn[b][s] = t-K-s;
    }
}

void scan() {
    scanf("%d", &n);
    forn(i, n) {
        scanf("%d", &a[i]);
//         a[i] = rand()%5 + 2;
    }
    ++n;
    a[n-1] = 1;
    forn(i, n) if (i%K == 0) {
        update(i, a[i]);
    }
}

void solve() {
    int m;
    scanf("%d", &m);
    char t[5];
    int a, b;
//     i64 s = 0;
    forn(i, m) {
        scanf("%s %d %d", t, &a, &b);
        if (t[0] == 'A') {
//         if (rand()%2) {
            printf("%d\n", get(a-1, b-1));
//             int l = rand()%n, r = rand()%n;
//             s += get(min(l, r), max(l, r));
        } else {
            update(a-1, b);
//             update(rand()%n, rand()%5 + 2);
        }
    }
//     cout << s << endl;
}


int main() {
#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif

    scan();
    solve();

#ifdef HOME
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}