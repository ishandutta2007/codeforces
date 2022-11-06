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

const int LOG = 42;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> Pow(LOG), NotPow(LOG);
    forn(i, 0, n) {
        ll x;
        cin >> x;
        forn(j, 0, LOG) {
            if (x == (1ll << j)) {
                ++Pow[j];
                break;
            } else if (x < (1ll << j)) {
                ++NotPow[j];
                break;
            }
        }
    }
    forn(i, 0, LOG - 1) {
        if (Pow[i] < Pow[i + 1]) {
            NotPow[i + 1] += (Pow[i + 1] - Pow[i]);
            Pow[i + 1] = Pow[i];
        }
    }
    vector<int> ans;
    while (Pow[0]) {
        //trace(Pow);
        //trace(NotPow);
        vector<int> End(LOG);
        forn(i, 0, LOG - 1)
            End[i] = Pow[i] - Pow[i + 1];
        End[LOG - 1] = Pow[LOG - 1];
        //trace(End);
        int rest = NotPow[0];
        forn(i, 1, LOG) {
            rest += NotPow[i];
            rest -= End[i - 1];
            rest = max(rest, 0);
        }
        //cerr << rest << '\n';
        if (rest == 0) ans.eb(Pow[0]);
        forn(i, 0, LOG) {
            --Pow[i];
            ++NotPow[i];
            if (i < LOG - 1 && Pow[i] + 1 > Pow[i + 1]) break;
        }
    }
    reverse(all(ans));
    if (ans.empty()) cout << "-1\n";
    else {
        for (int i : ans) cout << i << ' ';
    }
}