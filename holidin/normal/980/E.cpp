#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 1;

int d[3*N], ans[3*N], deep[N], tin[N], tout[N], v, a[N], top, cnt, p[N];
bool b[N];
vector <int> sp, e[N];

void push(int v) {
    if (d[v] != 0) {
        d[2*v + 1] += d[v];
        d[2*v + 2] += d[v];
        ans[2*v + 1] += d[v];
        ans[2*v + 2] += d[v];
        d[v] = 0;
    }
}

void recalc(int v) {
    ans[v] = min(ans[2*v + 1], ans[2*v + 2]);
}

void add(int v, int vl, int vr, int l, int r, int x) {
    if (l <= vl && vr <= r) {
        d[v] += x;
        ans[v] += x;
    } else if (vl >= r || l >= vr)
            return;
        else {
            push(v);
            add(2*v + 1, vl, (vl + vr)/2, l, r, x);
            add(2*v + 2, (vl + vr)/2, vr, l, r, x);
            recalc(v);
        }
}

int sum(int v, int vl, int vr, int l, int r) {
    if (l <= vl && vr <= r)
        return ans[v];
    else {
        push(v);
        if (l < (vl + vr)/2)
            return sum(2*v + 1, vl, (vl + vr)/2, l, r);
        else
            return sum(2*v + 2, (vl + vr)/2, vr, l, r);
    }
}

void add_element(int u) {
    ++cnt;
    sp.push_back(u);
    b[u] = true;
    add(0, 1, v + 1, tin[u], tout[u] + 1, -1);
}

void dfs(int u, int pr, int dp) {
    ++top;
    tin[u] = top;
    a[top] = u;
    p[u] = pr;
    deep[u] = dp;
    for (int i = 0; i < e[u].size(); ++i)
    if (e[u][i] != pr)
        dfs(e[u][i], u, dp + 1);
    tout[u] = top;
}

void add_element_to_cmp(int u) {
    vector <int> v;
    int j = u;
    while (!b[j]) {
        v.push_back(j);
        j = p[j];
    }
    for (int i = v.size() - 1; i >= 0; --i)
        add_element(v[i]);
}

int main() {
    int a1, b1, i, j, n, k;
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> k;
    for (int i = 1; i < n; ++i) {
        cin >> a1 >> b1;
        e[a1].push_back(b1);
        e[b1].push_back(a1);
    }
    dfs(n, 0, 0);
    v = 1;
    while (v < n) v *= 2;
    sp.push_back(n);
    b[n] = true;
    add(0, 1, v + 1, 1, 2, 1e9);
    for (i = 1; i <= v; ++i)
    if (i <= n)
        add(0, 1, v + 1, i, i + 1, deep[a[i]]);
    else
        add(0, 1, v + 1, i, i + 1, 1e9);
    cnt = 1;
    for (i = n - 1; i > 0 && cnt + k != n; --i)
    if (sum(0, 1, v + 1, tin[i], tin[i] + 1) <= n - cnt - k)
        add_element_to_cmp(i);
    sort(sp.begin(), sp.end());
    for (i = 1; i <= n; ++i)
    if (!b[i])
        cout << i << ' ';
}