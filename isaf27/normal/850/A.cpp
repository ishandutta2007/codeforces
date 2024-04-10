//#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

//defines
typedef long long ll;
typedef double ld;
#define TIME clock() * 1.0 / CLOCKS_PER_SEC
#define prev _prev
#define y0 _y0
//#define int ll

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
const ll btc = 30;
const ld eps = 1e-8;
const ll INF = (ll)(1e18 + 239);
const int BIG = (int)(1e9 + 239);
const ll MOD = (int)(1e9 + 7); //998244353;
const ll MOD2 = (ll)MOD * (ll)MOD;

//random
mt19937_64 rnd(239); //(chrono::high_resolution_clock::now().time_since_epoch().count());

//constants
const int M = (int)(2e5 + 239);
const int N = (int)(2e3 + 239);
const int L = 18;
const int T = (1 << 19);
const int B = 500;
const int X = 1010;

int n, x[5][X];

int32_t main()
{
#ifdef ONPC
    freopen("input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < 5; j++)
            cin >> x[j][i];
    if (n > 200)
    {
        cout << "0\n";
        return 0;
    }
    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        bool ch = true;
        for (int j = 0; j < n && ch; j++)
            for (int h = 0; h < n && ch; h++)
                if (j != h && j != i && h != i)
                {
                    int now = 0;
                    for (int t = 0; t < 5; t++)
                        now += (x[t][j] - x[t][i]) * (x[t][h] - x[t][i]);
                    if (now > 0)
                    {
                        ch = false;
                        break;
                    }
                }
        if (ch)
            ans.push_back(i);
    }
    cout << ans.size() << "\n";
    for (int i : ans)
        cout << i + 1 << " ";
    return 0;
}