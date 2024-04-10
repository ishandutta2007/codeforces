#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef double ld;

const int BIG = 2 * 1e9 + 239;
const ld pi = acos(-1.0);
const int M = 5 * 1e5 + 100;
const int L = 21;
const int two = 2;
const ll INF = 1e18 + 239;
const int T = (1 << 21);
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, -1, 0, 1};

int n, m, q, pos[M];
tuple<int, int, int> r[M];
bool used[M];
vector<vector<int> > v(M);
vector<vector<int> > t;
vector<vector<pair<int, int> > > ask(M);
vector<vector<pair<int, int> > > in(M);

int parent[M], rr[M];

inline void build()
{
    for (int i = 0; i < n; i++)
        parent[i] = i, rr[i] = 0;
}

inline int find_set(int p)
{
    if (parent[p] == p)
        return p;
    parent[p] = find_set(parent[p]);
    return parent[p];
}

inline void merge_set(int a, int b)
{
    a = find_set(a);
    b = find_set(b);
    if (a == b)
        return;
    if (rr[a] > rr[b])
        swap(a, b);
    parent[a] = b;
    if (rr[a] == rr[b])
        rr[b]++;
}

inline bool is_connect(int a, int b)
{
    return (find_set(a) == find_set(b));
}

bool yes;

void dfs(int p, int pr)
{
    used[p] = true;
    bool be = false;
    for (int i : v[p])
    {
        if (!used[i])
            dfs(i, p);
        else
        {
            if (!be && pr == i)
            {
                be = true;
                continue;
            }
            if (used[i])
                yes = true;
        }
    }
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
    #endif
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++)
    {
        int s, f, w;
        scanf("%d%d%d", &s, &f, &w);
        s--, f--;
        r[i] = make_tuple(s, f, w);
        in[w].push_back(make_pair(s, f));
    }
    scanf("%d", &q);
    for (int z = 0; z < q; z++)
    {
        vector<int> id;
        int sz;
        scanf("%d", &sz);
        id.resize(sz);
        for (int x = 0; x < sz; x++)
        {
            scanf("%d", &id[x]);
            id[x]--;
        }
        t.push_back(id);
        for (int i : id)
        {
            ask[get<2>(r[i]) - 1].push_back(make_pair(get<0>(r[i]), 0));
            ask[get<2>(r[i]) - 1].push_back(make_pair(get<1>(r[i]), 0));
        }
    }
    build();
    for (int w = 0; w < M; w++)
    {
        for (pair<int, int> t : in[w])
        {
            int s = t.first;
            int f = t.second;
            if (is_connect(s, f))
                continue;
            merge_set(s, f);
        }
        sort(ask[w].begin(), ask[w].end());
        for (int i = 0; i < ask[w].size(); i++)
            ask[w][i].second = find_set(ask[w][i].first);
        sort(ask[w].begin(), ask[w].end());
    }
    for (int i = 0; i < M; i++)
        in[i].clear();
    for (int z = 0; z < q; z++)
    {
        vector<int> pt;
        for (int i : t[z])
        {
            pt.push_back(get<2>(r[i]));
            in[get<2>(r[i])].push_back(make_pair(get<0>(r[i]), get<1>(r[i])));
        }
        sort(pt.begin(), pt.end());
        pt.resize(unique(pt.begin(), pt.end()) - pt.begin());
        yes = false;
        for (int w : pt)
        {
            vector<int> ptt;
            vector<pair<int, int> > rt;
            for (pair<int, int> t : in[w])
            {
                int s = t.first;
                int f = t.second;
                int ts = lower_bound(ask[w - 1].begin(), ask[w - 1].end(), make_pair(s, 0))->second;
                int tf = lower_bound(ask[w - 1].begin(), ask[w - 1].end(), make_pair(f, 0))->second;
                if (ts == tf)
                {
                    yes = true;
                    continue;
                }
                ptt.push_back(ts);
                ptt.push_back(tf);
                rt.push_back(make_pair(ts, tf));
            }
            in[w].clear();
            sort(ptt.begin(), ptt.end());
            ptt.resize(unique(ptt.begin(), ptt.end()) - ptt.begin());
            for (int i : ptt)
            {
                used[i] = false;
                v[i].clear();
            }
            for (pair<int, int> t : rt)
            {
                v[t.first].push_back(t.second);
                v[t.second].push_back(t.first);
            }
            for (int i : ptt)
                if (!used[i] && !yes)
                    dfs(i, -1);
        }
        if (yes)
            cout << "NO\n";
        else
            cout << "YES\n";
    }
    return 0;
}