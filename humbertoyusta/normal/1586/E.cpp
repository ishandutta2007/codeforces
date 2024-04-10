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
const int maxn = 300010;
const int mod = 1000000007;
const int mod2 = 998244353;
const double eps = 1e-9;
// Quick Functions------------------------------------------
ll qpow(ll b,int e){
    if( !e ) return 1;
    if( e & 1 ) return qpow(b,e-1) * b % mod;
    int pwur = qpow(b,e>>1);
    return pwur * pwur % mod;
}
mt19937_64 rnd(time(0));
ll rng (ll a, ll b){
    return uniform_int_distribution<ll>(a,b)(rnd);
}
// Problem starts here -------------------------------------

int p[maxn];
vector<int> v[maxn];

int find_(int x){
    return ( p[x] == x ) ? ( x ) : ( p[x] = find_( p[x] ) );
}

bool add(int u,int v){
    u = find_(u);
    v = find_(v);
    if( u == v )
        return false;
    p[v] = u;
    return true;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.setf(ios::fixed); cout.precision(10);

    //freopen("a.in","r",stdin);
    //freopen("a.in","w",stdout);

    int n, m;
    cin >> n >> m;

    for(int i=0; i<n; i++)
        p[i] = i;

    vector<int> g[n];
    for(int i=1; i<=m; i++){
        int u, v;
        cin >> u >> v;
        u--, v--;
        if( add(u,v) ){
            g[u].push_back(v);
            g[v].push_back(u);
        }
    }

    int q;
    cin >> q;
    map<pair<int,int>,int> mp;

    for(int i=1; i<=q; i++){

        int a, b;
        cin >> a >> b;
        a--, b--;

        vector<int> mk(n), p(n);
        function<void(int)> dfs= [&](int u){
            mk[u] = 1;
            for( auto v : g[u] ){
                if( !mk[v] ){
                    p[v] = u;
                    dfs(v);
                }
            }
        };
        dfs(a);

        int x = b;
        while( x != a ){
            v[i].push_back(x);
            mp[{min(x,p[x]),max(x,p[x])}] ^= 1;
            x = p[x];
        }
        v[i].push_back(a);
        reverse(v[i].begin(),v[i].end());
    }

    bool bad = 0;
    vector<int> t[n], deg(n);
    for( auto i : mp ){
        if( i.s == 1 ){
            t[i.f.f].push_back(i.f.s);
            t[i.f.s].push_back(i.f.f);
            deg[i.f.f] ++;
            deg[i.f.s] ++;
            bad = true;
        }
    }
    if( bad ){
        cout << "NO\n";

        int ans = 0;

        vector<int> mk(n);
        for(int i=0; i<n; i++){
            if( !mk[i] ){
                function<void(int,int)> dfs = [&](int u,int p){
                    int cnt = 0;
                    mk[u] = 1;
                    for( auto v : t[u] ){
                        if( !mk[v] ){
                            cnt ++;
                            dfs(v,u);
                        }
                    }
                    ans += ( cnt + ( u == p ) ) / 2;
                };
                dfs(i,i);
            }
        }

        cout << ans << '\n';
        return 0;
    }

    cout << "YES\n";

    for(int i=1; i<=q; i++){
        cout << v[i].size() << '\n';
        for( auto j : v[i] )
            cout << j + 1 << ' ';
        cout << '\n';
    }

    return 0;
}