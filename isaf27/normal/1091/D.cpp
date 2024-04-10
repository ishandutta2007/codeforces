/*
    Author: isaf27 (Ivan Safonov)
*/

#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

//defines
typedef long long ll;
typedef long double ld;
#define TIME clock() * 1.0 / CLOCKS_PER_SEC

//permanent constants
const ld pi = acos(-1.0);
const ld log23 = 1.58496250072115618145373894394781;
const int day[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
const int digarr[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};
const int dxo[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
const int dyo[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
const int alf = 26;
const int dig = 10;
const int two = 2;
const int th = 3;
const ll prost = 239;
const ll bt = 30;
const ld eps = 1e-8;
const ll INF = 1e18 + 239;
const int BIG = 2e9 + 239;
const ll MOD = 998244353; //998244353;
const ll MOD2 = (ll)MOD * (ll)MOD;

//random
mt19937 rnd(239); //rnd(chrono::high_resolution_clock::now().time_since_epoch().count())

//constants
const int M = 2e5 + 239;
const int N = 1e3 + 239;
const int L = 20;
const int T = (1 << 20);
const int B = trunc(sqrt(M)) + 1;
const int X = 1e6 + 239;

int n, pref[X];

int main()
{
    #ifdef ONPC
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    cin >> n;
    pref[n] = 1;
    for (int i = n - 1; i >= 0; i--)
        pref[i] = (1LL * (ll)(i + 1) * pref[i + 1]) % MOD;
    ll ans = (1LL * pref[0] * (ll)(n + 1)) % MOD;
    for (int i = 0; i <= n; i++)
    {
        ans -= pref[i];
        if (ans < 0) ans += MOD;
    }
    ans = (ans + 1) % MOD;
    cout << ans;
    return 0;
}