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
const int M = (int)(4e5 + 239);
const int N = (int)(2e3 + 10);
const int L = 21;
const int T = (1 << 18) + 239;
const int B = 510;
const int X = 2010;

int n;
bool used[X][X];
bool asked[X];

vector<int> ask(int p) {
    if (asked[p]) {
        return {};
    }
    asked[p] = true;
    cout << "? " << p + 1 << endl;
    vector<int> ans(n);
    for (int i = 0; i < n; i++) {
        cin >> ans[i];
        if (ans[i] == 1) {
            used[p][i] = true;
            used[i][p] = true;
        }
    }
    return ans;
}

int32_t main() {
#ifdef ONPC
    //freopen("input", "r", stdin);
#endif
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> n;
    vector<int> d = ask(0);
    vector<int> a, b;
    for (int i = 0; i < n; i++) {
        if (d[i] % 2 == 0) {
            a.emplace_back(i);
        } else {
            b.emplace_back(i);
        }
    }
    if (a.size() > b.size()) {
        swap(a, b);
    }
    for (int i : a) {
        ask(i);
    }
    cout << "!" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (used[i][j]) {
                cout << i + 1 << " " << j + 1 << endl;
            }
        }
    }
    return 0;
}