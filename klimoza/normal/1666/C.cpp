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
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    cout << fixed;
    cout.precision(15);
    solve();
    return 0;
}

void solve() {
    int x1, y1, x2, y2, x3, y3;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    vector<pair<int, int>> p = vector<pair<int, int>>{mp(x1, y1), mp(x2, y2), mp(x3, y3)};
    sort(all(p));
    int ymin = min(p[0].second, min(p[1].second, p[2].second));
    int ymax = max(p[0].second, max(p[1].second, p[2].second));
    vector<pair<pair<int, int>, pair<int, int>>> ans;
    if(ymin != ymax)
        ans.push_back(mp(mp(p[1].first, ymin), mp(p[1].first, ymax)));
    if(p[0].first != p[1].first)
        ans.push_back(mp(mp(p[0].first, p[0].second), mp(p[1].first, p[0].second)));
    if(p[2].first != p[1].first)
        ans.push_back(mp(mp(p[1].first, p[2].second), mp(p[2].first, p[2].second)));
    cout << ans.size() << endl;
    for(auto v : ans) {
        cout << v.first.first << " " << v.first.second << " " << v.second.first << " " << v.second.second << "\n";
    }
}