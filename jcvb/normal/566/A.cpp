#include <bits/stdc++.h>

#define REP(i, a, b) for (int i = (a), _end_ = (b); i < _end_; ++i)
#define FOR(i, a, b) for (int i = (a), _end_ = (b); i <= _end_; ++i)
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define EXIT(...) printf(__VA_ARGS__), exit(0)
#define mp make_pair
#define x first
#define y second
#define pb push_back
#define SZ(x) (int((x).size()))
#define ALL(x) (x).begin(), (x).end()

using namespace std;

typedef long long LL;

template<typename T> T &Read(T &x)
{
    static char c;
    while (!isdigit(c = getchar()));
    x = c - '0';
    while (isdigit(c = getchar())) (x *= 10) += c - '0';
    return x;
}

const int max0 = 800000, maxn = 100000;

struct node
{
    node *go[26];

    int sz[2];
    vector<int> res[2];

    node() { memset(go, 0, sizeof go); }
};

node nd[max0 + 5];
int cur = 0;

node *rt;

void add(node *&rt, char *s, const int &ty, const int &id)
{
    if (!rt) rt = nd + (cur)++;
    ++rt->sz[ty];
    if (s[0] == 0) 
    {
        rt->res[ty].pb(id);
        return;
    }
    add(rt->go[s[0] - 'a'], s + 1, ty, id);
}

int link[maxn + 5];

void dfs(node *rt)
{
    REP(i, 0, 26) if (rt->go[i]) 
    {
        dfs(rt->go[i]);
        REP(j, 0, 2)
            for (auto id : rt->go[i]->res[j]) rt->res[j].pb(id);
    }
    int cnt0 = SZ(rt->res[0]), cnt1 = SZ(rt->res[1]);
    while (cnt0 && cnt1)
    {
        link[rt->res[0][cnt0 - 1]] = rt->res[1][cnt1 - 1];
        rt->res[0].pop_back(), rt->res[1].pop_back();
        --cnt0, --cnt1;
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    scanf("%d", &n);
    static char s[max0 + 5];
    REP(i, 0, n) scanf("%s", s), add(rt, s, 0, i);
    REP(i, 0, n) scanf("%s", s), add(rt, s, 1, i);
    LL ans = 0;
    REP(i, 1, cur) ans += min(nd[i].sz[0], nd[i].sz[1]);
    cout << ans << endl;
    memset(link, -1, sizeof link);
    dfs(rt);
    REP(i, 0, n) printf("%d %d\n", i + 1, link[i] + 1);
    return 0;
}