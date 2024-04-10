#pragma GCC optimize("O3")
#pragma GCC optimize ("unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

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
const int BIG = (int)(1e9) + 239;
const int MOD = 998244353; //1e9 + 7;
const ll MOD2 = (ll)MOD * (ll)MOD;

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
const int X = 35;

void print(const vector<int>& p, bool change) {
    for (int i = 0; i < (int)p.size(); i++) {
        int value = p[i];
        if (change) {
            value = p.size() - 1 - value;
        }
        cout << value + 1 << " ";
    }
    cout << "\n";
}

void solve() {
    int n, a, b;
    cin >> n >> a >> b;
    if (a > (n - 1) / 2 || b > (n - 1) / 2 || a + b > n - 2 || abs(a - b) > 1) {
        cout << "-1\n";
        return;
    }
    bool change = false;
    if (a < b) {
        change = true;
        swap(a, b);
    }
    vector<int> p(n);
    iota(p.begin(), p.end(), 0);
    if (a == b) {
        for (int i = 0; i < a; i++) {
            swap(p[2 * i + 1], p[2 * i + 2]);
        }
        print(p, change);
        return;
    }
    reverse(p.begin(), p.end());
    for (int i = 0; i < b + 1; i++) {
        swap(p[2 * i], p[2 * i + 1]);
    }
    print(p, change);
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