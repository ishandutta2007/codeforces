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
const ll MOD = 1e9 + 7; //998244353;
const ll MOD2 = (ll)MOD * (ll)MOD;

//random
mt19937 rnd(239); //rnd(chrono::high_resolution_clock::now().time_since_epoch().count())

//constants
const int M = 2e5 + 239;
const int N = 1e3 + 239;
const int L = 20;
const int T = (1 << 20);
const int B = trunc(sqrt(M)) + 1;
const int X = 1e4 + 239;

ll n;
vector<ll> ans;

void upd(ll k)
{
    ll x = (n / k);
    x += ((x * (x - 1)) / 2LL) * k;
    ans.push_back(x);
}

int main()
{
    #ifdef ONPC
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    cin >> n;
    for (ll d = 1; d * d <= n; d++)
        if (n % d == 0)
        {
            upd(d);
            if (d * d != n) upd(n / d);
        }
    sort(ans.begin(), ans.end());
    ans.resize(unique(ans.begin(), ans.end()) - ans.begin());
    for (ll x : ans)
        cout << x << " ";
    return 0;
}