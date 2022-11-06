#include <bits/stdc++.h>

using namespace std;

int bits;
int maxn;

bool a[1 << 22];
bool used[1 << 22];
vector<int> order;
int add;

void dfs1(int v) {
    if (used[v]) return;
    used[v] = true;
    if (a[v]) {
        dfs1((maxn - 1) ^ v);
    }
    for (int i = 0; i < bits; ++i) {
        if (v & (1 << i)) {
            dfs1(v ^ (1 << i));
        }
    }
    order.push_back(v);
}

void dfs2(int v) {
    if (used[v]) return;
    used[v] = true;
    if (a[v]) {
        add = 1;
    }
    if (a[(maxn - 1) ^ v]) {
        dfs2((maxn - 1) ^ v);
    }
    for (int i = 0; i < bits; ++i) {
        dfs2(v | (1 << i));
    }
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    
    int n;
    cin >> bits >> n;
    maxn = 1 << bits;
    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        a[x] = true;
    }
    
    for (int i = 0; i < maxn; ++i) {
        if (!used[i]) {
            dfs1(i);
        }
    }
    reverse(order.begin(), order.end());
    memset(used, 0, sizeof(used));
    int ans = 0;
    for (auto i: order) {
        if (!used[i]) {
            add = 0;
            dfs2(i);
            ans += add;
        }
    }
    cout << ans << '\n';
}