#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
const int N = 2e6 + 1;

int m[N][2], a[N], x[N], sz;
vector <pair<int, int> > v, v0, v1;
char c[N];

void recalc(int v) {
    for (int i = 0; i < 2; ++i)
        m[v][i] = m[2*v + 2][m[2*v + 1][i]];
}

void als(int i, int from, int to) {
    i = i + sz - 2;
    m[i][from] = to;
    while (i > 0) {
        i = (i - 1) / 2;
        recalc(i);
    }
}
int main() {
    int i, j, k, n;
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> k;
    for (i = 0; i < n; ++i) {
        cin >> a[i];
        v.push_back({abs(a[i]), i});
    }
    sz = 1;
    while (sz < k) sz *= 2;
    for (i = 0; i <= 2 * sz; ++i) {
        m[i][0] = 0;
        m[i][1] = 1;
    }
    for (i = 1; i <= k; ++i) {
        cin >> c[i] >> x[i];
        if (c[i] == '>') {
            v0.push_back({x[i], i});
            if (0 > x[i]) {
                als(i, 0, 1);
                als(i, 1, 0);
            } else {
                als(i, 0, 0);
                als(i, 1, 1);
            }
        } else {
            v1.push_back({x[i], i});
            if (0 < x[i]) {
                als(i, 0, 1);
                als(i, 1, 0);
            } else {
                als(i, 0, 0);
                als(i, 1, 1);
            }
        }
    }
    sort(v.begin(), v.end());
    sort(v0.begin(), v0.end());
    sort(v1.begin(), v1.end());
    int uk00 = 0, uk01 = v0.size() - 1, uk10 = 0, uk11 = v1.size() - 1;
    for (i = 0; i < v.size(); ++i) {
        while (uk00 < v0.size() && v[i].fi > v0[uk00].fi) {
            als(v0[uk00].se, 0, 1);
            ++uk00;
        }
        while (uk01 >= 0 && -v[i].fi <= v0[uk01].fi) {
            als(v0[uk01].se, 1, 1);
            --uk01;
        }
        while (uk10 < v1.size() && v[i].fi >= v1[uk10].fi) {
            als(v1[uk10].se, 0, 0);
            ++uk10;
        }
        while (uk11 >= 0 && -v[i].fi < v1[uk11].fi) {
            als(v1[uk11].se, 1, 0);
            --uk11;
        }
        int c;
        if (a[v[i].se] < 0)
            c = 1;
        else
            c = 0;
        if (m[0][c] != c)
            a[v[i].se] = -a[v[i].se];
    }
    for (i = 0; i < n; ++i)
        cout << a[i] << ' ';
}