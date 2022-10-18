#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<bool> used(m+1, false);
    for (int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;
        for (int j = l; j <= r; j++) {
            used[j] = true;
        }
    }

    vector<int> res;
    for (int i = 1; i <= m; i++) {
        if (!used[i])
            res.push_back(i);
    }

    cout << (int)res.size() << '\n';
    for (auto x : res) {
        cout << x << ' ';
    }
    cout << '\n';
}