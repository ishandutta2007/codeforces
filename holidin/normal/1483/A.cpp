#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <math.h>
#include <iomanip>
#include <time.h>
#include <unordered_map>
#include <unordered_set>
#include <tgmath.h>
#define fi first
#define se second
#define ll long long
#define ld long double
#define int long long
using namespace std;
const int N = 2e5 + 12;
const ld PI = 3.141592653589793238;

bool local = 0;
vector<int> v[N];
vector<int> d[N];
int color[N];
void solve() {
    int n, k;
    cin >> n >> k;
    for (int i = 0; i <= n; ++i)
        v[i].clear();
    for (int i = 0; i < k; ++i) {
        int t;
        cin >> t;
        d[i].resize(t);
        for (auto& x : d[i]) {
            cin >> x;
            --x;
            v[x].push_back(i);
        }
        color[i] = -1;
    }
    int mx = 0;
    for (int i = 0; i < n; ++i)
        if (v[i].size() > v[mx].size())
            mx = i;
    auto vb = v[mx];
    int cnt = 0;
    for (auto x : vb)
        if (d[x].size() == 1) {
            ++cnt;
            color[x] = mx;
        }
    if (cnt > (k + 1) / 2) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    for (auto x : vb)
        if (color[x] < 0 && cnt + 1 <= (k + 1) / 2) {
            ++cnt;
            color[x] = mx;
        }
    for (int i = 0; i < k; ++i) {
        if (color[i] < 0) {
            if (d[i][0] == mx)
                color[i] = d[i][1];
            else
                color[i] = d[i][0];
        }
        cout << color[i] + 1 << ' ';
    }
    cout << "\n";

}


signed main() {
    if (local) {
        freopen("input.txt", "r", stdin);
    }
    ios_base::sync_with_stdio(false); cin.tie(0);
    int test = 1;
    cin >> test;
    while (test--) {
        solve();
    }
}