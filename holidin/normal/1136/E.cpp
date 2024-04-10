#include <bits/stdc++.h>
using namespace std;
const long long N = 2e5 + 1;

long long a[N], c[N], pr[N], sumk[2*N], m[2 * N], d[2 * N], v;
bool fpush[2 * N];

void recalc(long long v) {
    m[v] = m[2*v + 1] + m[2*v + 2];
}

void build(long long v, long long vl, long long vr) {
    sumk[v] = 0;
    for (long long i = vl; i < vr; ++i)
        sumk[v] += (long long) c[i] * (vr - i - 1);
    if (vl + 1 != vr) {
        build(2*v + 1, vl, (vl + vr) / 2);
        build(2*v + 2, (vl + vr) / 2, vr);
        recalc(v);
    } else
        m[v] = a[vl];
}

void push(long long v, long long vl, long long vr) {
    long long u = (vr + vl) / 2;
    if (fpush[v]) {
        fpush[2*v + 1] = 1;
        fpush[2*v + 2] = 1;
        d[2*v + 1] = d[v];
        d[2*v + 2] = d[v] + pr[u - 1] - pr[vl - 1];
        m[2*v + 1] = d[2*v + 1] * (u - vl) + sumk[2*v + 1];
        m[2*v + 2] = d[2*v + 2] * (vr - u) + sumk[2*v + 2];
        fpush[v] = 0;
    }
}

void als(long long v, long long vl, long long vr, long long l, long long r, long long x) {
    if (l <= vl && vr <= r) {
        fpush[v] = 1;
        d[v] = x + pr[vl - 1] - pr[l - 1];
        m[v] = sumk[v] + d[v] * (vr - vl);
    } else if (l >= vr || vl >= r)
            return;
        else {
            push(v, vl, vr);
            als(2*v + 1, vl, (vl + vr) / 2, l, r, x);
            als(2*v + 2, (vl + vr) / 2, vr, l, r, x);
            recalc(v);
        }
}

long long sum(long long v, long long vl, long long vr, long long l, long long r) {
    if (l <= vl && vr <= r)
        return m[v];
    else if (vl >= r || l >= vr)
            return 0;
        else {
            push(v, vl, vr);
            return sum(2*v + 1, vl, (vl + vr) / 2, l, r) + sum(2*v + 2, (vl + vr) / 2, vr, l, r);
        }
}



int main() {
    char tp;
    long long i, j, n, k, l, r, pos, x;
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for (i = 1; i <= n; ++i)
        cin >> a[i];
    for (i = 1; i < n; ++i) {
        cin >> c[i];
        pr[i] = pr[i - 1] + c[i];
    }
    v = 1;
    while (v < n) v *= 2;
    build(0, 1, v + 1);
    cin >> k;
    for (i = 0; i < k; ++i) {
        cin >> tp;
        if (tp == '+') {
            cin >> pos >> x;
            long long ff = sum(0, 1, v + 1, pos, pos + 1) + x;
            l = 0, r = n - pos + 1;
            while (r - l > 1) {
                long long mid = (l + r) / 2;
                if (sum(0, 1, v + 1, pos + mid, pos + mid + 1) < ff + pr[pos + mid - 1] - pr[pos - 1])
                    l = mid;
                else
                    r = mid;
            }
            als(0, 1, v + 1, pos, pos + r, ff);
        }
        if (tp == 's') {
            cin >> l >> r;
            cout << sum(0, 1, v + 1, l, r + 1) << "\n";
        }
    }
}