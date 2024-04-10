#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <algorithm>
#include <utility>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <iomanip>
#include <fstream>
#include <cmath>
using namespace std;
typedef long long ll;

void solve() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<int> vals(k);
    for (int i = 0; i < k; i++) {
        char val = '?';
        for (int j = i; j < n; j += k) {
            if (s[j] == '0') {
                if (val == '1') {
                    cout << "NO\n";
                    return;
                }
                val = s[j];
            }
            if (s[j] == '1') {
                if (val == '0') {
                    cout << "NO\n";
                    return;
                }
                val = s[j];
            }
        }
        vals[i] = val;
    }
    int count0 = 0, count1 = 0;
    for (auto c : vals) {
        if (c == '0') count0++;
        if (c == '1') count1++;
    }
    if (count0 <= k / 2 && count1 <= k / 2) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
    return;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed << setprecision(14);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}