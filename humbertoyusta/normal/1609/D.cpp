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
const int mod = 1000000007;
const int mod2 = 998244353;
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

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.setf(ios::fixed); cout.precision(10);

    //freopen("a.in","r",stdin);
    //freopen("a.in","w",stdout);

    int tc;
    tc = 1;//cin >> tc;
    while( tc-- ){
        int n, m;
        cin >> n >> m;

        vector<int> p(n), rnk(n);
        for(int i=0; i<n; i++){
            p[i] = i;
            rnk[i] = 1;
        }

        int extra_edges = 0;

        for(int t=0; t<m; t++){

            function<int(int)> find_ = [&](int x){
                if( p[x] == x ) return x;
                return p[x] = find_( p[x] );
            };

            function<int(int,int)> add = [&](int u,int v){
                u = find_(u);
                v = find_(v);
                if( u == v )
                    return 1;
                p[v] = u;
                rnk[u] += rnk[v];
                return 0;
            };

            int u, v;
            cin >> u >> v;
            u--, v--;

            extra_edges += add(u,v);

            vector<int> mk(n);
            vector<int> vx;
            for(int i=0; i<n; i++){
                if( !mk[find_(i)] ){
                    vx.push_back(rnk[find_(i)]);
                    mk[find_(i)] = 1;
                }
            }
            sort(vx.begin(),vx.end());
            reverse(vx.begin(),vx.end());

            int ans = 0;
            for(int i=0; i<=min(extra_edges,(int)vx.size()-1); i++)
                ans += vx[i];
            cout << ans - 1 << '\n';
        }
    }

    return 0;
}