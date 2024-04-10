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
const int M = (int)(1e6 + 239);
const int N = (int)(2e3 + 10);
const int L = 21;
const int T = (1 << 13) + 239;
const int B = 510;
const int X = 60;

vector<tuple<int, ll, ll>> operations;

int func(ll x) {
    for (ll i = 2; ; i++) {
        ll to = ((i + 1) * x) ^ (i * x) ^ (2LL * x);
        if (to < x) {
            return i;
        }
    }
}

void make(ll x, ll t) {
    if (t == 1) {
        return;
    }
    ll to = t / 2;
    make(x, to);
    operations.emplace_back(0, to * x, to * x);
    if (t % 2 == 1) {
        operations.emplace_back(0, 2 * to * x, x);
    }
}

int32_t main() {
#ifdef ONPC
    freopen("input", "r", stdin);
#endif
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll x;
    cin >> x;
    while (x != 1) {
        ll t = func(x);
        make(x, t);
        operations.emplace_back(0, t * x, x);
        operations.emplace_back(0, x, x);
        operations.emplace_back(1, t * x, (t + 1) * x);
        operations.emplace_back(1, (t * x) ^ ((t + 1) * x), x * 2LL);
        x = (t * x) ^ ((t + 1) * x) ^ (x * 2LL);
    }
    cout << operations.size() << "\n";
    for (const auto& t : operations) {
        if (get<0>(t) == 0) {
            cout << get<1>(t) << " + " << get<2>(t) << "\n";
        } else {
            cout << get<1>(t) << " ^ " << get<2>(t) << "\n";
        }
    }
    return 0;
}