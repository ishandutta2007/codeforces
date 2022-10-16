#include <unordered_map>
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <random>
#include <iomanip>
#include <clocale>
#include <bitset>
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

#define data NE_data
#define rank NE_rank
#define endl '\n'

#define int long long

void solve() {
    int n;
    cin >> n;
    vector<pair<int, int>> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i].first;
        arr[i].second = i;
    }

    sort(arr.rbegin(), arr.rend());
    vector<int> ans(n);
    int val = 0;

    for (int i = 0; i < n; i++) {
        int now = i / 2 + 1;
        if (i % 2) {
            ans[arr[i].second] = now;
        } else {
            ans[arr[i].second] = -now;
        }
        val += now * arr[i].first;
    }
    cout << val * 2 << endl;
    cout << 0 << " ";
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