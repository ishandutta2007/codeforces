#include<bits/stdc++.h>

using namespace std;

vector<vector<int>> g;
vector<int> l, used;
int T = 0;

bool dfs(int v) {
    if (used[v] == T) {
        return false;
    }
    used[v] = T;
    for (auto x : g[v]) {
        if (l[x] == -1) {
            l[x] = v;
            return true;
        }
    }
    for (auto x : g[v]) {
        if (dfs(l[x])) {
            l[x] = v;
            return true;
        }
    }
    return false;
}

long long opt(long long x, int y) {
    if (x % y == 0) {
        x += y;
    } else {
        x += y - x % y;
    }
    return x;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<int> a(n), usd(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    l.resize(n, -1);
    long long ans = 0, sum = 0;
    for (int t = 0; t < n; t++) {
        map<long long, vector<int>> c;
        for (int i = 0; i < n; i++) {
            if (!usd[i]) {
                c[opt(ans, a[i])].push_back(i);
            }
        }
        for (auto [x, b] : c) {
            T++;
            g.push_back(b);
            used.push_back(0);
            if (dfs(t)) {
                ans = x;
                break;
            } else {
                used.pop_back();
                g.pop_back();
                for (auto i : b) {
                    usd[i] = 1;
                }
            }
        }
        sum += ans;
    }
    cout << sum << '\n';
}