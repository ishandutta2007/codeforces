#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef double ld;
typedef pair<ll, ll> pll;

const int mod = 1e9 + 7;

void add(int& a, int b)
{
    a += b;
    if (a >= mod) {
        a -= mod;
    }
}

void sub(int& a, int b)
{
    a -= b;
    if (a < 0) {
        a += mod;
    }
}

void mul(int& a, int b)
{
    ll c = ll(a) * ll(b);
    if (c >= mod) {
        c %= mod;
    }
    a = c;
}

int binpow(int a, int n)
{
    int ans = 1;
    while (n) {
        if (n & 1) {
            mul(ans, a);
        }
        mul(a, a);
        n >>= 1;
    }
    return ans;
}

struct edge
{
    int from, to;
    int cost;
};

vector<vector<edge> > g;

pii dfs(int v, int p, int x)
{
    if (sz(g[v]) == 1 && g[v][0].to == p) {
        return {0, 0};
    }
    int a = 1;
    int b = 0;
    int z = binpow(sz(g[v]), mod - 2);
    for (edge& e : g[v]) {
        if (e.to == p) {
            continue;
        }
        pii p = dfs(e.to, v, e.cost);
        int val = z;
        mul(val, p.first);
        sub(a, val);
        val = p.second;
        add(val, e.cost);
        mul(val, z);
        sub(b, val);
    }
    if (v == 0) {
        int ans = (mod - b) % mod;
        mul(ans, binpow(a, mod - 2));
        cout << ans << '\n';
        return {0, 0};
    }
    mul(x, z);
    sub(b, x);
    b = (mod - b) % mod;
    z = binpow(a, mod - 2);
    a = binpow(sz(g[v]), mod - 2);
    mul(a, z);
    mul(b, z);
    return {a, b};
}

int main()
{

    //ifstream cin("./python/input.txt");
	//ofstream cout("output.txt");
    //freopen("input.txt", "r", stdin);

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    g.resize(n);

    for (int i = 0; i < n - 1; ++i) {
        int u, v, c;
        cin >> u >> v >> c;
        g[u].pb({u, v, c});
        g[v].pb({v, u, c});
    }

    dfs(0, 0, 0);

}