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

const int MAX = 20000;

void fail() {
    cout << "NO\n";
    exit(0);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    int x = 0;
    while (n--) {
        int d;
        string s;
        cin >> d >> s;
        if (s == "North") {
            x -= d;
            if (x < 0) fail();
        } else if (s == "South") {
            x += d;
            if (x > MAX) fail();
        } else {
            if (x == 0 || x == MAX) fail();
        }
    }
    if (x) fail();
    cout << "YES\n";
}