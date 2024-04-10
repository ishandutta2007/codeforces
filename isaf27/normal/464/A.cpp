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
const int BIG = 2e9 + 239;
const ll MOD = 998244353; //1e9 + 7;
const ll MOD2 = (ll)MOD * (ll)MOD;

//random
mt19937_64 rnd(239); //(chrono::high_resolution_clock::now().time_since_epoch().count());

//constants
const int M = 2e5 + 239;
const int N = 2e3 + 239;
const int L = 19;
const int T = (1 << 18);
const int B = trunc(sqrt(M)) + 1;
const int X = 1e4 + 239;

int n, p;
string s;

int32_t main()
{
    #ifdef ONPC
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> p >> s;
    if (p == 1 || (p == 2 && n > 2))
    {
        cout << "NO";
        return 0;
    }
    if (p == 2)
    {
        if (n == 1 && s == "b")
        {
            cout << "NO";
            return 0;
        }
        else if (n == 1)
        {
            cout << "b";
            return 0;
        }
        if (n == 2 && s == "ba")
        {
            cout << "NO";
            return 0;
        }
        else
        {
            cout << "ba";
            return 0;
        }
        return 0;
    }
    for (int i = n - 1; i >= 0; i--)
        if (s[i] - 'a' != p - 1)
        {
            string t = s;
            bool ch = false;
            while (t[i] - 'a' != p - 1)
            {
                t[i]++;
                if (i > 0 && t[i] == t[i - 1]) continue;
                if (i > 1 && t[i] == t[i - 2]) continue;
                ch = true;
                break;
            }
            if (!ch) continue;
            for (int x = i + 1; x < n; x++)
            {
                t[x] = (char)('a' - 1);
                while (t[x] - 'a' != p - 1)
                {
                    t[x]++;
                    if (x > 0 && t[x] == t[x - 1]) continue;
                    if (x > 1 && t[x] == t[x - 2]) continue;
                    break;
                }
            }
            cout << t;
            return 0;
        }
    cout << "NO";
    return 0;
}