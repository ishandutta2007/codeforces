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

void solve() {
    int n;
    cin >> n;
    ll W;
    cin >> W;

    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(a.begin(), a.end());

    while (!a.empty() && a.back().first > W) {
        a.pop_back();
    }

    if (!a.empty() && a.back().first * 2 >= W) {
        cout << "1\n";
        cout << a.back().second + 1 << '\n';
        return;
    }

    ll sum = 0;
    vector<int> ans;
    for (int i = 0; i < (int)a.size(); i++) {
        sum += a[i].first;
        ans.push_back(a[i].second);
        if (2 * sum >= W) break;
    }

    if (2 * sum < W) {
        cout << "-1\n";
        return;
    }
    cout << ans.size() << '\n';
    for (int i : ans) cout << i + 1 << ' ';
    cout << '\n';

}

int main() {

#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);

    int test;
    cin >> test;
    while (test--) solve();


    return 0;
}