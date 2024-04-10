#include <bits/stdc++.h>
using namespace std;
const long long N = 2e6 + 1;
const long long mod = 1e9 + 7;

long long m[N], d[N], v, x[N];
string u[N];

void push(long long v, long long vl, long long vr) {
    if (d[v] != -1) {
        d[2*v + 1] = d[v];
        d[2*v + 2] = d[v];
        m[2*v + 1] = (d[v] * (vr - vl) / 2) % mod;
        m[2*v + 2] = (d[v] * (vr - vl) / 2) % mod;
        d[v] = -1;
    }
}

void recalc(long long v) {
    m[v] = m[2*v + 1] + m[2*v + 2];
}

long long sum(long long v, long long vl, long long vr, long long l, long long r) {
    if (l <= vl && vr <= r)
        return m[v];
    else if (vl >= r || l >= vr)
            return 0;
        else {
            push(v, vl, vr);
            return (sum(2*v + 1, vl, (vl + vr)/2, l, r) + sum(2*v + 2, (vl + vr)/2, vr, l, r)) % mod;
        }
}

void add(long long v, long long vl, long long vr, long long l, long long r, long long x) {
    if (l <= vl && vr <= r) {
        d[v] = x;
        m[v] = ((vr - vl) * x) % mod;
    } else if (vl >= r || l >= vr)
            return;
        else {
            push(v, vl, vr);
            add(2*v + 1, vl, (vl + vr)/ 2, l, r, x);
            add(2*v + 2, (vl + vr)/2, vr, l, r, x);
            recalc(v);
        }
}

vector <long long> a;

long long foun(long long y) {
    long long l = 0, r = a.size();
    while (r - l > 1) {
        long long x = (l + r) / 2;
        if (a[x] > y)
            r = x;
        else
            l = x;
    }
    return l + 1;
}

long long cnt_t(long long a) {
    return sum(0, 1, v + 1, a, a + 1);
}

set <long long> s;

int main() {
    long long i, j, n;
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    v = 1;
    for (i = 0; i < n; ++i) {
        cin >> u[i] >> x[i];
        s.insert(x[i]);
    }
    for (set <long long> :: iterator it = s.begin(); it != s.end(); ++it)
        a.push_back((*it));
    a.push_back(1e9);
    while (v < a.size()) v *= 2;
    s.clear();
    s.insert(1e9);
    add(0, 1, v + 1, a.size(), a.size() + 1, 1);
    for (i = 0; i < 2 * v; ++i)
        d[i] = -1;
    for (i = 0; i < n; ++i)
    if (u[i] == "ADD") {
        set <long long> :: iterator it = s.lower_bound(x[i] + 1);
        long long p = foun((*it));
        add(0, 1, v + 1, foun(x[i]), foun(x[i]) + 1, cnt_t(foun(x[i])) + cnt_t(p));
        s.insert(x[i]);
    } else {
        set <long long> :: iterator it = s.lower_bound(x[i] + 1);
        long long p = foun((*it));
        long long k = (cnt_t(p) + cnt_t(foun(x[i]))) % mod;
        add(0, 1, v + 1, 1, v + 1, 0);
        add(0, 1, v + 1, p, p + 1, k);
        s.erase(x[i]);
    }
    cout << m[0] % mod;
}