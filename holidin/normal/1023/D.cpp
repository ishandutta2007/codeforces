#include <bits/stdc++.h>
using namespace std;
const int N = 1e6;

int i, j, n, k, p = 0, v, q;
int a[N], m[N], pr[N], b[N];

void als(int i, int j) {
    i = i + v - 2;
    m[i] = j;
    while (i > 0) {
        i = (i - 1) / 2;
        m[i] = min(m[2*i + 1], m[2*i + 2]);
    }
}

int mn(int v, int vl, int vr, int l, int r) {
    if (l <= vl && vr <= r)
        return m[v];
    else if (vl >= r || l >= vr)
            return 1e9;
        else
            return min(mn(2*v + 1, vl, (vl + vr)/2, l, r), mn(2*v + 2, (vl + vr)/ 2, vr, l, r));
}
set <int> s;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> q;
    for (i = 1; i <= n; ++i) {
        cin >> a[i];
        b[a[i]] = i;
    }
    if (b[q] == 0)
        s.insert(q);
    for (i = 1; i <= n; ++i)
    if (a[i] > 0) {
        s.insert(a[i]);
        if (b[a[i]] == i)
            s.erase(a[i]);
    } else if (s.size() == 0)
            a[i] = 1;
        else {
            set <int> :: iterator it = s.end();
            --it;
            a[i] = *it;
            if ((*it) == q && b[q] == 0) {
                s.erase(q);
                b[q] = 1;
            }
        }
    for (i = 1; i <= n; ++i)
        pr[i] = 0;
    v = 1;
    while (v < n) v *= 2;
    for (i = 1; i <= n; ++i)
        als(i, a[i]);
    bool can = true;
    for (i = 1; i <= n; ++i) {
        if (pr[a[i]] != 0)
            if (mn(0, 1, v + 1, pr[a[i]] + 1, i) < a[i])
                can = false;
        pr[a[i]] = i;
    }
    if (!can || b[q] == 0)
        cout << "NO";
    else {
        cout << "YES\n";
        for (i = 1; i <= n; ++i)
            cout << a[i] << ' ';
    }
}