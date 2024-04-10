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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int m;
    cin >> m;
    string s;
    cin >> s;
    int n = s.length();
    forn(i, 0, 26) {
        //cerr << '\n';
        bool ok = true;
        vector<char> get(n);
        forn(j, 0, n) if (s[j] < 'a' + i) get[j] = 1;
        int prev = -1, dist = 0;
        forn(j, 0, n) {
            ++dist;
            if (get[j]) {
                prev = -1;
                dist = 0;
            } else if (s[j] == 'a' + i) {
                prev = j;
            }
            //cerr << dist << '\n';
            if (dist == m) {
                if (prev == -1) {
                    ok = false;
                    break;
                }
                get[prev] = 1;
                dist = j - prev;
                prev = -1;
                //cerr << j <<' ' << prev << '\n';
                //cerr << "NEW: " << dist << '\n';
                if (dist >= m) {
                    ok = false;
                    break;
                }
            }
        }
        if (!ok) continue;
        int x[26];
        forn(j, 0, 26) x[j] = 0;
        forn(j, 0, n) if (get[j]) x[s[j] - 'a']++;
        forn(j, 0, 26) forn(k, 0, x[j]) cout << char('a' + j);
        return 0;
    }
}