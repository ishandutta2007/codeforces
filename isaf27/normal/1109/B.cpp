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
const ll bt = 31;
const ld eps = 1e-8;
const ll INF = 1e18 + 239;
const int BIG = 1e9 + 239;
const int MOD = 998244353; //1e9 + 7;
const ll MOD2 = (ll)MOD * (ll)MOD;

//random
mt19937_64 rnd(239); //rnd(chrono::high_resolution_clock::now().time_since_epoch().count())

//constants
const int M = 3e5 + 239;
const int N = 2e3 + 239;
const int L = 20;
const int T = (1 << 20);
const int B = trunc(sqrt(M)) + 1;
const int X = 1e4 + 239;

string s;
int n;

inline bool check(int l, int r)
{
    for (int i = l; i < r; i++)
        if (s[i] != s[l + r - 1 - i])
            return false;
    return true;
}

int32_t main()
{
    #ifdef ONPC
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> s;
    n = (int)s.size();
    bool ch = true;
    for (int i = 0; i < (n / 2); i++)
        if (s[i] != s[0])
            ch = false;
    if (ch)
    {
        cout << "Impossible";
        return 0;
    }
    s += s;
    for (int i = 1; i < n; i++)
        if (check(i, i + n))
        {
            bool ok = false;
            for (int x = 0; x < n; x++)
                if (s[x] != s[i + x])
                {
                    ok = true;
                    break;
                }
            if (ok)
            {
                cout << "1";
                return 0;
            }
        }
    cout << "2";
    return 0;
}