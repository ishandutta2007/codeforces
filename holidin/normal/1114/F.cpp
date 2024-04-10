#include <bits/stdc++.h>
using namespace std;
const int N = 2e6;
const int CF = 301;
const int LogN = 63;
const int mod = 1e9 + 7;

long long m[N], d[N], msk[N], dmsk[N];
bool b[CF];
long long msx[CF], t[LogN];
vector <int> v;
int vs;

long long bp(long long x, int st) {
    if (st == 0)
        return 1;
    else if (st % 2 == 0)
            return bp((x * x) % mod, st / 2) % mod;
        else
            return (bp((x * x) % mod, st / 2) * x) % mod;
}

void recalc(int v) {
    m[v] = (m[2*v + 1] * m[2*v + 2]) % mod;
    msk[v] = msk[2*v + 1] | msk[2*v + 2];
}

void push(int v, int vl, int vr) {
    if (dmsk[v] != 0) {
        long long f = bp(d[v], (vr - vl) / 2);
        m[2*v + 1] = (m[2*v + 1] * f) % mod;
        d[2*v + 1] = (d[2*v + 1] * d[v]) % mod;
        msk[2*v + 1] |= dmsk[v];
        dmsk[2*v + 1] |= dmsk[v];
        m[2*v + 2] = (m[2*v + 2] * f) % mod;
        d[2*v + 2] = (d[2*v + 2] * d[v]) % mod;
        msk[2*v + 2] |= dmsk[v];
        dmsk[2*v + 2] |= dmsk[v];
        d[v] = 1;
        dmsk[v] = 0;
    }
}

void add(int v, int vl, int vr, int l, int r, int x) {
    if (l <= vl && vr <= r) {
        m[v] = (m[v] * bp(x, vr - vl)) % mod;
        d[v] = (d[v] * x) % mod;
        msk[v] |= msx[x];
        dmsk[v] |= msx[x];
    } else if (l >= vr ||vl >= r)
            return;
        else {
            push(v, vl, vr);
            add(2*v + 1, vl, (vl + vr) / 2, l, r, x);
            add(2*v + 2, (vl + vr) / 2, vr, l, r, x);
            recalc(v);
        }
}

void cn(int v, int vl, int vr, int l, int r, long long &x, long long &mask) {
    if (l <= vl && vr <= r) {
        x = m[v];
        mask = msk[v];
    } else if (l >= vr || vl >= r)  {
            x = 1;
            mask = 0;
        } else {
            push(v, vl, vr);
            long long a, b, m1, m2;
            cn(2*v + 1, vl, (vl + vr) / 2, l, r, a, m1);
            cn(2*v + 2, (vl + vr) / 2, vr, l, r, b, m2);
            x = (a * b) % mod;
            mask = m1 | m2;
        }
}

long long ob[CF];

int main() {
    string s;
    int i, j, n, k, q, l, r, x;
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    for (i = 2; i < CF; ++i)
    if (!b[i]) {
        v.push_back(i);
        for (j = i; j < CF; j += i)
            b[j] = true;
    }
    t[0] = 1;
    for (i = 1; i < LogN; ++i)
        t[i] = t[i - 1] * 2;
    for (i = 1; i < CF; ++i)
    for (j = 0; j < v.size(); ++j)
    if (i % v[j] == 0)
        msx[i] += t[j];
    cin >> n >> q;
    vs = 1;
    while (vs < n) vs *= 2;
    for (i = 1; i <= n; ++i) {
        cin >> j;
        m[i + vs - 2] = j;
        msk[i + vs - 2] = msx[j];
    }
    for (i = 0; i < 2 * vs - 1; ++i)
        d[i] = 1;
    for (i = vs - 2; i >= 0; --i)
        recalc(i);
    for (i = 1; i < CF; ++i)
        ob[i] = bp(i, mod - 2);
    for (i = 0; i < q; ++i) {
        cin >> s;
        if (s == "MULTIPLY") {
            cin >> l >> r >> x;
            add(0, 1, vs + 1, l, r + 1, x);
        } else {
            cin >> l >> r;
            long long x, mask;
            cn(0, 1, vs + 1, l, r + 1, x, mask);
            for (j = 0; j < v.size(); ++j)
            if ((mask & t[j]) > 0)
                x = (((x * (long long) (v[j] - 1)) % mod) * ob[v[j]]) % mod;
            cout << x << "\n";
        }
    }
}