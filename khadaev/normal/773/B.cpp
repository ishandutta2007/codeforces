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

int rez(int cnt, int n) {
    fore(i, 1, 5) {
        if (cnt * (1 << i) > n)
            return i;
    }
    return 6;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> v(5), p(5);
    forn(i, 0, 5) cin >> v[i];
    forn(i, 0, 5) cin >> p[i];
    vector<int> cnt(5);
    forn(i, 0, 5) if (v[i] != -1) cnt[i]++;
    forn(i, 0, 5) if (p[i] != -1) cnt[i]++;
    forn(i, 2, n) {
        forn(j, 0, 5) {
            int x;
            cin >> x;
            if (x != -1) cnt[j]++;
        }
    }
    int _n = n;
    forn(q, 0, 33 * _n) {
        int rezv = 0;
        forn(i, 0, 5) if (v[i] != -1) {
            int x = rez(cnt[i], n);
            rezv += 500 * x - 2 * x * v[i];
        }
        int rezp = 0;
        forn(i, 0, 5) if (p[i] != -1) {
            int x = rez(cnt[i], n);
            rezp += 500 * x - 2 * x * p[i];
        }
        //cerr << rezv << ' ' << rezp << '\n';
        if (rezv > rezp) {
            cout << q << '\n';
            return 0;
        }
        ++n;
        forn(i, 0, 5) {
            if (v[i] != -1 && (v[i] < p[i] || p[i] == -1)) {
                //do nothing
            }
            if (p[i] != -1 && p[i] < v[i]) {
                ++cnt[i];
            }
        }
    }
    cout << "-1\n";
}