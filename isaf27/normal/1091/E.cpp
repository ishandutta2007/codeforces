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
const int M = 5e5 + 239;
const int N = 1e3 + 239;
const int L = 20;
const int T = (1 << 20);
const int B = trunc(sqrt(M)) + 1;
const int X = 1e6 + 239;

int n, gr[M];
ll a[M], f[two][M], pref[M];

ll gett(int l, int r)
{
    return (pref[r + 1] - pref[l]);
}

int main()
{
    #ifdef ONPC
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a + n);
    reverse(a, a + n);
    pref[0] = 0;
    for (int i = 0; i < n; i++)
        pref[i + 1] = pref[i] + a[i];
    int pr = n;
    for (int i = 0; i <= n; i++)
    {
        gr[i] = pr;
        while (gr[i] > 0 && a[gr[i] - 1] <= i) gr[i]--;
        pr = gr[i];
    }
    for (int k = 1; k <= n; k++)
    {
        f[0][k] = -pref[k - 1];
        f[0][k] += (ll)k * (ll)(k - 1);
        f[0][k] += gett(max(k - 1, gr[k]), n - 1);
        f[0][k] += (ll)(max(gr[k], k - 1) - (k - 1)) * (ll)k;
    }
    for (int i = n - 1; i >= 0; i--)
        f[0][i] = min(f[0][i], f[0][i + 1]);
    for (int k = 1; k <= n; k++)
    {
        f[1][k] = pref[k];
        f[1][k] -= (ll)k * (ll)(k - 1);
        f[1][k] -= gett(max(k, gr[k]), n - 1);
        f[1][k] -= (ll)(max(gr[k], k) - k) * (ll)k;
        if (k < f[1][k]) f[1][k] = n + 1;
    }
    f[1][0] = 0;
    for (int i = 1; i <= n; i++)
        f[1][i] = max(f[1][i], f[1][i - 1]);
    ll s = 0;
    for (int i = 0; i < n; i++)
        s += a[i];
    s %= 2LL;
    vector<int> ans;
    for (int i = 0; i <= n; i++)
    {
        if ((i + s) % 2 != 0) continue;
        int p = gr[i];
        if (p < n && f[0][p + 1] < i) continue;
        if (p > 0 && f[1][p] > i) continue;
        ans.push_back(i);
    }
    if (ans.empty())
        cout << "-1";
    else
    {
        for (int i : ans)
            cout << i << " ";
    }
    return 0;
}