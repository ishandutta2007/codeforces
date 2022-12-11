#include <bits/stdc++.h>

#define mp make_pair
#define pb push_back
#define sz(a) static_cast<int>((a).size())
#define all(a) (a).begin(), (a).end()
#define forn(i, n) for (int i = 0; i < n; ++i)

using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> edge;

vector<int> size;
vector<int> parent;

ll ans = 0;
vector<vector<int> > g;
vector<ll> a;

bool comp(const pair<ll, int>& a, const pair<ll, int>& b)
{
    if (a.first != b.first) {
        return a.first > b.first;
    }
    return a.second < b.second;
}

int findParent(int v)
{
    if (parent[v] == v) {
        return v;
    }
    return parent[v] = findParent(parent[v]);
}

void unite(int a, int b, ll x)
{
    if (size[a] < size[b]) {
        swap(a, b);
    }
    //a = findParent(a), b = findParent(b);
    ans += (ll)(size[a]) * (ll)(size[b]) * x;
    parent[b] = a;
    size[a] += size[b];
}

int main()
{

    ios::sync_with_stdio(false);

    //ifstream cin("input.txt");
    //ofstream cout("mine.txt");

    int n, m;
    cin >> n >> m;
    size.resize(n);
    parent.resize(n);
    g.resize(n);
    a.resize(n);

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        if (a[u] < a[v]) {
            g[u].pb(v);
        } else if (a[u] > a[v]) {
            g[v].pb(u);
        } else {
            g[max(u, v)].pb(min(u, v));
        }
    }

    vector<pair<ll, int> > p(n);
    for (int i = 0; i < n; ++i) {
        p[i] = mp(a[i], i);
    }
    sort(all(p), comp);
    vector<int> pos(n);
    for (int i = 0; i < n; ++i) {
        pos[p[i].second] = i;
    }

    for (int i = 0; i < n; ++i) {
        int v = p[i].second;
        size[i] = 1;
        parent[i] = i;
        for (int u : g[v]) {
            int x = findParent(pos[u]), y = findParent(i);
            if (x != y) {
                unite(y, x, p[i].first);
            }
        }
        //cout << ans << "\n";
    }

    ll t = (ll)(n) * (ll)(n - 1) / 2;
    ld otv = (ld)(ans) / t;
    cout << fixed;
    cout.precision(10);
    cout << otv << "\n";

}