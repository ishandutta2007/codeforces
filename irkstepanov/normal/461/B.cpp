#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define mp make_pair
#define pb push_back

using namespace std;

typedef long long ll;

const ll mod = 1e9 + 7;

void add(ll& a, ll b)
{
    a += b;
    if (a >= mod) {
        a -= mod;
    }
}

void mul(ll& a, ll b)
{
    a *= b;
    if (a >= mod) {
        a %= mod;
    }
}

void sub(ll& a, ll b)
{
    a -= b;
    if (a < 0) {
        a += mod;
    }
}

ll binpow(ll a, ll n)
{
    if (n == 0) {
        return 1;
    }
    ll ans = 1;
    while (n) {
        if (n & 1) {
            mul(ans, a);
        }
        mul(a, a);
        n >>= 1;
    }
    return ans;
}

void divide(ll& a, ll b)
{
    b = binpow(b, mod - 2);
    mul(a, b);
}

vector<vector<int> > g;
vector<int> color;
vector<ll> dp1, dp0;

void dfs(int v)
{
    if (g[v].empty()) {
        if (color[v] == 0) {
            dp0[v] = 1;
        } else {
            dp1[v] = 1;
        }
        return;
    }
    ll p = 1;
    for (int to : g[v]) {
        dfs(to);
        ll val = dp0[to];
        add(val, dp1[to]);
        mul(p, val);
    }
    if (color[v] == 0) {
        for (int to : g[v]) {
            ll val = dp1[to];
            mul(val, p);
            ll tmp = dp1[to];
            add(tmp, dp0[to]);
            divide(val, tmp);
            add(dp1[v], val);
        }
        dp0[v] = p;
    } else {
        dp0[v] = 0;
        dp1[v] = p;
    }
}

int main()
{

    int n;
    cin >> n;
    
    g.resize(n);
    color.resize(n);
    dp1.resize(n), dp0.resize(n);
    for (int i = 1; i < n; ++i) {
        int p;
        cin >> p;
        g[p].pb(i);
    }
    for (int i = 0; i < n; ++i) {
        cin >> color[i];
    }
    
    dfs(0);
    cout << dp1[0] << "\n";

}