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
//#define int long long

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<int> b(n);
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int l = -1;
    int r = 100000;
    while (r - l > 1) {
        int m = (l + r) / 2;
        int sz = n + m;
        int now1 = 0;
        int now2 = 0;
        for (int i = sz / 4; i < sz; i++) {
            if (i >= n) {
                now1 += 100;
            } else {
                now1 += a[i];
            }
            if (i >= m) {
                now2 += b[i - m];
            }
        }
        if (now1 >= now2) {
            r = m;
        } else {
            l = m;
        }
    }
    cout << r << endl;
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