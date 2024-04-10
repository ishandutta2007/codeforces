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
const int M = (int)(5e5 + 239);
const int N = (int)(2e3 + 239);
const int L = 18;
const int T = (1 << 18) + 239;
const int B = 500;
const int X = 1e4 + 239;

int n, m, t[M];
vector<int> v[M];
vector<pair<int, int>> al;
bool used[M];
int has[M];

int32_t main()
{
#ifdef ONPC
    freopen("input", "r", stdin);
#endif
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int s, f;
        cin >> s >> f;
        s--, f--;
        v[s].push_back(f);
        v[f].push_back(s);
    }
    for (int i = 0; i < n; i++)
    {
        cin >> t[i];
        t[i]--;
        al.push_back(make_pair(t[i], i));
    }
    sort(al.begin(), al.end());
    int cnt_has = 0;
    for (pair<int, int> tp : al)
    {
        int i = tp.second;
        cnt_has++;
        for (int j : v[i])
            if (used[j])
                has[t[j]] = cnt_has;
        int cur = 0;
        while (has[cur] == cnt_has)
            cur++;
        if (cur != t[i])
        {
            cout << "-1\n";
            return 0;
        }
        used[i] = true;
    }
    for (pair<int, int> t : al)
        cout << t.second + 1 << " ";
    cout << "\n";
    return 0;
}