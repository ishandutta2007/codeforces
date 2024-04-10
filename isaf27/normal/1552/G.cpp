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
const int B = 50;
const int X = 15;

int n, k, type[B];
vector<int> pos[X], nw[X];

int was[B][B];

void gen(int b) {
    if (b == k) {
        for (int i = 1; i < n; i++) {
            if (type[i - 1] > type[i]) {
                cout << "REJECTED\n";
                exit(0);
            }
        }
        return;
    }
    memcpy(was[b], type, sizeof(int) * n);
    int cnt = 0;
    for (int j : pos[b]) {
        if (type[j] == 0) {
            cnt++;
        }
    }
    for (int j = 0; j < (int)pos[b].size(); j++) {
        if (j < cnt) {
            type[pos[b][j]] = 0;
        } else {
            type[pos[b][j]] = 1;
        }
    }
    gen(b + 1);
    for (int t = 0; t < nw[b].size(); t++) {
        type[pos[b][cnt + t]] = 0;
        gen(b + 1);
    }
    memcpy(type, was[b], sizeof(int) * n);
}

int32_t main() {
#ifdef ONPC
    freopen("input", "r", stdin);
#endif
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> n >> k;
    if (n == 1) {
        cout << "ACCEPTED\n";
        return 0;
    }
    for (int i = 0; i < k; i++) {
        int s;
        cin >> s;
        pos[i].resize(s);
        for (int j = 0; j < s; j++) {
            cin >> pos[i][j];
            pos[i][j]--;
        }
    }
    for (int i = 0; i < n; i++) {
        type[i] = 2;
    }
    for (int i = 0; i < k; i++) {
        for (int j : pos[i]) {
            if (type[j] == 2) {
                nw[i].emplace_back(j);
                type[j] = 1;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        if (type[i] == 2) {
            cout << "REJECTED\n";
            return 0;
        }
    }
    for (int i = 0; i < n; i++) {
        type[i] = 2;
    }
    gen(0);
    cout << "ACCEPTED\n";
    return 0;
}