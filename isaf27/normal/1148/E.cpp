//#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

//defines
typedef long long ll;
typedef long double ld;
#define TIME clock() * 1.0 / CLOCKS_PER_SEC
#define prev _prev
#define y0 y00

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
const ld eps = 1e-9;
const ll INF = (ll)(1e18 + 239);
const int BIG = (int)(2e9 + 239);
const int MOD = 998244353; //1e9 + 7;
const ll MOD2 = (ll)MOD * (ll)MOD;

//random
mt19937_64 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());

//constants
const int M = (int)(3e5 + 239);
const int N = (int)(2e3 + 239);
const int L = 20;
const int T = (1 << 20);
const int B = (int)sqrt(M);
const int X = 1e4 + 239;

int n, x, id[M], p[M];
ll pr[M];
vector<pair<int, int> > a, b;

int32_t main()
{
#ifdef ONPC
    freopen("input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        a.push_back(make_pair(x, i));
    }
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        b.push_back(make_pair(x, i));
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    for (int i = 0; i < n; i++)
    {
        p[i] = b[i].first - a[i].first;
        id[i] = a[i].second;
    }
    pr[0] = 0;
    for (int i = 0; i < n; i++)
        pr[i + 1] = pr[i] + (ll)p[i];
    if (pr[n] != 0)
    {
        cout << "NO";
        return 0;
    }
    for (int i = 0; i < n; i++)
        if (pr[i] < 0)
        {
            cout << "NO";
            return 0;
        }
    vector<tuple<int, int, int> > ans;
    cout << "YES\n";
    vector<int> st;
    for (int i = 0; i < n; i++)
    {
        if (p[i] > 0)
        {
            st.push_back(i);
            continue;
        }
        while (p[i] < 0 && !st.empty())
        {
            int x = st.back();
            ans.push_back(make_tuple(id[x], id[i], min(abs(p[x]), abs(p[i]))));
            if (abs(p[x]) > abs(p[i]))
            {
                p[x] += p[i];
                p[i] = 0;
                break;
            }
            p[i] += p[x];
            st.pop_back();
        }
    }
    cout << (int)ans.size() << "\n";
    for (tuple<int, int, int> t : ans)
        cout << get<0>(t) + 1 << " " << get<1>(t) + 1 << " " << get<2>(t) << "\n";
    return 0;
}