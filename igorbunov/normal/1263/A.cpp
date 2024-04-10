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
    vector<int> arr(3);
    cin >> arr[0] >> arr[1] >> arr[2];
    sort(arr.begin(), arr.end());
    int ans = arr[1] - arr[0];
    arr[2] -= ans;
    arr[1] -= ans;
    if (arr[0] + arr[1] <= arr[2]) {
        ans += arr[0] + arr[1];
        cout << ans << endl;
        return;
    }
    arr[0] -= arr[2] / 2;
    arr[1] -= arr[2] / 2;
    ans += arr[2] - arr[2] % 2;
    ans += arr[0];
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
    return 0;
}