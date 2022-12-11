#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, ll> pii;
typedef long double ld;

vector<vector<pii> > g;
int n;
vector<int> subtree;
vector<ll> a;

void dfs1(int v)
{
    subtree[v] = 1;
    for (pii& to : g[v]) {
        dfs1(to.first);
        subtree[v] += subtree[to.first];
    }
}

struct data
{
    map<ll, int> m;
    ll d;
    int sum;
    data() : d(0), sum(0) {}
    void add(ll x)
    {
        d += x;
        while (!m.empty()) {
            map<ll, int>::iterator it = m.begin();
            if (it->first - d < 0) {
                sum -= it->second;
                m.erase(m.begin());
            } else {
                break;
            }
        }
    }
};

vector<int> ans;

void dfs(int v, data& res)
{
    if (g[v].empty()) {
        res.m[a[v]] = 1;
        res.sum = 1;
        return;
    }
    vector<pii> sons = g[v];
    sort(all(sons), [&](const pii& a, const pii& b) { return subtree[a.first] > subtree[b.first]; } );
    dfs(sons[0].first, res);
    res.add(sons[0].second);
    for (int i = 1; i < sz(sons); ++i) {
        data tmp;
        dfs(sons[i].first, tmp);
        for (auto it : tmp.m) {
            ll val = it.first - tmp.d - sons[i].second;
            if (val >= 0) {
                res.m[val + res.d] += it.second;
                res.sum += it.second;
            }
        }
    }
    ans[v] = res.sum;
    ++res.m[a[v] + res.d];
    ++res.sum;
}

int main()
{

    //ifstream cin("input.txt");
    //ofstream cout("wa");

    //freopen("input.txt", "r", stdin);

    scanf("%d", &n);
    a.resize(n);
    for (int i = 0; i < n; ++i) {
        scanf("%lld", &a[i]);
    }

    g.resize(n);
    subtree.resize(n);
    for (int i = 1; i < n; ++i) {
        int p;
        ll w;
        scanf("%d%lld", &p, &w);
        --p;
        g[p].pb({i, w});
    }

    dfs1(0);
    ans.resize(n);

    data d;
    dfs(0, d);

    for (int i = 0; i < n; ++i) {
        printf("%d ", ans[i]);
    }
    printf("\n");

}