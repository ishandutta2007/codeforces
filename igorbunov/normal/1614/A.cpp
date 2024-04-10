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
    int n, l, r, k;
    cin >> n >> l >> r >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] > r) {
            break;
        }
        if (arr[i] < l) {
            continue;
        }
        if (arr[i] > k) {
            break;
        }
        ans++;
        k -= arr[i];
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