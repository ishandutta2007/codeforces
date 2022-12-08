#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <stack>
#include <queue>
#include <string>
#include <cmath>
#include <map>
#include <random>
#include <chrono>
#include <fstream>
#include <array>
#include <iomanip>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <sstream> 
#include <utility>
#include <functional>
#include <bitset>
#include <cassert>

using namespace std;
using ll = long long;
using ld = long double;

// #define int long long

#define pii pair<int, int>
#define vi vector<int>
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define mp make_pair

const ld eps = 1e-8;
// const ll mod = 998244353;
const ll mod = 1e9 + 7;
const int MAXN = 3e5;
const int inf0 = 1e9 + 10;
const ll inf = 2e18 + 10;

void solve();

signed main() {
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}

int do_scan(int x, int y) {
    cout << "SCAN " << x + 1 << " " << y + 1 << "\n";
    cout.flush();
    int ans;
    cin >> ans;
    return ans;
}


int do_dig(int x, int y) {
    cout << "DIG " << x + 1 << " " << y + 1 << "\n";
    cout.flush();
    int ans;
    cin >> ans;
    return ans;
}

void solve() {
    int n, m;
    cin >> n >> m;
    int x3y3mx1my1 = n + m - 2 - do_scan(0, 0);
    int x1y3mx3my1 = n + m - 2 - do_scan(n - 1, 0);
    int x3mx1 = (x3y3mx1my1 - x1y3mx3my1) / 2;
    int y3my1 = (x3y3mx1my1 + x1y3mx3my1) / 2;
    int x2y2 = do_scan((n - 1 - x3mx1) / 2, (m - 1 - y3my1) / 2) + 2;
    int y1 = (do_scan((n - 1 - x3mx1) / 2, 0) - x2y2 + 2) / 2;
    int y3 = y3my1 + y1;
    int x2 = x2y2 - (m - y1 - y3);
    int x3 = (n - x2 + x3mx1) / 2;
    int x1 = (n - x2 - x3mx1) / 2;
    if (do_dig(x1, y1)) {
        assert(do_dig(n - 1 - x3, m - 1 - y3) == 1);
    }
    else {
        assert(do_dig(x1, m - 1 - y3) == 1);
        assert(do_dig(n - 1 - x3, y1) == 1);
    }
}