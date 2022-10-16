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

//#define int long long
#define endl '\n'


int arr[500][500];
int pref[500][500];

void solve() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char c;
            cin >> c;
            arr[i][j] = (c == '1');
        }
    }
    for (int j = 0; j < m; j++) {
        for (int i = 0; i < n; i++) {
            pref[i][j] = arr[i][j];
            if (i) {
                pref[i][j] += pref[i - 1][j];
            }
        }
    }

    int ans = 100000000;

    for (int i1 = 0; i1 < n; i1++) {
        for (int i2 = i1 + 4; i2 < n; i2++) {
            vector<int> arr2(m);
            for (int i = 0; i < m; i++) {
                arr2[i] = pref[i2 - 1][i] - pref[i1][i];
                arr2[i] += (arr[i1][i] == 0);
                arr2[i] += (arr[i2][i] == 0);
            }
            vector<int> arr1(m);
            for (int i = 0; i < m; i++) {
                int len = i2 - i1 - 1;
                arr1[i] = len - (pref[i2 - 1][i] - pref[i1][i]);
            }
            vector<int> pref(m);
            for (int i = 0; i < m; i++) {
                pref[i] = arr2[i];
                if (i) {
                    pref[i] += pref[i - 1];
                }
            }
            int kek_val = -10000000;
            for (int i = 3; i < m; i++) {
                kek_val = max(kek_val, (-arr1[i - 3] + pref[i - 3]));
                int now = pref[i - 1] + arr1[i];
                now -= kek_val;
                ans = min(ans, now);
            } 
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