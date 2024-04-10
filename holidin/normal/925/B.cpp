#include <bits/stdc++.h>
using namespace std;
const int N = 1200000;
const long double e = 1e-10;

vector <pair<int, int> > v;
int m[N], d[N], ans[N], v1;

void push(int v) {
    if (d[v] != 0) {
        d[2*v + 1] += d[v];
        m[2*v + 1] += d[v];
        d[2*v + 2] += d[v];
        m[2*v + 2] += d[v];
        d[v] = 0;
    }
}

void recalc(int v) {
    if (m[2*v + 1] > m[2*v + 2]) {
        m[v] = m[2*v + 1];
        ans[v] = ans[2*v + 1];
    } else {
        m[v] = m[2*v + 2];
        ans[v] = ans[2*v + 2];
    }
}


void add(int v, int vl, int vr, int l, int r, int x) {
    if (l <= vl && vr <= r) {
        d[v] += x;
        m[v] += x;
    } else if (vl >= r || l >= vr)
            return;
        else {
            push(v);
            add(2*v + 1, vl, (vl + vr)/2, l, r, x);
            add(2*v + 2, (vl + vr)/2, vr, l, r, x);
            recalc(v);
        }
}

void build(int v, int vl, int vr) {
    if (vl == vr - 1) {
        m[v] = -(v - v1 + 2);
        ans[v] = (v - v1 + 2);
        d[v] = 0;
    } else {
        build(2*v + 1, vl, (vl + vr)/2);
        build(2*v + 2, (vl + vr)/2, vr);
        recalc(v);
    }

}

int main() {
    long double x1, x2;
    int n, cl, ck, u, i, j;
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> x1 >> x2;
    for (i = 0; i < n; ++i) {
        cin >> j;
        v.push_back({j, i + 1});
    }
    sort(v.begin(), v.end());
    v1 = 1;
    while (v1 < n) v1 *= 2;
    build(0, 1, v1 + 1);
    int l = 0, r = n;
    for (i = n; i > 0; --i) {
        while (l < v.size() && x1 / i > v[l].first + e) {
            int l1 = 1, r1 = n + 2;
            while (r1 - l1 > 1) {
                int xx = (l1 + r1) / 2 - 1;
                if (x2 / xx > v[l].first + e)
                    l1 = xx + 1;
                else
                    r1 = xx + 1;
            }
            ++l;
            add(0, 1, v1 + 1, l1, n + 1, 1);
        }
        while (r < v.size() && r - l <= i) {
            int l1 = 1, r1 = n + 2;
            while (r1 - l1 > 1) {
                int xx = (l1 + r1) / 2 - 1;
                if (x2 / xx > v[r].first + e)
                    l1 = xx + 1;
                else
                    r1 = xx + 1;
            }
            ++r;
            add(0, 1, v1 + 1, l1, n + 1, -1);
        }
        while (r - l > i) {
            --r;
            int l1 = 1, r1 = n + 2;
            while (r1 - l1 > 1) {
                int xx = (l1 + r1) / 2 - 1;
                if (x2 / xx > v[r].first + e)
                    l1 = xx + 1;
                else
                    r1 = xx + 1;
            }
            add(0, 1, v1 + 1, l1, n + 1, 1);
        }
        if (r - l >= i && m[0] >= 0) {
            cout << "Yes\n";
            cout << i << ' ' << ans[0] << "\n";
            for (j = l; j < r; ++j)
                cout << v[j].second << ' ';
            cout << endl;
            j = 0;
            int pt = ans[0];
            while (ans[0] > 0 && j < v.size()) {
                if ((j < l || j >= r) && v[j].first + e >= x2 / pt) {
                    --ans[0];
                    cout << v[j].second << ' ';
                }
                ++j;
            }
            return 0;
        }
    }
    cout << "No";
}