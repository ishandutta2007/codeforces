#pragma GCC optimize("O3")
#pragma GCC optimize("popcnt")
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
const ld eps = 1e-10;
const ll INF = (ll)(1e18 + 239);
const int BIG = (int)(1e9 + 239);
const int MOD = 998244353; //(int)(1e9 + 7); //;
const ll MOD2 = (ll)MOD * (ll)MOD;

//random
mt19937 rnd(239); //(chrono::high_resolution_clock::now().time_since_epoch().count());

//constants
const int M = (int)(4e5 + 239);
const int N = (int)(2e3 + 239);
const int L = 20;
const int T = (1 << 18) + 239;
const int B = 500;
const int X = 1e4 + 239;

vector<int> al;
int a[M], n, c[M], k;

int32_t main()
{
#ifdef ONPC
    freopen("input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        al.push_back(a[i]);
    }
    sort(al.begin(), al.end());
    al.resize(unique(al.begin(), al.end()) - al.begin());
    for (int i = 0; i < n; i++)
        a[i] = lower_bound(al.begin(), al.end(), a[i]) - al.begin();
    k = (int)al.size();
    for (int i = 0; i < n; i++)
        c[a[i]]++;
    int p = 1;
    int q = 1;
    int sqr = 1;
    for (int i = 1; i * i <= n; i++)
    {
        int cur = 0;
        for (int j = 0; j < k; j++)
            cur += min(i, c[j]);
        int j = (cur / i);
        if (j >= i && i * j > sqr)
        {
            p = i;
            q = j;
            sqr = i * j;
        }
    }
    cout << p * q << "\n";
    cout << p << " " << q << "\n";
    vector<pair<int, int>> sm;
    for (int i = 0; i < k; i++)
        sm.push_back(make_pair(min(p, c[i]), al[i]));
    sort(sm.rbegin(), sm.rend());
    vector<int> val;
    for (pair<int, int> t : sm)
        for (int i = 0; i < t.first; i++)
            val.push_back(t.second);
    val.resize(p * q);
    vector<vector<int>> ans(p);
    for (int i = 0; i < p; i++)
        ans[i].resize(q);
    int c = 0;
    for (int j = 0; j < q; j++)
        for (int i = 0; i < p; i++)
            ans[i][(i + j) % q] = val[c++];
    for (int i = 0; i < p; i++)
    {
        for (int j = 0; j < q; j++)
            cout << ans[i][j] << " ";
        cout << "\n";
    }
    return 0;
}