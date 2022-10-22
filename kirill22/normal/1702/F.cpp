#include<bits/stdc++.h>

using namespace std;

const int N = 1e7;
int l[N], r[N], bal[N];
int c = 1, ans = 0;

void add(int v, int x, int j, int t) {
    if (j == -1 || x == 0) {
        bal[v] += t;
        return;
    }
    if (l[v] ==0) {
        l[v] = c++;
    }
    if (r[v] == 0) {
        r[v] = c++;
    }
    if (x >> j & 1) {
        add(r[v], x, j - 1, t);
    } else {
        add(l[v], x, j - 1, t);
    }
}

void dfs(int v) {
    if (ans == -1) {
        return;
    }
    if (l[v] == 0) {
        return;
    }
    dfs(l[v]);
    dfs(r[v]);
    if (ans == -1) {
        return;
    }
    //cout << temp[v] << " " << gl[v] << " " << v << " " << bal[l[v]] << " " << bal[r[v]] << endl;
    if (bal[r[v]] < 0) {
        ans = -1;
        return;
    }
    ans += abs(bal[l[v]]);
    ans += abs(bal[r[v]]);
    bal[v] += bal[l[v]] + bal[r[v]];
}

void solve() {
    c = 1, ans = 0;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        int j = 0;
        while ((1 << (j + 1)) <= x) {
            j++;
        }
        add(0, x, j, -1);
    }
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        int j = 0;
        while ((1 << (j + 1)) <= x) {
            j++;
        }
        add(0, x, j, 1);
    }
    dfs(0);
    for (int i = 0; i <= c; i++) {
        bal[i] = l[i] = r[i] = 0;
    }
    cout << (ans == -1 ? "NO\n" : "YES\n");
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}