#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;


struct event {
    int x;
    int tp;
    int num;
    event(int x, int tp, int num) : x(x), tp(tp), num(num) {}
    bool operator < (const event& rhs) const {
        if (x != rhs.x) {
            return x < rhs.x;
        }
        if (tp != rhs.tp) {
            return tp < rhs.tp;
        }
        return num < rhs.num;
    }
};

const int mod = 1'000'000'007;

struct maxend {
    ll val;
    ll cnt;
    maxend(ll val, ll cnt) : val(val), cnt(cnt) {}
};

maxend max(maxend a, maxend b) {
    if (a.val == b.val) {
        return maxend(a.val, (a.cnt + b.cnt) % mod);
    } else if (a.val > b.val) {
        return a;
    } else {
        return b;
    }
}

maxend operator + (maxend a, ll b) {
    return maxend(a.val + b, a.cnt);
}

int main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<ll> a(n), b(n);
    ll maxa = 0;
    ll maxb = 0;
    for (int i = 0; i < n; ++i) {
        cin >> b[i] >> a[i];
        maxa = max(maxa, a[i]);
        maxb = max(maxb, b[i]);
    }
    vector<event> ev;
    for (int i = 0; i < n; ++i) {
        if (b[i] > maxa) {
            b[i] = maxb;
        }
        ev.emplace_back(a[i], 1, i);
        ev.emplace_back(b[i], -1, i);
    }
    sort(all(ev));
    maxend cur(0, 1);
    vector<maxend> mxe_seg(n, maxend(0, 1));
    for (int i = 0; i < ev.size(); ++i) {
        event e = ev[i];
        if (e.tp == -1) {
            cur = max(cur, mxe_seg[e.num]);
        } else {
            mxe_seg[e.num] = cur + (b[e.num] - a[e.num]);
        }
    }
    cout << cur.cnt << "\n";
}