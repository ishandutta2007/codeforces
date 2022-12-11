#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
#define rep1n(i, n) for (int i = 1; i <= (n); ++i)
#define repr(i, n) for (int i = (n) - 1; i >= 0; --i)
#define pb push_back
#define eb emplace_back
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define sz(a) (int)(a.size())
#define each(x, a) for (auto &x : a)
#define ar array
#define vec vector
#define f0r(i, a, b) for (int i = (a); i < (b); ++i)
#define range(i, n) rep(i, n)

using namespace std;

using ll = long long;
using ld = long double;
using str = string;
using pi = pair<int, int>;
using pl = pair<ll, ll>;

using vi = vector<int>;
using vl = vector<ll>;
using vpi = vector<pair<int, int>>;
using vvi = vector<vi>;

int Bit(int mask, int b) { return (mask >> b) & 1; }

template<class T>
bool ckmin(T &a, const T &b) {
    if (b < a) {
        a = b;
        return true;
    }
    return false;
}

template<class T>
bool ckmax(T &a, const T &b) {
    if (b > a) {
        a = b;
        return true;
    }
    return false;
}

void solve() {
    int n;
    cin >> n;
    vi p(n);
    rep(i, n) {
        cin >> p[i];
        p[i]--;
    }
    vi a(n);
    rep(i, n) {
        cin >> a[i];
    }
    vi c(n);
    rep(i, n) c[p[i]]++;
    int cnt = 0;
    rep(i, n) if (c[i] == 0) cnt++;
    int mx = *max_element(all(a));
    mx -= n;
    int k = mx / cnt;
    int LG = 1;
    while (1 << (LG - 1) < k) LG++;
    vvi up(n, vi(LG));
    rep(i, n) up[i][0] = p[i];
    for (int j = 1; j < LG; ++j) {
        rep(i, n) {
            up[i][j] = up[up[i][j - 1]][j - 1];
        }
    }
    vi have(n + 1, -1);
    set<int> emp;
    rep(i, n) {
        if (a[i] <= n) {
            have[a[i]] = 1;
        }
    }
    for (int i = n; i >= 1; --i) {
        if (have[i] == -1) emp.insert(i);
    }
    rep(i, n) {
        int v = i;
        rep(j, LG) {
            if ((1 << j) & k) v = up[v][j];
        }
        int val = a[v];
        assert(val <= n && 1 <= val);
        if (have[val] == 1) {
            have[val] = 0;
            cout << val << ' ';
        } else {
            int x = *emp.lower_bound(val);
            emp.erase(x);
            cout << x << ' ';
        }
    }
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // cout << setprecision(20 - 7) << fixed;
    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}