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
//const ll bt = 30;
const ld eps = 1e-8;
const ll INF = 1e18 + 239;
const int BIG = 2e9 + 239;
const ll MOD = 1e9 + 7; //998244353; //998244353;
const ll MOD2 = (ll)MOD * (ll)MOD;

//random
mt19937 rnd(239); //rnd(chrono::high_resolution_clock::now().time_since_epoch().count())

//constants
const int M = 1e5 + 239;
const int N = 2e3 + 239;
const int L = 60;
const int LT = 100;
const int T = (1 << 20);
const int B = trunc(sqrt(M)) + 1;
const int X = 7010;

typedef bitset<X> bt;

bt ad[X], as[X];
bt a[M];
int n, q, t, x, y, z, v, mb[X];

int main()
{
    #ifdef ONPC
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    ios::sync_with_stdio(0); cin.tie(); cout.tie(0);
    cin >> n >> q;
    for (int i = 0; i < n; i++) a[i] = 0;
    for (int i = 1; i < X; i++)
    {
        ad[i] = 0;
        for (int j = 1; j <= i; j++)
            if (i % j == 0)
                ad[i][j] = 1;
    }
    for (int i = 1; i < X; i++)
    {
        mb[i] = 1;
        for (int j = 2; j * j <= i; j++)
            if (i % (j * j) == 0)
            {
                mb[i] = 0;
                break;
            }
    }
    for (int i = 1; i < X; i++)
    {
        as[i] = 0;
        for (int j = i; j < X; j += i)
            if (mb[j / i] == 1)
                as[i][j] = 1;
    }
    string ans = "";
    for (int i = 0; i < q; i++)
    {
        cin >> t;
        if (t == 1)
        {
            cin >> x >> v;
            a[x - 1] = ad[v];
        }
        else if (t == 2)
        {
            cin >> x >> y >> z;
            x--, y--, z--;
            a[x] = (a[y] ^ a[z]);
        }
        else if (t == 3)
        {
            cin >> x >> y >> z;
            x--, y--, z--;
            a[x] = (a[y] & a[z]);
        }
        else
        {
            cin >> x >> v;
            x--;
            ans += (char)('0' + (char)((a[x] & as[v]).count() & 1));
        }
    }
    cout << ans;
    return 0;
}