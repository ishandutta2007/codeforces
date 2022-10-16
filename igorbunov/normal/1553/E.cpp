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

vector<int> g[400000];
vector<int> used(400000);

void dfs(int v) {
    if (used[v]) {
        return;
    }
    used[v] = true;
    dfs(g[v][0]);
}

int solve1(int n, vector<int> next) {
    for (int i = 0; i < n; i++) {
        g[i].clear();
        used[i] = false;
    }
    for (int i = 0; i < n; i++) {
        g[i].push_back(next[i]);
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (!used[i]) {
            ans++;
            dfs(i);
        }
    }
    return ans;
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        arr[i]--;
    }
    vector<int> kek(n);
    vector<int> cnt(n);
    for (int i = 0; i < n; i++) {
        kek[arr[i]] = i;
        cnt[(arr[i] - i + n) % n]++;
    }
    vector<int> ans;
    for (int sd = 0; sd < n; sd++) {
        if (cnt[sd] >= n / 3 - 2) {
            vector<int> next(n);
            for (int i = 0; i < n; i++) {
                next[i] = kek[i] + sd;
                next[i] %= n;
            }
            int res = solve1(n, next);
            if (m >= n - res) {
                ans.push_back((n - sd) % n);
            }
        }
    }
    sort(ans.begin(), ans.end());
    cout << ans.size() << " ";
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
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