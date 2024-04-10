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
const int M = (int)(2e5 + 239);
const int N = (int)(2e3 + 239);
const int L = 20;
const int T = (1 << 18) + 239;
const int B = 500;
const int X = 26;

vector<int> v[M];
int dist[two][M], n, m, k;
vector<int> st;
vector<pair<int, int>> a;

void bfs(int c, int p)
{
    for (int i = 0; i < n; i++)
        dist[c][i] = BIG;
    dist[c][p] = 0;
    queue<int> q;
    q.push(p);
    while (!q.empty())
    {
        int t = q.front();
        q.pop();
        for (int i : v[t])
            if (dist[c][i] > dist[c][t] + 1)
            {
                dist[c][i] = dist[c][t] + 1;
                q.push(i);
            }
    }
}

vector<int> suf[M];

bool cmp(int i, int j)
{
    return (a[i].second > a[j].second);
}

bool check(int t)
{
    t--;
    for (int i = 0; i < k; i++)
    {
        int x = a[i].first;
        int y = a[i].second;
        int it = lower_bound(a.begin(), a.end(), make_pair(t - y, 0)) - a.begin();
        for (int j : suf[it])
            if (i != j && a[i].first + a[j].second >= t && a[i].second + a[j].first >= t)
                return true;
    }
    return false;
}

int32_t main()
{
#ifdef ONPC
    freopen("input", "r", stdin);
#endif
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m >> k;
    st.resize(k);
    for (int i = 0; i < k; i++)
    {
        cin >> st[i];
        st[i]--;
    }
    for (int i = 0; i < m; i++)
    {
        int s, f;
        cin >> s >> f;
        s--, f--;
        v[s].push_back(f);
        v[f].push_back(s);
    }
    bfs(0, 0);
    bfs(1, n - 1);
    int ans = dist[0][n - 1];
    for (int i : st)
        a.push_back(make_pair(dist[0][i], dist[1][i]));
    sort(a.begin(), a.end());
    for (int i = k - 1; i >= 0; i--)
    {
        suf[i] = suf[i + 1];
        suf[i].push_back(i);
        sort(suf[i].begin(), suf[i].end(), cmp);
        if ((int)suf[i].size() == 3)
            suf[i].pop_back();
    }
    int l = 0;
    int r = n + 1;
    while (r - l > 1)
    {
        int h = (l + r) >> 1;
        if (check(h))
            l = h;
        else
            r = h;
    }
    cout << min(ans, l) << "\n";
    return 0;
}