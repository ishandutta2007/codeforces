#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;
    n <<= 1;
    vector<vector<pair<int,ll>>> adj(n);
    for (int i = 0; i < n - 1; i++) {
        int a, b; ll c;
        cin >> a >> b >> c;
        a--, b--;
        adj[a].emplace_back(b, c);
        adj[b].emplace_back(a, c);
    }

    vector<int> parent(n, -1), que(1, 0);
    vector<ll> parent_cost(n);
    parent[0] = 0;
    for (int f = 0; f < que.size(); f++) {
        int i = que[f];
        for (auto [j, c]: adj[i]) {
            if (parent[j] == -1) {
                parent[j] = i;
                parent_cost[j] = c;
                que.push_back(j);
            }
        }
    }
    vector<int> size(n, 1);
    ll mn = 0, mx = 0;
    reverse(que.begin(), que.end());
    for (int i : que) {
        size[parent[i]] += size[i];
        mx += parent_cost[i] * min(size[i], n - size[i]);
        mn += parent_cost[i] * (size[i] & 1);
    }
    cout << mn << " " << mx << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int z;
    for (cin >> z; z--; solve());
}