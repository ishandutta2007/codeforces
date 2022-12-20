#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 1;
int s[4*N], m[4*N], pr[4*N], suf[4*N], v;
vector <int> e[N];

void recalc(int u) {
    s[u] = s[2*u + 1] + s[2*u + 2];
    m[u] = max(suf[2*u + 1] + pr[2*u + 2], max(m[2*u + 1], m[2*u + 2]));
    pr[u] = max(pr[2*u + 1], s[2*u + 1] + pr[2*u + 2]);
    suf[u] = max(suf[2*u + 2], s[2*u + 2] + suf[2*u + 1]);
}

void als(int i, int j) {
    i = i + v - 2;
    m[i] = j;
    s[i] = j;
    pr[i] = max(0, j);
    suf[i] = max(0, j);
    while (i > 0) {
        i = (i - 1) / 2;
        recalc(i);
    }
}

int main() {
    int i, j, n, k;
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> k;
    for (i = 1; i <= n; ++i) {
        cin >> j;
        e[j].push_back(i);
    }
    int sum = e[k].size(), ans = e[k].size();
    v = 1;
    while (v < n) v *= 2;
    for (i = 0; i < e[k].size(); ++i)
        als(e[k][i], -1);
    for (i = 1; i < N; ++i)
    if (i != k) {
        for (j = 0; j < e[i].size(); ++j)
            als(e[i][j], 1);
        ans = max(ans, sum + m[0]);
        for (j = 0; j < e[i].size(); ++j)
            als(e[i][j], 0);
    }
    cout << ans;
}