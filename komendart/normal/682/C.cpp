#include <bits/stdc++.h>

using namespace std;

#define int long long

const int maxn = 1e5 + 5;

vector<int> graph[maxn];
int a[maxn];
int c[maxn];
int cnt = 0;

void dfs(int v, int sum=0, int val=0) {
    if (v != 1) {
        sum += c[v];
        val = min(val, sum);
        if (sum - val > a[v]) return;
    }
    cnt++;
    for (auto u: graph[v]) {
        dfs(u, sum, val);
    }
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 2; i <= n; i++) {
        int p, t;
        cin >> p >> t;
        graph[p].push_back(i);
        c[i] = t;
    }

    dfs(1);
    cout << n - cnt << endl;
}