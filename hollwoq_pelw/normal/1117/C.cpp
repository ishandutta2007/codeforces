#include <bits/stdc++.h>

#define uint unsigned int
#define ll long long
#define ull unsigned long long
#define ld long double
#define rep(i, l, r) for (int i = l; i < r; i++)
#define repb(i, r, l) for (int i = r; i > l; i--)
#define sz(a) (int)a.size()
#define fi first
#define se second
#define mp(a, b) make_pair(a, b)

using namespace std;

inline void setmin(int &x, int y) { if (y < x) x = y; }
inline void setmax(int &x, int y) { if (y > x) x = y; }
inline void setmin(ll &x, ll y) { if (y < x) x = y; }
inline void setmax(ll &x, ll y) { if (y > x) x = y; }

const int N = 100000;
const int inf = (int)1e9 + 1;
const ll big = (ll)1e18 + 1;
const int P = 239;
const int P1 = 31;
const int P2 = 57;
const int MOD = (int)1e9 + 7;
const int MOD1 = (int)1e9 + 9;
const int MOD2 = 998244353;
const double eps = 1e-9;
const double pi = atan2(0, -1);
const int ABC = 26;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.precision(20);
    cout << fixed;
    ll x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    int n;
    cin >> n;
    string s;
    cin >> s;
    pair<int, int> pref[n + 1];
    pref[0] = {0, 0};
    rep(i, 0, n) {
        if (s[i] == 'U') {
            pref[i + 1] = {0, 1};
        } else if (s[i] == 'D') {
            pref[i + 1] = {0, -1};
        } else if (s[i] == 'R') {
            pref[i + 1] = {1, 0};
        } else {
            pref[i + 1] = {-1, 0};
        }
        pref[i + 1].fi += pref[i].fi;
        pref[i + 1].se += pref[i].se;
    }
    ll l = 0, r = big, mid;
    while (r - l > 1) {
        mid = (l + r) / 2;
        ll x = x1 + pref[n].fi * (mid / n) + pref[mid % n].fi;
        ll y = y1 + pref[n].se * (mid / n) + pref[mid % n].se;
        if (abs(x - x2) + abs(y - y2) <= mid) {
            r = mid;
        } else {
            l = mid;
        }
    }
    if (r != big) {
        cout << r << "\n";
    } else {
        cout << -1 << "\n";
    }
    return 0;
}