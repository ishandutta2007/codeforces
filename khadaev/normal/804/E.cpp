#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;

#define forn(i, a, n) for (int i = a; i < n; ++i)
#define ford(i, a, n) for (int i = n - 1; i >= a; --i)
#define fore(i, a, n) for (int i = a; i <= n; ++i)
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

int p[1010];
set<pair<int, int>> d;

void out(int i, int j) {
    if (i > j) swap(i, j);
    swap(p[i], p[j]);
    /*if (d.count({i, j})) {
        cerr << "FAIL\n";
        exit(0);
    }
    d.emplace(i, j);*/
    printf("%d %d\n", i + 1, j + 1);
}

void solve4(int n) {
    printf("YES\n");
    /*vector<pair<int, int>> x(n / 4);
    forn(i, 0, n / 4) {
        x[i].fs = i;
        x[i].sn = n / 2 - 1 - i;
    }
    forn(i, 0, n / 4) {
        out_perm(n, x);
        add_one(n, x);
    }
    x[0].fs = 0;
    x[0].sn = n / 4;
    forn(i, 1, n / 4) {
        x[i].fs = i;
        x[i].sn = n / 2 - i;
    }
    forn(i, 0, n / 4) {
        out_perm(n, x);
        add_one(n, x);
    }*/
    forn(i, 0, n / 2)
        forn(j, 0, i) {
            out(i, j);
            out(i + n / 2, j + n / 2);
            out(i, j + n / 2);
            out(i + n / 2, j);
        }
}

int main() {
    int n;
    scanf("%d", &n);
    //forn(i, 0, n) p[i] = i;
    if (n % 4 == 0) {
        solve4(n);
        forn(i, 0, n / 2)
            out(i, i + n / 2);
    } else if (n % 4 == 1) {
        solve4(n - 1);
        forn(i, 0, n / 2) {
            out(n - 1, i);
            out(i, i + n / 2);
            out(i + n / 2, n - 1);
        }
    } else printf("NO\n");
    /*cerr << d.size() << '\n';
    cerr << n * (n - 1) / 2 << '\n';
    forn(i, 0, n) cerr << p[i] << ' ';*/
}