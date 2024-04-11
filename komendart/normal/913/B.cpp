#include <bits/stdc++.h>

using namespace std;

#define sz(x) ((int) (x).size())

const int maxn = 1005;

int n;
vector<int> graph[maxn];

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    cin >> n;
    for (int i = 2; i <= n; ++i) {
        int p; cin >> p;
        graph[p].push_back(i);
    }
    for (int i = 1; i <= n; ++i) {
        if (graph[i].empty()) continue;
        int cnt = 0;
        for (auto to: graph[i]) {
            if (graph[to].empty()) ++cnt;
        }
        if (cnt < 3) {
            cout << "No\n";
            return 0;
        }
    }
    cout << "Yes\n";
}