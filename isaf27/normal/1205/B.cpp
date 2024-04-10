//#pragma GCC optimize("O3")
#ifdef ONPC
#include "bits/stdc++.h"
#else
#include <bits/stdc++.h>
#endif

using namespace std;

//defines
typedef long long ll;
typedef long double ld;
#define TIME clock() * 1.0 / CLOCKS_PER_SEC
#define prev _prev
#define y0 y00
#define y1 y11
#define int ll

//permanent constants
const ld pi = acos(-1.0);
const int day[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
const int digarr[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};
const int dxo[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
const int dyo[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
const int dxk[8] = {-1, -2, -1, 2, -2, 1, 1, 2};
const int dyk[8] = {-2, -1, 2, -1, 1, -2, 2, 1};
const int alf = 26;
const int dig = 10;
const int two = 2;
const int th = 3;
const ll prost = 239;
const ll bt = 30;
const ld eps = 1e-8;
const ll INF = (ll)(1e18 + 239);
const int BIG = (1e9 + 239);
const int MOD = 998244353;
const ll MOD2 = (ll)MOD * (ll)MOD;

//random
mt19937 rnd(239); //(chrono::high_resolution_clock::now().time_since_epoch().count());

//constants
const int M = (int)(1e5 + 239);
const int N = (int)(2e3 + 239);
const int L = 18;
const int T = (1 << 19);
const int B = (int)sqrt(M);
const int X = 130;

int n, k;
ll a[M];
vector<int> v[X];
int dist[X][X];

int32_t main() {
#ifdef ONPC
    freopen("input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        for (ll t = 0; t < 60; t++)
            if (((a[i] >> t) & 1LL) != 0 && v[t].size() <= 2)
                v[t].push_back(i);
    for (ll t = 0; t < 60; t++)
        if (v[t].size() > 2)
        {
            cout << 3;
            return 0;
        }
    vector<int> vx;
    vector<pair<int, int> > rb;
    for (ll t = 0; t < 60; t++)
        if (v[t].size() == 2)
        {
            int i = v[t][0];
            int j = v[t][1];
            vx.push_back(i);
            vx.push_back(j);
            rb.push_back(make_pair(i, j));
        }
    sort(vx.begin(), vx.end());
    vx.resize(unique(vx.begin(), vx.end()) - vx.begin());
    k = vx.size();
    for (pair<int, int>& t : rb)
    {
        t.first = lower_bound(vx.begin(), vx.end(), t.first) - vx.begin();
        t.second = lower_bound(vx.begin(), vx.end(), t.second) - vx.begin();
        if (t.first > t.second)
            swap(t.first, t.second);
    }
    sort(rb.begin(), rb.end());
    rb.resize(unique(rb.begin(), rb.end()) - rb.begin());
    int ans = BIG;
    for (int ig = 0; ig < rb.size(); ig++)
    {
        for (int i = 0; i < k; i++)
            for (int j = 0; j < k; j++)
                dist[i][j] = BIG;
        for (int i = 0; i < k; i++)
            dist[i][i] = 0;
        for (int t = 0; t < rb.size(); t++)
            if (t != ig)
            {
                int x = rb[t].first;
                int y = rb[t].second;
                dist[x][y] = 1;
                dist[y][x] = 1;
            }
        for (int h = 0; h < k; h++)
            for (int i = 0; i < k; i++)
                for (int j = 0; j < k; j++)
                    dist[i][j] = min(dist[i][j], dist[i][h] + dist[h][j]);
        int x = rb[ig].first;
        int y = rb[ig].second;
        ans = min(ans, dist[x][y] + 1);
    }
    if (ans >= BIG)
        ans = -1;
    cout << ans;
    return 0;
}