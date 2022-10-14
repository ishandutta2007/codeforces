/// Code by humbertoyusta
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
const int maxn = 200010;
const int mod = 1000000007;
const int mod2 = 998244353;
const double eps = 1e-9;
// Quick Functions------------------------------------------
int qpow(int b,int e){
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

vector<int> g[maxn];
int mk[maxn], buds, leaves, lst;

void dfs(int u,int p){

    bool can = 0;
    for( auto v : g[u] ){
        if( v == p ) continue;
        dfs(v,u);
        can |= ( mk[v] == 0 );
    }

    if( can == 0 && u != 1 )
        leaves ++;

    if( can ){
        buds ++;
        mk[u] = 1;
        for( auto v : g[u] ){
            if( v == p ) continue;
            mk[v] = 1;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.setf(ios::fixed); cout.precision(10);

    //freopen("a.in","r",stdin);
    //freopen("a.in","w",stdout);

    int tc;
    cin >> tc;
    while( tc-- ){

        int n;
        cin >> n;

        for(int i=1; i<=n; i++){
            g[i].clear();
            mk[i] = 0;
        }

        for(int i=1; i<n; i++){
            int u, v;
            cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
        }

        buds = leaves = 0;
        dfs(1,1);

        cout << leaves + 1 - buds << '\n';
    }

    return 0;
}