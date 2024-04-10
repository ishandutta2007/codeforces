#pragma GCC_OPTIMIZE("ofast")
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

int pow(int a, int b) {
    int c = 1;
    for (int i = 0; i < b; i++) {
        c *= a;
    }
    return c;
}
void solve() {
    int n, k;
    cin >> n >> k;
    k++;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        int c;
        cin >> c;
        int ans = 1;
        for (int j = 0; j < c; j++) {
            ans *= 10;
        }
        arr[i] = ans;
    }
    int ans = 0;
    for (int i = 0; i < n - 1; i++) {
        int now = arr[i + 1] / arr[i] - 1;
        if (now >= k) {
            cout << ans + k * arr[i] << endl;
            return;
        } else {
            k -= now;
            ans += now * arr[i];
        }
    }
    ans += k * arr.back();
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