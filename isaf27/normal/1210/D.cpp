//#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

//defines
typedef long long ll;
typedef double ld;
#define TIME clock() * 1.0 / CLOCKS_PER_SEC
#define prev _prev
#define y0 _y0

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
const ll bt = 30;
const ld eps = 1e-8;
const ll INF = (ll)(1e18 + 239);
const int BIG = (int)(1e9 + 239);
const ll MOD = (int)(1e9 + 7); //998244353;
const ll MOD2 = (ll)MOD * (ll)MOD;

//random
mt19937_64 rnd(239); //(chrono::high_resolution_clock::now().time_since_epoch().count());

//constants
const int M = (int)(1e5 + 239);
const int N = (int)(2e3 + 239);
const int L = 18;
const int T = (1 << 19);
const int B = 500;
const int X = 1e4 + 239;

int n, m;
ll cnt_l[M], cnt_r[M], deg[M];
vector<int> r[M];

int32_t main()
{
#ifdef ONPC
    freopen("input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int s, f;
        cin >> s >> f;
        if (s > f)
            swap(s, f);
        s--, f--;
        cnt_r[s]++;
        r[s].push_back(f);
        cnt_l[f]++;
        deg[s]++;
        deg[f]++;
    }
    ll cur = 0;
    for (int i = 0; i < n; i++)
        cur += cnt_l[i] * cnt_r[i];
    cout << cur << "\n";
    int q;
    cin >> q;
    for (int z = 0; z < q; z++)
    {
        int i;
        cin >> i;
        i--;
        cur -= cnt_l[i] * cnt_r[i];
        for (int t : r[i])
        {
            cur -= cnt_r[t];
            r[t].push_back(i);
            cnt_l[t]--;
            cnt_r[t]++;
            cur += cnt_l[t];
        }
        cnt_l[i] = deg[i];
        cnt_r[i] = 0;
        r[i].clear();
        cout << cur << "\n";
    }
    return 0;
}