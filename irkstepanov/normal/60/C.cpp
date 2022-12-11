#include <bits/stdc++.h>
 
#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;
typedef double ld;
typedef pair<ll, ll> pll;
 
const int nmax = 110;
 
struct edge {
    int from, to;
    int gcd, lcm;
};
 
ll binpow(ll a, ll n) {
    if (n == -1) {
        return 1;
    }
    ll ans = 1;
    while (n) {
        if (n & 1) {
            ans *= a;
        }
        a *= a;
        n >>= 1;
    }
    return ans;
}
 
vector<ll> res;
vector<edge> edges;
vector<int> g[nmax];
 
const int kmax = 1e6 + 100;
int mind[kmax];
vector<int> primes;
bool was[kmax];
 
vector<int> used(nmax);
vector<int> visited;
 
int deg(int val, int p) {
    int ans = 0;
    while (val % p == 0) {
        ++ans;
        val /= p;
    }
    return ans;
}

bool eq(int a, int b, int c, int d) {
    return ((a == c && b == d) || (a == d && b == c));
}
 
bool dfs(int v, int p) {
    visited.pb(v);
    for (int e : g[v]) {
        int x = deg(edges[e].gcd, p) + deg(edges[e].lcm, p) - used[v];
        int to = edges[e].to;
        if (!eq(x, used[v], deg(edges[e].gcd, p), deg(edges[e].lcm, p))) {
            return false;
        }
        if (used[to] == -1) {
            used[to] = x;
            if (!dfs(to, p)) {
                return false;
            }
        }
        if (used[to] != x) {
            return false;
        }
    }
    return true;
}

void nein() {
    cout << "NO\n";
    exit(0);
}

//mt19937 rr(1);

//const int magic = 10;

/*void rs(vector<int>& a) {
    for (int i = 1; i < sz(a); ++i) {
        swap(a[i], a[rr() % (i + 1)]);
    }
}*/
 
int main()
{
 
    //memset(pro, -1, sizeof(pro));
 
    //ifstream cin("input.txt");
    //ofstream cout("output.txt");
    //freopen("input.txt", "r", stdin);
 
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    int n, m;
    cin >> n >> m;
 
    for (int i = 0; i < m; ++i) {
        int u, v;
        int gcd, lcm;
        cin >> u >> v >> gcd >> lcm;
        if (lcm % gcd) {
            nein();
        }
        --u, --v;
        g[u].pb(sz(edges));
        edges.pb({u, v, gcd, lcm});
        g[v].pb(sz(edges));
        edges.pb({v, u, gcd, lcm});
    }
    res.assign(n, 1);
 
    for (int i = 2; i < kmax; ++i) {
        was[i] = false;
        mind[i] = i;
    }
    for (int i = 2; i < kmax; ++i) {
        if (mind[i] == i) {
            primes.pb(i);
        }
        for (int p : primes) {
            if (i * p >= kmax || p > mind[i]) {
                break;
            }
            mind[i * p] = p;
        }
    }

    for (int i = 0; i < sz(edges); ++i) {
        int u = edges[i].from, v = edges[i].to;
        ll x = edges[i].lcm;
        vector<ll> degs;
        for (ll d = 2; d * d <= x; ++d) {
            if (x % d == 0) {
                was[d] = true;
                degs.pb(1);
                while (x % d == 0) {
                    degs.back() *= d;
                    x /= d;
                }
            }
        }
        if (x != 1) {
            was[x] = true;
            degs.pb(x);
        }
        //rs(g[u]);
        //rs(g[v]);
        for (int e1 : g[u]) {
            for (int e2 : g[v]) {
                ll t = ll(edges[e1].lcm) * edges[e2].lcm;
                if (t % edges[i].lcm) {
                    nein();
                }
            }
        }
    }
 
    for (int p : primes) {
        if (!was[p]) {
            continue;
        }
        used.assign(n, -1);
        visited.clear();
        for (int i = 0; i < sz(edges); ++i) {
            int u = edges[i].from, v = edges[i].to;
            if (used[u] != -1) {
                continue;
            }
            int minn = deg(edges[i].gcd, p), maxx = deg(edges[i].lcm, p);
            //cout << minn << " " << maxx << " " << u << " " << v << endl;
            if (minn == 0 && maxx == 0) {
                continue;
            }
            used[u] = minn;
            if (dfs(u, p)) {
                visited.clear();
                continue;
            }
            for (int w : visited) {
                used[w] = -1;
            }
            visited.clear();
 
            used[u] = maxx;
            if (!dfs(u, p)) {
                nein();
            }
            visited.clear();
        }
        for (int i = 0; i < n; ++i) {
            //cout << "!" << i << " " << used[i] << "\n";
            res[i] *= binpow(p, used[i]);
        }
    }
 
    cout << "YES\n";
    for (int i = 0; i < n; ++i) {
        cout << res[i] << " ";
    }
    cout << "\n";
 
}