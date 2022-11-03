#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <cassert>
#include <cstddef>
#include <cstring>
#include <bitset>
#include <random>
#include <memory>
#include <iomanip>

typedef long long ll;
typedef long double ld;

using namespace std;

int main() {

#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);

    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(n));
    vector<pair<int, int>> b;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
            b.push_back({i, j});
        }
    }
    sort(b.begin(), b.end(), [&](auto& i, auto& j) {
        return a[i.first][i.second] < a[j.first][j.second];
    });
    vector<int> r(n), c(n, n);
    ll ans = 0;

    for (auto [i, j] : b) {
        ans += r[i] * 1ll * (c[j] - 1);
        r[i]++;
        c[j]--;
    }
    cout << ans << '\n';


    return 0;
}