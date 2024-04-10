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
const int T = (1 << 18) + 239;
const int B = 510;
const int X = 110;

int n, a[M], b[M];
vector<int> in[M];

void answer() {
    int good = 0;
    for (int i = 0; i < n; i++) {
        good += (a[i] == b[i]);
    }
    cout << good << "\n";
    for (int i = 0; i < n; i++) {
        cout << b[i] + 1 << " ";
    }
    cout << "\n";
}

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i]--;
        b[i] = -1;
        in[i].clear();
    }
    if (n == 2) {
        b[0] = 1;
        b[1] = 0;
        answer();
        return;
    }
    for (int i = 0; i < n; i++) {
        if (a[i] != i) {
            in[a[i]].emplace_back(i);
        }
    }
    vector<int> vals;
    for (int i = 0; i < n; i++) {
        if (!in[i].empty()) {
            b[in[i][0]] = i;
        } else {
            vals.emplace_back(i);
        }
    }
    if (vals.empty()) {
        answer();
        return;
    }
    if (vals.size() >= 2) {
        vector<int> pos;
        for (int i = 0; i < n; i++) {
            if (b[i] == -1) {
                pos.emplace_back(i);
            }
        }
        while (pos.size() >= 2) {
            if (pos.back() == vals.back() || (pos.size() == 2 && pos[0] == vals[0])) {
                swap(pos[(int)pos.size() - 2], pos[(int)pos.size() - 1]);
            }
            b[pos.back()] = vals.back();
            pos.pop_back();
            vals.pop_back();
        }
        b[pos.back()] = vals.back();
        answer();
        return;
    }
    if (b[vals[0]] != -1) {
        for (int i = 0; i < n; i++) {
            if (b[i] == -1) {
                b[i] = vals[0];
            }
        }
        answer();
        return;
    }
    if (vals[0] == a[vals[0]]) {
        b[vals[0]] = vals[0];
        swap(b[vals[0]], b[(vals[0] + 1) % n]);
        answer();
        return;
    }
    int idx = a[vals[0]];
    assert(in[idx].size() == 2);
    swap(b[in[idx][0]], b[in[idx][1]]);
    b[in[idx][0]] = vals[0];
    answer();
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