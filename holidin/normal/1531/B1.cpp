#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <map>
#include <algorithm>
#include <set>
#include <math.h>
#include <random>
#include <bitset>
#include <map>
#include <unordered_map>
#include <queue>
#include <time.h>
#define fi first
#define se second
#define ll long long
#define int long long
#define ld double
#define mp make_pair
using namespace std;
const int inf = 1e9;
const int N = 3e5 + 13;
vector<int> e[N];

map<int, int> sq;
map<int, int> side;
map<pair<int, int>, int> cnt;


void solve() {
    int n, k,a, b;
    string s;
    cin >> n;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a >> b;
        ans += side[a];
        if (a != b) {
            ans += side[b];
            ans -= cnt[{a, b}] + cnt[{b, a}];
            ++side[a];
            ++side[b];
            ++cnt[{a, b}];
        } else {
            ++side[a];
        }
    }
    cout << ans;
}



signed main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // local
    solve();


}