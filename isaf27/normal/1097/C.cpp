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
const int N = 2e3 + 239;
const int L = 20;
const int T = (1 << 20);
const int B = trunc(sqrt(M)) + 1;
const int X = 100;

int n, b[M], mn[M], kl[M], kr[M];
string s[M];

int main()
{
    #ifdef ONPC
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    ios::sync_with_stdio(0); cin.tie(); cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> s[i];
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        b[i] = 0;
        mn[i] = 0;
        for (int x = 0; x < (int)s[i].size(); x++)
        {
            if (s[i][x] == '(')
                b[i]++;
            else
                b[i]--;
            mn[i] = min(mn[i], b[i]);
        }
        if (b[i] == 0 && mn[i] < 0) continue;
        if (b[i] == 0)
        {
            ans++;
            continue;
        }
        if (b[i] > 0 && mn[i] < 0) continue;
        if (b[i] > 0)
        {
            kl[b[i]]++;
            continue;
        }
        b[i] = -b[i];
        if (mn[i] + b[i] < 0) continue;
        kr[b[i]]++;
    }
    ans /= 2;
    for (int i = 1; i < M; i++)
        ans += min(kl[i], kr[i]);
    cout << ans;
    return 0;
}