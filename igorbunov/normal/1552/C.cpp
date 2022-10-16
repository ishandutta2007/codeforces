#include <unordered_map>
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <random>
#include <iomanip>
#include <clocale>
#include <string>
#include <vector>
#include <cmath>
#include <ctime>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>

using namespace std;

#define endl '\n'
#define int long long

bool check(int x1, int y1, int x2, int y2, int n) {
    int val1 = (x2 - x1 + 2 * n) % (2 * n);
    val1 += (y1 - x2 + 2 * n) % (2 * n);
    val1 += (y2 - y1 + 2 * n) % (2 * n);
    val1 += (x1 - y2 + 2 * n) % (2 * n);
    if (val1 == 2 * n) {
        return true;
    }
    swap(x2, y2);
    int val2 = (x2 - x1 + 2 * n) % (2 * n);
    val2 += (y1 - x2 + 2 * n) % (2 * n);
    val2 += (y2 - y1 + 2 * n) % (2 * n);
    val2 += (x1 - y2 + 2 * n) % (2 * n);
    if (val2 == 2 * n) {
        return true;
    }
    return false;
}


void solve() {
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> now;
    vector<bool> used(2 * n);
    for (int i = 0; i < k; i++) {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        used[x] = true;
        used[y] = true;
        now.push_back(make_pair(x, y));
    }
    vector<int> kek;
    for (int i = 0; i < 2 * n; i++) {
        if (!used[i]) {
            kek.push_back(i);
        }
    }
    for (int i = 0; i < n - k; i++) {
        now.push_back(make_pair(kek[i], kek[i + n - k]));
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            ans += check(now[i].first, now[i].second, now[j].first, now[j].second, n);
        }
    }
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        solve();
    }
}