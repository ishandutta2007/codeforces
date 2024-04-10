#include<bits/stdc++.h>
using namespace std;
// Pragma
#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline","03")
// Macros:
#define f first
#define s second
typedef long long ll;
// debugging macros
#define db(x) cerr << #x << ": " << (x) << '\n';
#define db_v(x) cerr << #x << ": ["; for( auto i : (x) ) cerr << i << ", "; cerr << "]\n";
#define db_p(x) cerr << #x << ": " << (x).first << " " << (x).second << '\n';
// Constraints:
const int maxn = 1000010;
const int mod2 = 1000000007;
const int mod = 998244353;
const ll INF = 1ll * mod * mod;
const double eps = 1e-9;
// Quick Functions------------------------------------------
ll qpow(ll b,int e){
    if( !e ) return 1;
    if( e & 1 ) return qpow(b,e-1) * b % mod;
    ll pwur = qpow(b,e>>1);
    return pwur * pwur % mod;
}
mt19937_64 rnd(time(0));
ll rng (ll a, ll b){
    return uniform_int_distribution<ll>(a,b)(rnd);
}
// Problem starts here

namespace ntt
{
    typedef long long ll;
    const int _MOD = 998244353;

    ll inv(ll b, ll M)
    {
        ll u = 1, x = 0, s = b, t = M;
        while (s)
        {
            ll q = t / s;
            swap(x -= u * q, u);
            swap(t -= s * q, s);
        }
        return (x %= M) >= 0 ? x : x + M;
    }

    ll pow(ll a, ll b, ll M)
    {
        ll x = 1;
        for (; b > 0; b >>= 1)
        {
            if (b & 1)
                x = (a * x) % M;
            a = (a * a) % M;
        }
        return x;
    }

    // fast modulo transform
    //   (1) n = 2^k < 2^23
    //   (2) only predetermined mod can be used
    void fmt(vector<ll> &x, int sign = +1)
    {
        int n = x.size();
        ll h = pow(3, (mod - 1) / n, _MOD);
        if (sign < 0) h = inv(h, _MOD);
        for (int i = 0, j = 1; j < n - 1; ++j)
        {
            for (int k = n >> 1; k > (i ^= k); k >>= 1);
            if (j < i) swap(x[i], x[j]);
        }
        for (int m = 1; m < n; m *= 2)
        {
            ll w = 1, wk = pow(h, n / (2 * m), _MOD);
            for (int i = 0; i < m; ++i)
            {
                for (int j = i; j < n; j += 2 * m)
                {
                    ll u = x[j], d = x[j + m] * w % _MOD;
                    if ((x[j] = u + d) >= _MOD)
                        x[j] -= _MOD;
                    if ((x[j + m] = u - d) < 0)
                        x[j + m] += _MOD;
                }
                w = w * wk % _MOD;
            }
        }
        if (sign < 0)
        {
            ll n_inv = inv(n, _MOD);
            for (auto &a : x)
                a = (a * n_inv) % _MOD;
        }
    }

    // convolution via fast modulo transform
    vector<ll> convolution(vector<ll> x, vector<ll> y)
    {
        for (auto &a : x) a %= mod;
        for (auto &b : y) b %= mod;
        int n = x.size() + y.size() - 1, size = n - 1;
        for (int s : { 1, 2, 4, 8, 16 })
            size |= (size >> s);
        size += 1;
        x.resize(size);
        y.resize(size);

        fmt(x, +1);
        fmt(y, +1);
        for (int i = 0; i < x.size(); ++i)
            x[i] = (x[i] * y[i]) % _MOD;
        fmt(x, -1);
        return x;
    }
}

vector<vector<ll>> v;

void DandC(int l,int r){

    if( l >= r )
        return;

    int mi = ( l + r ) >> 1;

    DandC(l,mi);
    DandC(mi+1,r);

    v[l] = ntt::convolution( v[l] , v[mi+1] );
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.setf(ios::fixed); cout.precision(10);

    //freopen("a.in","r",stdin);
    //freopen("a.in","w",stdout);

    int n;
    cin >> n;

    vector<int> g[n], deg(n);
    for(int i=0; i<n-1; i++){
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    function<void(int,int)> dfs = [&](int u,int p){
        for( auto v : g[u] ){
            if( v != p ){
                deg[u] ++;
                dfs(v,u);
            }
        }
    };
    dfs(0,0);

    for(int i=0; i<n; i++)
        if( deg[i] )
            v.push_back({1ll,(ll)deg[i]});

    DandC(0,(int)v.size()-1);

    while( v[0].size() <= n )
        v[0].push_back(0);

    vector<ll> fact;
    fact.push_back(1);
    for(int i=1; i<=n; i++)
        fact.push_back(fact.back()*i%mod);

    ll ans = 0;
    for(int i=0; i<n; i++){
        if( i & 1 ){
            ans = ( ans - v[0][i] * fact[n-i] + 1ll * mod * mod ) % mod;
        }
        else{
            ans = ( ans + v[0][i] * fact[n-i] ) % mod;
        }
    }
    cout << ans << '\n';

    return 0;
}