#include <bits/stdc++.h>
using namespace std;
const int N = 2e6 + 1;

vector <int> v[N];

int t0[N], t1[N], top = 0, cnt[N], l[N], r[N], ans[N];
string s[N];

int uni(int a, int b) {
    if (v[a].size() < v[b].size())
        swap(a, b);
    for (int i = 0; i < v[b].size(); ++i)
        v[a].push_back(v[b][i]);
    return a;
}

void dfs(int u) {
    if (s[u] == "IN") {
        t0[u] = top + 1;
        t1[u] = top + 2;
        if (cnt[u] == 0)
            v[t1[u]].push_back(u);
        else
            v[t0[u]].push_back(u);
        top += 2;
        return;
    }
    if (s[u] == "NOT") {
        dfs(l[u]);
        t1[u] = t0[l[u]];
        t0[u] = t1[l[u]];
        cnt[u] = !cnt[l[u]];
        return;
    }
    if (s[u] == "AND") {
        dfs(l[u]);
        dfs(r[u]);
        cnt[u] = cnt[l[u]] & cnt[r[u]];
        if (cnt[l[u]] == 0) {
            t0[u] = uni(t0[r[u]], t1[r[u]]);
            ++top;
            t1[u] = top;
        } else {
            t0[u] = t0[r[u]];
            t1[u] = t1[r[u]];
        }
        if (cnt[r[u]] == 0)
            t0[u] = uni(t0[u], uni(t0[l[u]], t1[l[u]]));
        else {
            t0[u] = uni(t0[u], t0[l[u]]);
            t1[u] = uni(t1[u], t1[l[u]]);
        }
    }
    if (s[u] == "OR") {
        dfs(l[u]);
        dfs(r[u]);
        cnt[u] = cnt[l[u]] | cnt[r[u]];
        if (cnt[l[u]] == 1) {
            t1[u] = uni(t0[r[u]], t1[r[u]]);
            ++top;
            t0[u] = top;
        } else {
            t0[u] = t0[r[u]];
            t1[u] = t1[r[u]];
        }
        if (cnt[r[u]] == 1)
            t1[u] = uni(t1[u], uni(t0[l[u]], t1[l[u]]));
        else {
            t0[u] = uni(t0[u], t0[l[u]]);
            t1[u] = uni(t1[u], t1[l[u]]);
        }
    }
    if (s[u] == "XOR") {
        dfs(l[u]);
        dfs(r[u]);
        cnt[u] = cnt[l[u]] ^ cnt[r[u]];
        if (cnt[l[u]] == 1) {
            t0[u] = t1[r[u]];
            t1[u] = t0[r[u]];
        } else {
            t0[u] = t0[r[u]];
            t1[u] = t1[r[u]];
        }
        if (cnt[r[u]] == 1) {
            t0[u] = uni(t0[u], t1[l[u]]);
            t1[u] = uni(t1[u], t0[l[u]]);
        } else {
            t0[u] = uni(t0[u], t0[l[u]]);
            t1[u] = uni(t1[u], t1[l[u]]);
        }
    }
}

int main() {
    int i, j, n, k, a;
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for (i = 1; i <= n; ++i) {
        cin >> s[i];
        if (s[i] == "IN")
            cin >> cnt[i];
        else if (s[i] == "NOT")
                cin >> l[i];
            else
                cin >> l[i] >> r[i];
    }
    dfs(1);
    for (i = 0; i < v[t0[1]].size(); ++i)
        ans[v[t0[1]][i]] = 0;
    for (i = 0; i < v[t1[1]].size(); ++i)
        ans[v[t1[1]][i]] = 1;
    for (i = 1; i <= n; ++i)
    if (s[i] == "IN")
        cout << ans[i];
}