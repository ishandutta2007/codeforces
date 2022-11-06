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

void fail() {
    cout << "-1\n";
    exit(0);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> l(m);
    forn(i, 0, m) {
        cin >> l[i];
        --l[i];
    }
    vector<int> a(n, -1);
    forn(i, 1, m) {
        int val = (l[i] - l[i - 1]  + n - 1) % n + 1;
        if (a[l[i - 1]] != -1 && a[l[i - 1]] != val) fail();
        a[l[i - 1]] = val;
    }
    set<int> free;
    fore(i, 1, n) free.insert(i);
    forn(i, 0, n) {
        if (a[i] == -1) continue;
        if (free.count(a[i]) == 0) fail();
        free.erase(a[i]);
    }
    forn(i, 0, n) {
        if (a[i] != -1) continue;
        a[i] = *free.begin();
        free.erase(free.begin());
    }
    forn(i, 0, n) cout << a[i] << ' ';
}