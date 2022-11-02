#include <bits/stdc++.h>

using namespace std;

vector<int> numtok(int x, int k) {
    vector<int> res;
    while (x != 0) res.push_back(x % k), x /= k;
    return res;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n, k;
    cin >> n >> k;
    vector<vector<int>> v(n);
    for (int i = 0; i < n; ++i) v[i] = numtok(i, k);
    int ans = v.back().size();
    for (int i = 0; i < n; ++i) {
        while (v[i].size() != ans) v[i].push_back(0);
        reverse(v[i].begin(), v[i].end());
    }
    cout << ans << '\n';
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            for (int l = 0; l < ans; ++l) {
                if (v[i][l] != v[j][l]) {
                    cout << l + 1 << ' ';
                    break;
                }
            }
        }
    }
    std::cout << '\n';
    return 0;
}