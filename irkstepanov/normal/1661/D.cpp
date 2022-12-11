#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

struct node {
    ll a0;
    ll d;
    node() : a0(0), d(0) {}
};

vector<node> t;

void push(int v, int l, int r) {
    int m = (l + r) >> 1;
    ll a0 = t[v].a0, d = t[v].d;
    t[v].a0 = 0, t[v].d = 0;
    t[v * 2].a0 += a0, t[v * 2].d += d;
    t[v * 2 + 1].a0 += a0 + d * (m - l + 1), t[v * 2 + 1].d += d;
}

ll get(int v, int tl, int tr, int pos) {
    if (tl == tr) {
        return t[v].a0;
    }
    push(v, tl, tr);
    int tm = (tl + tr) >> 1;
    if (pos <= tm) {
        return get(v * 2, tl, tm, pos);
    } else {
        return get(v * 2 + 1, tm + 1, tr, pos);
    }
}

void update(int v, int tl, int tr, int l, int r, ll a0, ll d) {
    if (tl == l && tr == r) {
        t[v].a0 += a0;
        t[v].d += d;
        return;
    }
    push(v, tl, tr);
    int tm = (tl + tr) >> 1;
    if (l <= tm) {
        update(v * 2, tl, tm, l, min(r, tm), a0, d);
        a0 += d * (tm - l + 1);
    }
    if (r > tm) {
        update(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r, a0, d);
    }
}

void build(int v, int tl, int tr, vector<ll>& b) {
    if (tl == tr) {
        t[v].a0 = b[tl];
        t[v].d = 0;
        return;
    }
    int tm = (tl + tr) >> 1;
    build(v * 2, tl, tm, b);
    build(v * 2 + 1, tm + 1, tr, b);
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    //ifstream cin("input.txt");
    //freopen("input.txt", "r", stdin);
    //ofstream cout("output.txt");

    int n, k;
    cin >> n >> k;

    vector<ll> b(n);
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }
    t.resize(4 * n);
    build(1, 0, n - 1, b);

    ll ans = 0;
    for (int i = n - 1; i >= k - 1; --i) {
        ll val = get(1, 0, n - 1, i);
        if (val <= 0) {
            continue;
        }
        ll cnt = (val + k - 1) / k;
        update(1, 0, n - 1, i - k + 1, i, -cnt, -cnt);
        ans += cnt;
    }

    for (int i = k - 2; i >= 0; --i) {
        ll val = get(1, 0, n - 1, i);
        if (val <= 0) {
            continue;
        }
        ll cnt = (val + (i + 1) - 1) / (i + 1);
        update(1, 0, n - 1, 0, i, -cnt, -cnt);
        ans += cnt;
    }
    cout << ans << "\n";

}