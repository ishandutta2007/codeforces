#include <bits/stdc++.h>

using namespace std;

vector< pair<int, int> > ans;
int diameter = 0;

void solve(int n, int k, int cur) {
    if (n - cur + 1 <= k) {
        for (int i = cur + 1; i <= n; ++i) {
            ans.push_back({cur, i});
        }
        return;
    }
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    int n, k;
    cin >> n >> k;
    vector< vector<int> > layers;
    for (int i = 0; i < n; ++i) {
        if (i % k == 0 || i == n - 1) layers.resize(layers.size() + 1);
        layers.back().push_back(i + 1);
    }
    int sz = layers.size();
    int diameter = 2 * (sz - 1);
    if (layers[sz - 2].size() == 1) {
        --diameter;
        layers[sz - 2].push_back(n);
        layers.pop_back();
    }
    cout << diameter << '\n';
    for (int i = 0; i + 1 < layers.size(); ++i) {
        for (int j = 0; j < layers[i].size(); ++j) {
            cout << layers[i][j] << ' ';
            cout << layers[i + 1][min(j, (int) layers[i + 1].size() - 1)] << '\n';
        }
    }
    if (layers.back().size() == 2) {
        cout << layers.back()[0] << ' ' << layers.back()[1] << '\n';
    }
}