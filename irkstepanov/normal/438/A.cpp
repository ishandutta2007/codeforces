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

vector<ll> sum;
vector<ll> a;

struct comp
{
    bool operator()(int x, int y)
    {
        return a[x] > a[y] || (a[x] == a[y] && x < y);
    }
};

int main()
{

    ios::sync_with_stdio(false);

    //ifstream cin("input.txt");
    //ofstream cout("mine.txt");

    int n, m;
    cin >> n >> m;
    a.resize(n);

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<vector<int> > g(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        g[u].pb(v);
        g[v].pb(u);
    }

    sum.resize(n);
    for (int i = 0; i < n; ++i) {
        for (int to : g[i]) {
            sum[i] += a[to];
        }
        //cout << i << " " << sum[i] << "\n";
    }

    set<int, comp> q;
    vector<char> deleted(n, false);
    for (int i = 0; i < n; ++i) {
        q.insert(i);
    }

    ll ans = 0;
    while (!q.empty()) {
        int v = *q.begin();
        q.erase(q.begin());
        //cout << v << "\n";
        deleted[v] = true;
        ans += sum[v];
        for (int to : g[v]) {
            if (!deleted[to]) {
                q.erase(to);
                sum[to] -= a[v];
                q.insert(to);
            }
        }
    }

    cout << ans << "\n";

}