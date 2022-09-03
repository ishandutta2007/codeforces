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
const int MOD = 1e9 + 7; //

//random
mt19937 rnd(239); //(chrono::high_resolution_clock::now().time_since_epoch().count());

//constants
const int M = (int)(1e6 + 239);
const int N = (int)(2e3 + 239);
const int L = 20;
const int T = (1 << 18) + 239;
const int B = 500;
const int X = 50;

int n;
pair<ll, ll> line[M];

ld inter(int i, int j)
{
    return (ld)(line[i].first - line[j].first) / (ld)(line[j].second - line[i].second);
}

int32_t main()
{
#ifdef ONPC
    freopen("input", "r", stdin);
#endif
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    line[0] = make_pair(0, 0);
    ll s = 0;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        s += a;
        line[i + 1] = make_pair(s, -(i + 1));
    }
    vector<pair<ld, int>> st;
    for (int i = 0; i <= n; i++)
    {
        while (!st.empty())
        {
            int l = st.back().second;
            ld x = inter(l, i);
            if (x <= st.back().first)
            {
                st.pop_back();
                continue;
            }
            st.push_back(make_pair(x, i));
            break;
        }
        if (st.empty())
            st.push_back(make_pair(-INF, 0));
    }
    cout << fixed << setprecision(15);
    for (int i = 0; i + 1 < (int)st.size(); i++)
    {
        ld now = (ld)(line[st[i + 1].second].first - line[st[i].second].first) / (st[i + 1].second - st[i].second);
        for (int it = st[i].second; it < st[i + 1].second; it++)
            cout << now << "\n";
    }
    return 0;
}