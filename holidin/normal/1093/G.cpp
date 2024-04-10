#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 1;
const int K = 10;

vector <int> h[N];
multiset <int> s[32];
int t[N], n, k, v;
int m[32][4*N];

void als(int s, int i, int j) {
    i = i + v - 2;
    m[s][i] = j;
    while (i > 0) {
        i = (i - 1) / 2;
        m[s][i] = max(m[s][2*i + 1], m[s][2*i + 2]);
    }
}

int mx(int s, int v, int vl, int vr, int l, int r) {
    if (l <= vl && vr <= r)
        return m[s][v];
    else if (l >= vr || vl >= r)
            return -1e9;
        else
            return max(mx(s, 2*v + 1, vl, (vl + vr) / 2, l, r), mx(s, 2*v + 2, (vl + vr) / 2, vr, l, r));
}

void add(vector <int> v, int p) {
    for (int i = 0; i < t[k]; ++i) {
        int x = 0;
        for (int j = 0; j < k; ++j)
        if ((t[j] & i) == 0)
            x += v[j];
        else
            x -= v[j];
        als(i, p, x);
    }
}

void er(vector <int> v) {
    for (int i = 0; i < t[k]; ++i) {
        int x = 0;
        for (int j = 0; j < k; ++j)
        if ((t[j] & i) == 0)
            x += v[j];
        else
            x -= v[j];
        s[i].erase(s[i].find(-x));
    }
}

int main() {
    int i, j, tp, x, q, l, r;
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> k;
    t[0] = 1;
    for (i = 1; i <= k; ++i)
        t[i] = t[i - 1] * 2;
    v = 1;
    while (v < n) v *= 2;
    for (i = 1; i <= n; ++i) {
        h[i].resize(k);
        for (j = 0; j < k; ++j)
            cin >> h[i][j];
        add(h[i], i);
    }
    cin >> q;
    for (i = 0; i < q; ++i) {
        cin >> tp;
        if (tp == 1) {
            cin >> x;
            for (j = 0; j < k; ++j)
                cin >> h[x][j];
            add(h[x], x);
        } else {
            cin >> l >> r;
            int ans = 0;
            for (j = 0; j < t[k] / 2; ++j)
                ans = max(ans, mx(j, 0, 1, v + 1, l, r + 1) + mx(t[k] - j - 1, 0, 1, v + 1, l, r + 1));
            cout << ans << "\n";
        }
    }
}