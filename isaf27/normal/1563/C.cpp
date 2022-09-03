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
const ll INF = (ll)(1e18 + 239);
const int BIG = (int)(1e9 + 239);
//const int MOD = 998244353; //1e9 + 7;
//const ll MOD2 = (ll)MOD * (ll)MOD;

//random
#ifdef ONPC
mt19937_64 rnd(239);
#else
mt19937_64 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
#endif

//constants
const int M = (int)(2e5 + 239);
const int N = (int)(2e3 + 10);
const int L = 21;
const int T = (1 << 18) + 239;
const int B = 2000;
const int X = 2100;

int n, a[X];
vector<int> ans;

void add(int x) {
    ans.emplace_back(x);
    reverse(a, a + x);
}

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i]--;
    }
    vector<int> even, odd;
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            even.emplace_back(a[i]);
        } else {
            odd.emplace_back(a[i]);
        }
    }
    sort(even.begin(), even.end());
    sort(odd.begin(), odd.end());
    for (int i = 0; i < (int)even.size(); i++) {
        if (even[i] != 2 * i) {
            cout << "-1\n";
            return;
        }
    }
    for (int i = 0; i < (int)odd.size(); i++) {
        if (odd[i] != 2 * i + 1) {
            cout << "-1\n";
            return;
        }
    }
    if (n == 3) {
        if (a[0] == 0 && a[1] == 1 && a[2] == 2) {
            cout << "0\n";
            return;
        }
        if (a[0] == 2 && a[1] == 1 && a[2] == 0) {
            cout << "1\n3\n";
            return;
        }
        return;
    }
    ans.clear();
    for (int x = n; x >= 3; x -= 2) {
        if (a[x - 1] == x - 1 && a[x - 2] == x - 2) {
            continue;
        }
        for (int i = 0; i < x; i++) {
            if (a[i] == x - 1) {
                add(i + 1);
                break;
            }
        }
        for (int i = 0; i < x; i++) {
            if (a[i] == x - 2) {
                add(i);
                add(i + 2);
                break;
            }
        }
        add(3);
        add(x);
    }
#ifdef ONPC
    for (int i = 0; i < n; i++) {
        assert(a[i] == i);
    }
#endif
    cout << ans.size() << "\n";
    for (int i : ans) {
        cout << i << " ";
    }
    cout << "\n";
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