//#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

//defines
typedef long long ll;
typedef long double ld;
#define TIME clock() * 1.0 / CLOCKS_PER_SEC
#define prev _prev
#define y0 y00

//permanent constants
const ld pi = acos(-1.0);
const int day[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
const int digarr[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};
const int dxo[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
const int dyo[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
const int alf = 26;
const int dig = 10;
const int two = 2;
const int th = 3;
const ll prost = 239;
const ll bt = 30;
const ld eps = 1e-8;
const ll INF = (ll)(1e18 + 239);
const int BIG = (int)(1e9 + 239);
const int MOD = 998244353;
const ll MOD2 = (ll)MOD * (ll)MOD;

//random
mt19937 rnd(239); //(chrono::high_resolution_clock::now().time_since_epoch().count());

//constants
const int M = (int)(1e6 + 239);
const int N = (int)(2e3 + 239);
const int L = 18;
const int T = (1 << 20);
const int B = (int)sqrt(M);
const int X = 1e4 + 239;

string s;
ll pref[M], suf[M];

int32_t main()
{
#ifdef ONPC
    freopen("input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> s;
    pref[0] = 0;
    int n = s.size();
    for (int i = 0; i < n; i++)
    {
        pref[i + 1] = pref[i];
        if (i > 0 && s[i] == s[i - 1] && s[i] == 'v')
            pref[i + 1]++;
    }
    suf[n] = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        suf[i] = suf[i + 1];
        if (i < n - 1 && s[i] == s[i + 1] && s[i] == 'v')
            suf[i]++;
    }
    ll ans = 0;
    for (int i = 0; i < n; i++)
        if (s[i] == 'o')
            ans += pref[i] * suf[i + 1];
    cout << ans;
    return 0;
}