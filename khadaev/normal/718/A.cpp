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
    int n, t;
    cin >> n >> t;
    string s;
    cin >> s;
    vector<char> ss(n - 1);
    int pos, j = 0;
    forn(i, 0, n) {
        if (s[i] == '.') pos = i;
        else {
            ss[j] = s[i];
            ++j;
        }
    }
    vector<int> opt(n - 1);
    opt[n - 2] = INF;
    ford(i, pos - 1, n - 2) {
        if (ss[i + 1] >= '5') opt[i] = 1;
        else if (ss[i + 1] == '4') opt[i] = opt[i + 1] + 1;
        else opt[i] = INF;
    }
    forn(i, pos - 1, n - 1) if (opt[i] <= t) {
        j = i;
        while (j >= 0 && ss[j] == '9') {
            ss[j] = '0';
            --j;
        }
        if (j >= 0) ++ss[j];
        else cout << 1;
        forn(k, 0, pos) cout << ss[k];
        if (i != pos - 1) {
            cout << '.';
            fore(k, pos, i) cout << ss[k];
        }
        return 0;
    }
    cout << s << '\n';
    return 0;
}