#pragma GCC optimize("Ofast")
/*
#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
*/

#include <bits/stdc++.h>

using namespace std;

//defines
typedef long long ll;
typedef long double ld;
#define TIME clock() * 1.0 / CLOCKS_PER_SEC
#define y0 _y0
#define kill _kill

//permanent constants
const ld pi = acos(-1.0);
const int day[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
const int digarr[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};
const int dxo[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
const int dyo[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
const int alf = 26;
const ld eps = 1e-10;
const ll INF = (ll)(4e18 + 239);
const int BIG = (int)(1e9 + 239);
const int MOD = 1e9 + 7;
const ll MOD2 = (ll)MOD * (ll)MOD;

//random
#ifdef ONPC
mt19937_64 rnd(239);
#else
mt19937_64 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
#endif

//constants
const int M = (int)(5e4 + 239);
const int N = (int)(2e3 + 10);
const int L = 21;
const int T = (1 << 18) + 239;
const int B = 510;
const int X = 1e4 + 239;

int n, k;
vector<int> busy;

int len(int x, int y) {
    if (y >= x) {
        return y - x;
    }
    return 2 * n - len(y, x);
}

int count(int x, int y) {
    int ans = 0;
    for (int z : busy) {
        if (len(x, y) == len(x, z) + len(z, y)) {
            ans++;
        }
    }
    return ans;
}

bool inter(pair<int, int> a, pair<int, int> b) {
    for (int ms = 0; ms < 4; ms++) {
        if (ms & 1) {
            swap(a.first, a.second);
        }
        if ((ms >> 1) & 1) {
            swap(b.first, b.second);
        }
        int sum = 0;
        sum += len(a.first, a.second);
        sum += len(a.second, b.first);
        sum += len(b.first, b.second);
        sum += len(b.second, a.first);
        if (sum == 2 * n) {
            return false;
        }
        if (ms & 1) {
            swap(a.first, a.second);
        }
        if ((ms >> 1) & 1) {
            swap(b.first, b.second);
        }
    }
    return true;
}

void solve() {
    cin >> n >> k;
    vector<pair<int, int>> v;
    busy.clear();
    vector<bool> free(2 * n, true);
    for (int i = 0; i < k; i++) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        v.emplace_back(x, y);
        free[x] = false;
        free[y] = false;
    }
    for (int i = 0; i < 2 * n; i++) {
        if (free[i]) {
            busy.emplace_back(i);
        }
    }
    int ans = (n - k) * (n - k - 1) / 2;
    for (int i = 0; i < k; i++) {
        for (int j = i + 1; j < k; j++) {
            if (inter(v[i], v[j])) {
                ans++;
            }
        }
    }
    for (int i = 0; i < k; i++) {
        ans += min(count(v[i].first, v[i].second), count(v[i].second, v[i].first));
    }
    cout << ans << "\n";
}

int32_t main() {
#ifdef ONPC
    freopen("input", "r", stdin);
#endif
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}