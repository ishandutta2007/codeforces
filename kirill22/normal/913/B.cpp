#include<bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<vector<int>> g(n);
    for (int i = 1; i < n; i++) {
        int x;
        cin >> x;
        x--;
        g[x].push_back(i);
    }
    for (int i = 0; i < n; i++) {
        if ((int) g[i].size() == 0) {
            continue;
        }
        int cnt = 0;
        for (auto j : g[i]) {
            cnt += ((int) g[j].size() == 0);
        }
        if (cnt <= 2) {
            cout << "No";
            return 0;
        }
    }
    cout << "Yes";
}