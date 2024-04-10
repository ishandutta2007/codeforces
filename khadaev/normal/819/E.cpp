#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;

#define forn(i, a, n) for (int i = (int)(a); i < (int)(n); ++i)
#define ford(i, a, n) for (int i = (int)(n - 1); i >= (int)(a); --i)
#define fore(i, a, n) for (int i = (int)(a); i <= (int)(n); ++i)
#define all(a) (a).begin(), (a).end()
#define fs first
#define sn second
#define trace(a)\
    for (auto i : a) cerr << i << ' ';\
    cerr << '\n'
#define eb emplace_back

#ifndef M_PI
const ld M_PI = acos(-1.0);
#endif

const ld eps = 1e-9;
const int INF = 2000000000;
const ll LINF = 1ll * INF * INF;
const ll MOD = 1000000007;

vector<vector<int>> ans;

void add(int a, int b, int c) {
    ans.eb(vector<int>{a, b, c});
}

void add(int a, int b, int c, int d) {
    ans.eb(vector<int>{a, b, c, d});
}

int main() {
    int n;
    scanf("%d", &n);
    int st;
    if (n % 2) {
        add(0, 1, 2);
        add(0, 1, 2);
        st = 3;
    } else {
        add(0, 1, 2);
        add(0, 1, 3);
        add(0, 2, 3);
        add(1, 2, 3);
        st = 4;
    }
    for (int i = st; i < n; i += 2) {
        forn(j, 0, i - 1) {
            add(i, j, i + 1, j + 1);
        }
        add(i, i + 1, 0);
        add(i, i + 1, i - 1);
    }
    printf("%d\n", (int)ans.size());
    for (auto p : ans) {
        printf("%d ", (int)p.size());
        for (int i : p) printf("%d ", 1 + i);
        printf("\n");
    }
}