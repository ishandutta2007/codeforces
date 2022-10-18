#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> pre;
vector<int> starts;
vector<int> coproc;
vector<int> cnts;
vector<int> nexts;

void dfs(int v, int co) {
    for (int p : pre[v]) {
        cnts[p]--;
        if (cnts[p] == 0) {
            if (coproc[p] == co) {
                nexts.push_back(p);
            } else {
                dfs(p, co);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    coproc.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> coproc[i];
    }
    pre.resize(n);
    cnts.assign(n, 0);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        pre[v].push_back(u);
        cnts[u]++;
    }

    for (int i = 0; i < n; i++) {
        if (cnts[i] == 0) {
            if (coproc[i])
                nexts.push_back(i);
            else
                starts.push_back(i);
        }
    }

    int cnt = 0;
    while (starts.size() + nexts.size()) {
        for (auto v : starts) {
            dfs(v, 1);
        }
        starts.swap(nexts);
        nexts.clear();

        if (starts.size()) {
            cnt++;
        }
        for (auto v : starts) {
            dfs(v, 0);
        }
        starts.swap(nexts);
        nexts.clear();
    }

    cout << cnt << '\n';
    
}