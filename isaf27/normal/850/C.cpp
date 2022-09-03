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
const int X = 110;

map<int, vector<int>> mx;

void func(int a)
{
    for (int x = 2; x * x <= a; x++)
        if (a % x == 0)
        {
            int t = 0;
            while (a % x == 0)
            {
                a /= x;
                t++;
            }
            mx[x].push_back(t);
        }
    if (a > 1)
        mx[a].push_back(1);
}

map<vector<int>, int> f;

int grundy(vector<int> v)
{
    sort(v.begin(), v.end());
    v.resize(unique(v.begin(), v.end()) - v.begin());
    reverse(v.begin(), v.end());
    while (!v.empty() && v.back() == 0)
        v.pop_back();
    if (v.empty())
        return 0;
    if (f.find(v) != f.end())
        return f[v];
    vector<bool> to(v[0] + 1, false);
    for (int i = 1; i <= v[0]; i++)
    {
        vector<int> now = v;
        for (int& x : now)
            if (x >= i)
                x -= i;
        int cur = grundy(now);
        if (cur <= v[0])
            to[cur] = true;
    }
    for (int i = 0; i <= v[0]; i++)
        if (!to[i])
            return (f[v] = i);
    exit(239);
}

int32_t main()
{
#ifdef ONPC
    freopen("input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        func(a);
    }
    int ans = 0;
    for (auto t : mx)
        ans ^= grundy(t.second);
    cout << (ans == 0 ? "Arpa" : "Mojtaba");
    return 0;
}