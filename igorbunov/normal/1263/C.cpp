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
    map<int, int> lol;
    int ans = 0;
    vector<int> arr;
    for (int i = 1; i * i < n; i++) {
        int now = n / i;
        if (lol[now] == 0) {
            ans++;
            arr.push_back(now);
            lol[now]++;
        }
    }
    //n / a = i
    for (int i = 1; i * i <= n; i++) {
        int bruh = n / i;
        for (int j = max(1LL, bruh - 5); j < bruh + 5; j++) {
            int now = n / j;
            if (lol[now] == 0) {
                ans++;

            arr.push_back(now);
                lol[now]++;
            }
        }
    }
    if (lol[0] == 0) {

            arr.push_back(0);
        ans++;
    }
    cout << ans << endl;
    sort(arr.begin(), arr.end());
    for (auto val: arr) {
        cout << val << " ";
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
    return 0;
}