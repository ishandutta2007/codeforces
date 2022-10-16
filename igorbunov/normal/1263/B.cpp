#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <stdio.h>
#include <iomanip>
#include <clocale>
#include <random>
#include <string>
#include <random>
#include <vector>
#include <cmath>
#include <ctime>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>

using namespace std;

#define int long long
#define endl '\n'


void solve() {
    int n;
    cin >> n;
    vector<string> arr(n);
    map<string, int> kek;
    map<string, int> kek1;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        kek1[arr[i]]++;
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (kek[arr[i]]) {
            string t = arr[i];
            for (int j = 0; j < 10; j++) {
                t[0] = '0' + j;
                if (kek[t] == 0 && kek1[t] == 0) {
                    break;
                }
            }
            ans++;
            arr[i] = t;
        }
        kek[arr[i]]++;
    }
    cout << ans << endl;
    for (auto val: arr) {
        cout << val << endl;
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
    return 0;
}