#include <iostream>
#include <cstdio>
#include <cmath>
#include <cassert>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <numeric>
#include <iomanip>

using namespace std;

#define sz(x) ((int) (x).size())

signed main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false); cin.tie(0);
    
    int n;
    cin >> n;
    vector<int> L;
    vector<int> R;
    long long ans = 0;
    for (int i = 0; i < n; ++i) {
        int len; cin >> len;
        bool ok = false;
        int ma; cin >> ma;
        int prev = ma;
        for (int j = 1; j < len; ++j) {
            int x; cin >> x;
            if (x > prev) {
                ok = true;
            }
            prev = x;
        }
        if (ok) {
            ans += n;
        } else {
            L.push_back(prev);
            R.push_back(ma);
        }
    }
    sort(begin(L), end(L));
    for (auto val: R) {
        int cnt = lower_bound(begin(L), end(L), val) - begin(L);
        ans += cnt;
        ans += n - sz(L);
    }
    cout << ans << '\n';
    
}