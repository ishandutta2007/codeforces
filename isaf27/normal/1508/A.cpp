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

string s[3];
int a[3][2];
int n;

void solve(const string& l, const string& r, int x) {
    vector<int> pl, pr;
    for (int i = 0; i < 2 * n; i++) {
        if (l[i] - '0' == x) {
            pl.emplace_back(i);
        }
        if (r[i] - '0' == x) {
            pr.emplace_back(i);
        }
    }
    int s = min((int)pl.size(), (int)pr.size());
    pl.resize(s);
    pr.resize(s);
    cout << l.substr(0, pl[0]) << r.substr(0, pr[0]);
    pl.emplace_back(2 * n);
    pr.emplace_back(2 * n);
    for (int i = 0; i < s; i++) {
        cout << x;
        cout << l.substr(pl[i] + 1, pl[i + 1] - pl[i] - 1);
        cout << r.substr(pr[i] + 1, pr[i + 1] - pr[i] - 1);
    }
    cout << "\n";
}

void solve() {
    cin >> n;
    for (int t = 0; t < 3; t++) {
        cin >> s[t];
        a[t][0] = 0;
        a[t][1] = 0;
        for (char x : s[t]) {
            a[t][x - '0']++;
        }
    }
    for (int x = 0; x < 3; x++) {
        for (int y = x + 1; y < 3; y++) {
            for (int d = 0; d < 2; d++) {
                if (a[x][d] >= n && a[y][d] >= n) {
                    solve(s[x], s[y], d);
                    return;
                }
            }
        }
    }
}

int32_t main() {
#ifdef ONPC
    freopen("input", "r", stdin);
#endif
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}