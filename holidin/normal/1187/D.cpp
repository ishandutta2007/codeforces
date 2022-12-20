#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 1;

int m[4*N], a[N], b[N], v = 0, p[N];
vector <int> v1[N], v2[N];

void als(int i, int j) {
    i += v - 2;
    m[i] = j;
    while (i > 0) {
        i = (i - 1) / 2;
        m[i] = max(m[2*i + 1], m[2*i + 2]);
    }
}

int mx(int v, int vl, int vr, int l, int r) {
    if (l <= vl && vr <= r)
        return m[v];
    else if (l >= vr || vl >= r)
            return 0;
        else
            return max(mx(2*v + 1, vl, (vl + vr) / 2, l, r), mx(2*v + 2, (vl + vr) / 2, vr, l, r));
}

bool stup_ans(int n) {
    int i, j, k;
    for (i = 1; i <= n; ++i) {
        if (v1[i].size() != v2[i].size())
            return 0;
        for (j = 0; j < v1[i].size(); ++j)
            p[v1[i][j]] = v2[i][j];
    }
    for (i = 1; i <= n; ++i)
    for (j = i + 1; j <= n; ++j)
    if (a[i] < a[j] && p[i] > p[j])
        return 0;
    return 1;
}

int main() {
    int i, j, k, n, test;
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> test;
    for (int h = 0; h < test; ++h) {
        cin >> n;
        for (i = 1; i <= n; ++i) {
            cin >> a[i];
            v1[a[i]].push_back(i);
        }
        for (i = 1; i <= n; ++i) {
            cin >> b[i];
            v2[b[i]].push_back(i);
        }
        v = 1;
        while (v < n)
            v *= 2;
        bool flag = 0;
        for (i = 1; i <= n; ++i) {
            if (v1[i].size() != v2[i].size()) {
                flag = 1;
                break;
            }
            for (j = 0; j < v1[i].size(); ++j)
                p[v1[i][j]] = v2[i][j];
        }
        for (i = 1; i <= n; ++i)
        if (!flag) {
            for (j = 0; j < v1[i].size(); ++j)
            if (mx(0, 1, v + 1, 1, v1[i][j]) > v2[i][j])
                flag = 1;
            for (j = 0; j < v1[i].size(); ++j)
                als(v1[i][j], v2[i][j]);

        }
        if (flag)
            cout << "NO\n";
        else
            cout << "YES\n";
        for (i = 1; i <= n; ++i) {
            v1[i].clear();
            v2[i].clear();
        }
        for (i = 0; i < 2 * v; ++i)
            m[i] = 0;
    }

}