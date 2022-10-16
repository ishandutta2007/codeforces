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

bool comp(vector<int> arr1, vector<int> arr2) {
    int cnt = 0;
    for (int i = 0; i < 5; i++) {
        cnt += arr1[i] < arr2[i];
    }
    return cnt >= 3;
}

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> r(n, vector<int>(5));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 5; j++) {
            cin >> r[i][j];
        }
    }
    int ans = 0;
    for (int i = 1; i < n; i++) {
        if (comp(r[i], r[ans])) {
            ans = i;
        }
    }

    bool good = true;
    for (int i = 0; i < n; i++) {
        if (i == ans) {
            continue;
        }
        if (comp(r[i], r[ans])) {
            good = false;
            break;
        }
    }
    if (good) {
        cout << ans + 1 << endl;
    } else {
        cout << -1 << endl;
    }
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