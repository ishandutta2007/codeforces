//#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

//defines
typedef long long ll;
typedef double ld;
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
const int two = 2;
const ld eps = 1e-8;
const ll INF = (ll)(1e18 + 239);
const int BIG = (int)(1e9 + 239);
const int MOD = 1e9 + 7;
const ll MOD2 = (ll)MOD * (ll)MOD;

//random
#ifdef ONPC
mt19937_64 rnd(239);
#else
mt19937_64 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
#endif

//constants
const int M = (int)(2e5 + 239);
const int N = (int)(2e3 + 239);
const int L = 10;
const int T = (1 << 20) + 239;
const int B = 500;
const int X = 1e4 + 239;

int n, m, k;
vector<pair<int, int>> v[M];
vector<int> has[L];
bool good[L][L][L][L];
bool can[L][L];

int used[M], cnt_used;

int ans;

int p[L];

void gen(int b)
{
    if (b == k)
    {
        ans++;
        return;
    }
    for (int i = 0; i <= b; i++)
    {
        p[b] = i;
        if (can[b + 1][p[b]])
        {
            bool ch = true;
            for (int j = 0; j < b && ch; j++)
                ch &= good[j + 1][p[j]][b + 1][p[b]];
            if (ch)
                gen(b + 1);
        }
    }
}

int32_t main()
{
#ifdef ONPC
    freopen("input", "r", stdin);
#endif
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m >> k;
    for (int i = 0; i < m; i++)
    {
        int s, f, c;
        cin >> s >> f >> c;
        s--, f--;
        v[s].push_back(make_pair(c, f));
    }
    for (int i = 0; i < n; i++)
        sort(v[i].begin(), v[i].end());
    for (int i = 0; i < n; i++)
        has[v[i].size()].push_back(i);
    if (!has[0].empty())
    {
        cout << "0\n";
        return 0;
    }
    for (int s = 1; s <= k; s++)
        for (int t = 0; t < s; t++)
        {
            can[s][t] = true;
            cnt_used++;
            for (int i : has[s])
            {
                int to = v[i][t].second;
                if (used[to] == cnt_used)
                    can[s][t] = false;
                used[to] = cnt_used;
            }
        }
    for (int s1 = 1; s1 <= k; s1++)
        for (int t1 = 0; t1 < s1; t1++)
            if (can[s1][t1])
                for (int s2 = s1 + 1; s2 <= k; s2++)
                    for (int t2 = 0; t2 < s2; t2++)
                        if (can[s2][t2])
                        {
                            good[s1][t1][s2][t2] = true;
                            cnt_used++;
                            for (int i : has[s2])
                            {
                                int to = v[i][t2].second;
                                used[to] = cnt_used;
                            }
                            for (int i : has[s1])
                            {
                                int to = v[i][t1].second;
                                if (used[to] == cnt_used)
                                {
                                    good[s1][t1][s2][t2] = false;
                                    break;
                                }
                            }
                        }
    ans = 0;
    gen(0);
    cout << ans << "\n";
    return 0;
}