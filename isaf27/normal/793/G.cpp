/*
    Author: isaf27 (Ivan Safonov)
*/

#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

//defines
typedef long long ll;
typedef double ld;
#define TIME clock() * 1.0 / CLOCKS_PER_SEC
#define fast_read cin.sync_with_stdio(0)
#define nul point(0, 0)
#define str_to_int(stroka) atoi(stroka.c_str())
#define str_to_ll(stroka) atoll(stroka.c_str())
#define str_to_double(stroka) atof(stroka.c_str())
#define what_is(x) cerr << #x << " is " << x << endl
#define solve_system int number; cin >> number; for (int i = 0; i < number; i++) solve()
#define solve_system_scanf int number; scanf("%d", &number); forn(i, 0, number) solve()

//permanent constants
const ld pi = 3.141592653589793238462643383279;
const ld log23 = 1.58496250072115618145373894394781;
const ld eps = 1e-10;
const ll INF = 1e18 + 239;
const ll prost = 239;
const int two = 2;
const int th = 3;
const ll MOD = 1e9 + 9;
const ll MOD2 = MOD * MOD;
const int BIG = 1e9 + 239;
const int alf = 26;
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};
const int dxo[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
const int dyo[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
const int dig = 10;
const string str_alf = "abcdefghijklmnopqrstuvwxyz";
const string str_alf_big = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const int day[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
const int digarr[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
const int bt = 31;

//easy functions
template< typename T >
inline T gcd(T a, T b) { return a ? gcd(b % a, a) : b; }
template< typename T >
inline T lcm(T a, T b) { return (a / gcd(a, b)) * b; }
inline bool is_down(char x) { return ('a' <= x && x <= 'z'); }
inline bool is_upper(char x) { return ('A' <= x && x <= 'Z'); }
inline bool is_digit(char x) { return ('0' <= x && x <= '9'); }
ll power(ll a, int k)
{
    ll ans = 1;
    while (k)
    {
        if (k & 1) ans = (ans * a) % MOD;
        ans = (ans * ans) % MOD;
        k >>= 1;
    }
    return ans;
}

//random
mt19937 rnd(239);

//constants
const int M = 2 * 1e5 + 239;
const int N = 2 * 1e3 + 239;
const int L = 20;
const int T = (1 << 16);
const int B = trunc(sqrt(M)) + 1;
const int X = 1e4 + 239;

// Code starts here

struct MaxFlow
{
    struct Edge
    {
        int to;
        ll c, f;

        Edge()
        {
            to = c = f = 0;
        }

        Edge(int to1, int c1)
        {
            to = to1;
            c = c1;
            f = 0;
        }
    };

    int n;
    vector<Edge> e;
    vector<vector<int> > v;
    int s, f;
    vector<int> dist, last;

    MaxFlow()
    {

    }

    MaxFlow(int nn, int ss, int ff)
    {
        n = nn;
        dist.resize(n);
        v.resize(n);
        last.resize(n);
        s = ss, f = ff;
    }

    void connect(int a, int b, ll c)
    {
        if (v.size() <= max(a, b))
        {
            n = max(a, b) + 1;
            dist.resize(n);
            v.resize(n);
            last.resize(n);
        }
        int i = e.size();
        e.push_back(Edge(b, c));
        v[a].push_back(i);
        e.push_back(Edge(a, 0));
        v[b].push_back(i + 1);
    }

    ll dfs(int p, ll f0)
    {
        if (p == f)
            return f0;
        while (last[p] >= 0)
        {
            int i = v[p][last[p]];
            if (dist[e[i].to] != dist[p] + 1)
            {
                last[p]--;
                continue;
            }
            if (e[i].c == e[i].f)
            {
                last[p]--;
                continue;
            }
            ll res = dfs(e[i].to, min(f0, e[i].c - e[i].f));
            if (res == 0)
            {
                last[p]--;
                continue;
            }
            e[i].f += res;
            e[i ^ 1].f -= res;
            if (e[i].f == e[i].c)
                last[p]--;
            return res;
        }
        return 0;
    }

    void phase()
    {
        for (int i = 0; i < n; i++)
            dist[i] = BIG;
        dist[s] = 0;
        queue<int> q;
        q.push(s);
        while (!q.empty())
        {
            int x = q.front();
            q.pop();
            for (int i : v[x])
                if (e[i].c > e[i].f && dist[e[i].to] > dist[x] + 1)
                {
                    dist[e[i].to] = dist[x] + 1;
                    q.push(e[i].to);
                }
        }
        if (dist[f] >= BIG)
            return;
        for (int i = 0; i < n; i++)
            last[i] = (int)v[i].size() - 1;
        while (dfs(s, INF) != 0);
        phase();
    }

    void run()
    {
        phase();
    }

    ll gett()
    {
        ll ans = 0;
        for (int i : v[s])
            ans += e[i].f;
        return ans;
    }
};

bool w[X][X];
int n, q, m;
vector<pair<int, int> > l, r;
pair<int, int> a[X], b[X];
vector<vector<int> > va, vb;
vector<int> now;
int id1[T], id2[T];
MaxFlow st;

void fnd(int i, int l, int r, int ql, int qr)
{
    if (qr <= l || r <= ql) return;
    if (ql <= l && r <= qr)
    {
        now.push_back(i);
        return;
    }
    int mid = (l + r) >> 1;
    fnd(2 * i + 1, l, mid, ql, qr);
    fnd(2 * i + 2, mid, r, ql, qr);
}

void build1(int i, int l, int r)
{
    id1[i] = (2 * n + 2) + i;
    if (r - l == 1)
    {
        st.connect(l + 1, i + (2 * n + 2), 1);
        return;
    }
    int mid = (l + r) >> 1;
    build1(2 * i + 1, l, mid);
    build1(2 * i + 2, mid, r);
    st.connect((2 * n + 2) + (2 * i + 1), (2 * n + 2) + i, n);
    st.connect((2 * n + 2) + (2 * i + 2), (2 * n + 2) + i, n);
}

#define ws kekmem

int ws;

void build2(int i, int l, int r)
{
    id2[i] = ws + i;
    if (r - l == 1)
    {
        st.connect(i + ws, (n + 1 + l), 1);
        return;
    }
    int mid = (l + r) >> 1;
    build2(2 * i + 1, l, mid);
    build2(2 * i + 2, mid, r);
    st.connect(ws + i, ws + (2 * i + 1), n);
    st.connect(ws + i, ws + (2 * i + 2), n);
}

int main()
{   //*
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif /**/
    fast_read;
    cin >> n >> q;
    for (int i = 0; i < q; i++)
    {
        cin >> a[i].first >> b[i].first >> a[i].second >> b[i].second;
        a[i].first--, b[i].first--;
        for (int x = a[i].first; x < a[i].second; x++)
            for (int y = b[i].first; y < b[i].second; y++)
                w[x][y] = true;
    }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (!w[i][j])
            {
                int t = 1;
                while (j + t < n && !w[i][j + t])
                    t++;
                int to = i;
                for (int h = i; h < n; h++)
                {
                    bool bad = false;
                    for (int u = 0; u < t && !bad; u++)
                        if (w[h][u + j])
                        {
                            bad = true;
                            break;
                        }
                    if (!bad)
                    {
                        to = h;
                        continue;
                    }
                    break;
                }
                l.push_back(make_pair(i, to + 1));
                r.push_back(make_pair(j, j + t));
                for (int x = l.back().first; x < l.back().second; x++)
                    for (int y = r.back().first; y < r.back().second; y++)
                        w[x][y] = true;
            }
    m = l.size();
    for (int i = 0; i < m; i++)
    {
        now.clear();
        fnd(0, 0, n, l[i].first, l[i].second);
        va.push_back(now);
        now.clear();
        fnd(0, 0, n, r[i].first, r[i].second);
        vb.push_back(now);
    }
    st = MaxFlow(2 * n + 2, 0, 2 * n + 1);
    for (int i = 0; i < n; i++)
        st.connect(0, i + 1, 1);
    for (int i = 0; i < n; i++)
        st.connect(n + 1 + i, 2 * n + 1, 1);
    build1(0, 0, n);
    ws = st.n;
    build2(0, 0, n);
    for (int i = 0; i < m; i++)
    {
        int x = st.n;
        int y = st.n + 1;
        st.connect(x, y, n);
        for (int r : va[i])
            st.connect(id1[r], x, n);
        for (int r : vb[i])
            st.connect(y, id2[r], n);
    }
    st.run();
    cout << st.gett();
    return 0;
}