#include <bits/stdc++.h>

#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
#define rep1n(i, n) for(int i = 1; i <= (n); ++i)
#define repr(i, n) for(int i = (n) - 1; i >= 0; --i)
#define pb push_back
#define eb emplace_back
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define sz(a) (int)(a.size())
#define each(x, a) for(auto &x : a)
#define ar array

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

template<class T> bool ckmin(T &a, const T &b) {
    if (b < a) {
        a = b;
        return true;
    }
    return false;
}

template<class T> bool ckmax(T &a, const T &b) {
    if (b > a) {
        a = b;
        return true;
    }
    return false;
}

const int mxN = 2e5;
const ll INF = 1e18;
const int md = 998244353;

void solve() {
    int n; cin >> n;
    vi a(n);
    each(x, a) cin >> x;
    vvi to(n + 1);
    rep(rot, 2) {
        vi lm(n, -1), rb(n, n);
        vi stk;
        rep(i, n) {
            while(!stk.empty() && a[stk.back()] > a[i]) stk.pop_back();
            if (!stk.empty()) lm[i] = stk.back();
            stk.push_back(i);
        }
        stk.clear();
        repr(i, n) {
            while(!stk.empty() && a[stk.back()] < a[i]) stk.pop_back();
            if (!stk.empty()) rb[i] = stk.back();
            stk.push_back(i);
        }
        rep(i, n) {
            if (rot) rb[i] = n - rb[i] - 1, lm[i] = n - lm[i] - 1, swap(rb[i], lm[i]);
            to[rb[i]].push_back(lm[i] + 1);
        }
        reverse(all(a));
    }
    ll res = 0;
    int l = 0;
    rep(r, n) {
        each(t, to[r]) ckmax(l, t);
        res += r - l + 1;
    }
    cout << res << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t = 1; cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}