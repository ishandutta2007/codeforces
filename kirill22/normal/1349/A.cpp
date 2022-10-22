#include <bits/stdc++.h>

using namespace std;

#define int long long
#define fi first
#define se second
#define ld long double

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    int ans = 1;
    unordered_map<int, vector<int>> b;
    for (int i = 0; i < n; i++) {
        int x = a[i];
        for (int j = 2; j * j <= x; j++) {
            int c = 0;
            while (x % j == 0) {
                c++;
                x /= j;
            }
            if (c != 0) b[j].push_back(c);
        }
        if (x > 1) b[x].push_back(1);
    }
    for (auto el : b) {
        if (el.second.size() >= n - 1) {
            while (b[el.first].size() < n) {
                b[el.first].push_back(0);
            }
            sort(b[el.first].begin(), b[el.first].end());
            int k = 1;
            for (int i = 0; i < b[el.first][1]; i++) k *= el.first;
            ans *= k;
        }
    }
    cout << max(1ll, ans);
}