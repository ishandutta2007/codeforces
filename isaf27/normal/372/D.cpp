#pragma GCC optimize("O3")
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
mt19937_64 rnd(239); //(chrono::high_resolution_clock::now().time_since_epoch().count());

//constants
const int M = (int)(2e5 + 239);
const int N = (int)(2e3 + 239);
const int L = 20;
const int T = (1 << 18);
const int B = (int)sqrt(M);
const int X = 42;

int n, k, h[M], pos[M], s, how[M];
vector<int> v[M];
pair<int, int> dp[L][M];
vector<int> et;

void dfs(int p, int pr, int d)
{
    h[p] = d;
    pos[p] = (int)et.size();
    et.push_back(p);
    for (int i : v[p])
        if (i != pr)
        {
            dfs(i, p, d + 1);
            et.push_back(p);
        }
}

int lca(int s, int f)
{
    if (s == f) return s;
    s = pos[s];
    f = pos[f];
    if (s > f) swap(s, f);
    int e = how[f - s + 1];
    pair<int, int> rt = min(dp[e][s], dp[e][f - (1 << e) + 1]);
    return rt.second;
}

int dist(int s, int f)
{
    return h[s] + h[f] - 2 * h[lca(s, f)];
}

set<pair<int, int> > q;
int sum;

void recalc(int x, int cf)
{
    auto it = q.find(make_pair(pos[x], x));
    int pr, nx;
    if (it == q.begin())
    {
        auto it2 = q.end();
        it2--;
        pr = it2->second;
    }
    else
    {
        it--;
        pr = it->second;
        it++;
    }
    it++;
    if (it == q.end())
    {
        auto it2 = q.begin();
        nx = it2->second;
    }
    else
        nx = it->second;
    int now = dist(nx, x) + dist(pr, x) - dist(pr, nx);
    sum += cf * now;
}

void add(int x)
{
    q.insert(make_pair(pos[x], x));
    recalc(x, 1);
}

void del(int x)
{
    recalc(x, -1);
    q.erase(make_pair(pos[x], x));
}

int getfunc()
{
    return (sum / 2);
}

int32_t main()
{
#ifdef ONPC
    freopen("input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> k;
    k--;
    for (int i = 0; i < n - 1; i++)
    {
        int s, f;
        cin >> s >> f;
        s--, f--;
        v[s].push_back(f);
        v[f].push_back(s);
    }
    dfs(0, -1, 0);
    s = (int)et.size();
    for (int i = 0; i < s; i++)
        dp[0][i] = make_pair(h[et[i]], et[i]);
    for (int l = 1; l < L; l++)
        for (int i = 0; i < s; i++)
        {
            int j = i + (1 << (l - 1));
            if (j >= s)
            {
                dp[l][i] = dp[l - 1][i];
                continue;
            }
            dp[l][i] = min(dp[l - 1][i], dp[l - 1][j]);
        }
    how[1] = 0;
    for (int i = 1; i < s; i++)
    {
        how[i + 1] = how[i] + 1;
        if ((1 << how[i + 1]) > i + 1)
            how[i + 1]--;
    }
    sum = 0;
    int ans = 0;
    int r = 0;
    for (int i = 0; i < n; i++)
    {
        while (r < n)
        {
            add(r);
            if (getfunc() > k)
            {
                del(r);
                break;
            }
            r++;
        }
        del(i);
        ans = max(ans, r - i);
    }
    cout << ans << "\n";
    return 0;
}