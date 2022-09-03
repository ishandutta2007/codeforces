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
const int T = (1 << 20) + 239;
const int B = 510;
const int X = 110;

int n;
ll k;

bool make[M];

void solve() {
    cin >> n >> k;
    if (n <= 61) {
        ll x = (1LL << (ll)(n - 1));
        if (k > x) {
            cout << "-1\n";
            return;
        }
    }
    k--;
    for (int i = 0; i < n - 1; i++) {
        make[i] = true;
    }
    for (int i = 0; i < n - 1; i++) {
        if (k & 1LL) {
            make[n - i - 2] = false;
        }
        k /= 2LL;
    }
    vector<int> pos;
    pos.emplace_back(0);
    for (int i = 0; i < n - 1; i++) {
        if (make[i]) {
            pos.emplace_back(i + 1);
        }
    }
    pos.emplace_back(n);
    vector<int> ans(n);
    iota(ans.begin(), ans.end(), 0);
    for (int i = 0; i + 1 < (int)pos.size(); i++) {
        reverse(ans.begin() + pos[i], ans.begin() + pos[i + 1]);
    }
    for (int i : ans) {
        cout << i + 1 << " ";
    }
    cout << "\n";
}

void slow(int n) {
    cout << n << "\n";
    int count = 0;
    vector<int> p(n);
    iota(p.begin(), p.end(), 0);
    do {
        bool ch = true;
        for (int i = 0; i + 1 < n; i++) {
            ch &= (p[i + 1] >= p[i] - 1);
        }
        if (ch) {
            count++;
            for (int i = 0; i + 1 < n; i++) {
                cout << p[i + 1] - p[i] << " ";
            }
            cout << "\n";
        }
    } while (next_permutation(p.begin(), p.end()));
    cout << count << "\n";
}

int32_t main() {
#ifdef ONPC
    freopen("input", "r", stdin);
#endif
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    /*for (int n = 1; n <= 10; n++) {
        slow(n);
    }
    return 0;*/
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}