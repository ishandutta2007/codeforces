//#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

//defines
typedef long long ll;
typedef long double ld;
#define TIME clock() * 1.0 / CLOCKS_PER_SEC
#define prev _prev
#define y0 _y0
#define kill _kill

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
const int MOD = 1e9 + 7;

//random
mt19937_64 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());

//constants
const int M = (int)(2e5 + 239);
const int N = (int)(2e3 + 239);
const int L = 18;
const int T = (1 << 18) + 239;
const int B = 500;
const int X = 1010;
const int S = 4 * X * X;

int n, m, q, dist[X][X];
string s[X];
pair<int, int> my_q[S];
int l, r;

bool check(int i, int j)
{
    return (0 <= i && i < n && 0 <= j && j < m);
}

int32_t main()
{
#ifdef ONPC
    freopen("input", "r", stdin);
#endif
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m >> q;
    for (int i = 0; i < n; i++)
        cin >> s[i];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            dist[i][j] = BIG;
    l = (S / 2);
    r = (S / 2);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            bool ch = false;
            for (int d = 0; d < 4; d++)
            {
                int ni = i + dx[d];
                int nj = j + dy[d];
                if (check(ni, nj) && s[i][j] == s[ni][nj])
                {
                    ch = true;
                    break;
                }
            }
            if (ch)
            {
                my_q[r++] = make_pair(i, j);
                dist[i][j] = 0;
            }
        }
    while (l < r)
    {
        int i = my_q[l].first;
        int j = my_q[l].second;
        l++;
        for (int d = 0; d < 4; d++)
        {
            int ni = i + dx[d];
            int nj = j + dy[d];
            if (check(ni, nj))
            {
                if (s[ni][nj] == s[i][j])
                {
                    if (dist[ni][nj] > dist[i][j])
                    {
                        dist[ni][nj] = dist[i][j];
                        l--;
                        my_q[l] = make_pair(ni, nj);
                    }
                }
                else
                {
                    if (dist[ni][nj] > dist[i][j] + 1)
                    {
                        dist[ni][nj] = dist[i][j] + 1;
                        my_q[r++] = make_pair(ni, nj);
                    }
                }
            }
        }
    }
    for (int i = 0; i < q; i++)
    {
        int x, y;
        ll t;
        cin >> x >> y >> t;
        x--, y--;
        if (dist[x][y] == BIG)
            cout << s[x][y] << "\n";
        else
        {
            if (t <= dist[x][y])
                cout << s[x][y] << "\n";
            else
            {
                int ev = (t - dist[x][y]) % 2LL;
                if (ev == 0)
                    cout << s[x][y] << "\n";
                else
                    cout << (char)('0' + '1' - s[x][y]) << "\n";
            }
        }
    }
    return 0;
}