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
const ll INF = (ll)(2e18 + 239);
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
const int M = (int)(1e5 + 239);
const int N = (int)(2e3 + 10);
const int L = 21;
const int T = (1 << 13) + 239;
const int B = 510;
const int X = 60;

int n, a[X];

int32_t main() {
#ifdef ONPC
    freopen("input", "r", stdin);
#endif
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i]--;
    }
    vector<vector<int>> answer;
    int need_rev = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == i) {
            continue;
        }
        int p = -1;
        for (int j = i + 1; j < n; j++) {
            if (a[j] == i) {
                p = j;
                break;
            }
        }
        vector<int> cur;
        for (int x = 0; x < i; x++) {
            cur.emplace_back(1);
        }
        cur.emplace_back(p - i + 1);
        for (int x = p + 1; x < n; x++) {
            cur.emplace_back(1);
        }
        if (need_rev) {
            reverse(cur.begin(), cur.end());
        }
        if (cur.size() >= 2) {
            answer.emplace_back(cur);
        }
        need_rev ^= 1;
        reverse(a + i, a + p + 1);
    }
    if (need_rev) {
        if (n >= 2) {
            answer.emplace_back(n, 1);
        }
    }
    cout << answer.size() << "\n";
    for (const auto& t : answer) {
        cout << t.size() << " ";
        for (int i : t) {
            cout << i << " ";
        }
        cout << "\n";
    }
    return 0;
}