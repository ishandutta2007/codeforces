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
const ld eps = 1e-10;
const ll INF = (ll)(1e18 + 239);
const int BIG = (int)(1e9 + 239);
const int MOD = (int)(1e9 + 7); //998244353;
const ll MOD2 = (ll)MOD * (ll)MOD;

//random
mt19937 rnd(239); //(chrono::high_resolution_clock::now().time_since_epoch().count());

//constants
const int M = (int)(2e5 + 239);
const int N = (int)(2e3 + 239);
const int L = 19;
const int T = (1 << 20);
const int B = 500;
const int X = 50;

int n, l1[M], r1[M], l2[M], r2[M], k;
vector<int> v1, v2;
vector<int> open[M], close[M];

bool check()
{
    for (int i = 0; i < k; i++)
    {
        open[i].clear();
        close[i].clear();
    }
    for (int i = 0; i < n; i++)
    {
        open[l1[i]].push_back(i);
        close[r1[i]].push_back(i);
    }
    multiset<int> mnr;
    multiset<int> mxl;
    for (int i = 0; i < k; i++)
    {
        for (int t : open[i])
        {
            mnr.insert(r2[t]);
            mxl.insert(l2[t]);
        }
        if (!mnr.empty())
        {
            int mn_value = *mnr.begin();
            int mx_value = *mxl.rbegin();
            if (mx_value > mn_value)
                return false;
        }
        for (int t : close[i])
        {
            mnr.erase(mnr.lower_bound(r2[t]));
            mxl.erase(mxl.lower_bound(l2[t]));
        }
    }
    return true;
}

int32_t main()
{
#ifdef ONPC
    freopen("input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> l1[i] >> r1[i] >> l2[i] >> r2[i];
        v1.push_back(l1[i]);
        v1.push_back(r1[i]);
        v2.push_back(l2[i]);
        v2.push_back(r2[i]);
    }
    sort(v1.begin(), v1.end());
    v1.resize(unique(v1.begin(), v1.end()) - v1.begin());
    sort(v2.begin(), v2.end());
    v2.resize(unique(v2.begin(), v2.end()) - v2.begin());
    for (int i = 0; i < n; i++)
    {
        l1[i] = lower_bound(v1.begin(), v1.end(), l1[i]) - v1.begin();
        r1[i] = lower_bound(v1.begin(), v1.end(), r1[i]) - v1.begin();
        l2[i] = lower_bound(v2.begin(), v2.end(), l2[i]) - v2.begin();
        r2[i] = lower_bound(v2.begin(), v2.end(), r2[i]) - v2.begin();
    }
    k = max((int)v1.size(), (int)v2.size());
    if (!check())
    {
        cout << "NO\n";
        return 0;
    }
    for (int i = 0; i < n; i++)
    {
        swap(l1[i], l2[i]);
        swap(r1[i], r2[i]);
    }
    if (!check())
    {
        cout << "NO\n";
        return 0;
    }
    cout << "YES\n";
    return 0;
}