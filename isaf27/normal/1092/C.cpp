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
const ll bt = 30;
const ld eps = 1e-8;
const ll INF = 1e18 + 239;
const int BIG = 1e9 + 239;
const int MOD = 1e9 + 7; //998244353;
const ll MOD2 = (ll)MOD * (ll)MOD;

//random
mt19937 rnd(239); //rnd(chrono::high_resolution_clock::now().time_since_epoch().count())

//constants
const int M = 2e5 + 239;
const int N = 2e3 + 239;
const int L = 20;
const int T = (1 << 18);
const int B = trunc(sqrt(M)) + 1;
const int X = 1e1 + 239;

int n;
string s[X];
int used[X];

bool check(string t)
{
    for (int i = 0; i < 2 * n - 2; i++)
        used[i] = 0;
    for (int i = 0; i < n - 1; i++)
    {
        string nw = "";
        for (int x = 0; x <= i; x++)
            nw += t[x];
        bool ch = false;
        for (int x = 0; x < (2 * (n - 1)); x++)
            if (!used[x] && s[x] == nw)
            {
                used[x] = 1;
                ch = true;
                break;
            }
        if (!ch) return false;
    }
    for (int i = 1; i < n; i++)
    {
        string nw = "";
        for (int x = i; x < n; x++)
            nw += t[x];
        bool ch = false;
        for (int x = 0; x < (2 * (n - 1)); x++)
            if (!used[x] && s[x] == nw)
            {
                used[x] = -1;
                ch = true;
                break;
            }
        if (!ch) return false;
    }
    return true;
}

int32_t main()
{
    #ifdef ONPC
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    ios::sync_with_stdio(0); cin.tie(); cout.tie(0);
    cin >> n;
    for (int i = 0; i < 2 * n - 2; i++)
        cin >> s[i];
    for (int i = 0; i < 2 * n - 2; i++)
        if (s[i].size() == n - 1)
            for (char x = 'a'; x <= 'z'; x++)
            {
                string nw = s[i];
                nw += x;
                if (check(nw))
                {
                    for (int u = 0; u < (2 * (n - 1)); u++)
                    {
                        if (used[u] == 1)
                            cout << "P";
                        else
                            cout << "S";
                    }
                    return 0;
                }
            }
    return 0;
}