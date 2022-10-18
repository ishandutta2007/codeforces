#include "bits/stdc++.h"
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> v(2, vector<int>(n));
    vector<vector<int>> where(n);
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < n; j++) {
            cin >> v[i][j];
            v[i][j]--;
            where[v[i][j]].push_back(j);
        }
    }

    vector<bool> finished(n, false);
    for (int i = 0; i < n; i++) {
        if (where[i].size() != 2) {
            cout << -1 << '\n';
            return;
        }
        if (where[i][0] == where[i][1])
            finished[where[i][0]] = true;
    }

    vector<int> which_ones;
    for (int i = 0; i < n; i++) {
        if (finished[i])
            continue;

        int columns = 0;
        int cur_col = i;
        int cur_value = v[0][cur_col];
        vector<int> option_a, option_b;
        do {
            int next_col = cur_col ^ where[cur_value][0] ^ where[cur_value][1];
            int next_value;
            if (v[0][next_col] == cur_value) {
                next_value = v[1][next_col];
                option_a.push_back(next_col);
            } else {
                next_value = v[0][next_col];
                option_b.push_back(next_col);
            }
            columns++;
            cur_col = next_col;
            cur_value = next_value;
        } while (cur_col != i);

        if (option_a.size() > option_b.size())
            option_a.swap(option_b);
        for (int x : option_a)
            which_ones.push_back(x);

        for (int x : option_a)
            finished[x] = true;
        for (int x : option_b)
            finished[x] = true;
    }
    cout << which_ones.size() << '\n';
    for (int x : which_ones) {
        cout << x + 1 << " ";
    }
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    for (int t = 0; t < T; t++) {
        solve();
    }
}