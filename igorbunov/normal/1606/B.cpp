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

void solve() {
    int n, k;
    cin >> n >> k;
    int now = 1;
    int ost = n - 1;
    int ans = 0;
    while (ost > 0 && now < k) {
        ost -= now;
        now *= 2;
        ans++;
    }
    if (ost <= 0) {
        cout << ans << endl;
        return;
    }
    ans += (ost - 1) / k + 1;
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