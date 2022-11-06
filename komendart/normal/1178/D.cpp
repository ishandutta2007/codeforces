#include <bits/stdc++.h>

using namespace std;

#define sz(x) ((int) (x).size())

bool is_prime(int n) {
    if (n == 1) return false;
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    
    /*for (int n = 3; n <= 1000; ++n) {
        bool ok = false;
        for (int i = n; i <= n + n / 2; ++i) {
            if (is_prime(i)) {
                ok = true;
                break;
            }
        }
        if (!ok) {
            cout << n << endl;
        }
    }*/
    
    int n;
    cin >> n;
    vector<pair<int, int>> ans;
    for (int i = 1; i < n; ++i) {
        ans.emplace_back(i, i + 1);
    }
    ans.emplace_back(n, 1);
    if (n > 3) {
        vector<int> deg(n, 2);
        for (int i = 1; i <= n; ++i) {
            int j = 1 + ((i - 1) + 2) % n;
            if (deg[i] == 2 && deg[j] == 2) {
                ++deg[i];
                ++deg[j];
                ans.emplace_back(i, j);
            }
        }
    }
    while (!is_prime(sz(ans))) {
        ans.pop_back();
    }
    assert(sz(ans) >= n);
    
    cout << sz(ans) << '\n';
    for (auto [i, j]: ans) {
        cout << i << ' ' << j << '\n';
    }
}