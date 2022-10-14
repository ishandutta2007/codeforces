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
const int maxn = 1010;
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

int query(vector<int> v){
    cout << "? " << v.size() << ' ';
    for( auto i : v ) cout << i + 1 << ' ';
    cout << '\n';
    cout.flush();
    int ret;
    cin >> ret;
    return ret;
}

int query(set<int> v){
    cout << "? " << v.size() << ' ';
    for( auto i : v ) cout << i + 1 << ' ';
    cout << '\n';
    cout.flush();
    int ret;
    cin >> ret;
    return ret;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.setf(ios::fixed); cout.precision(10);

    //freopen("a.in","r",stdin);
    //freopen("a.in","w",stdout);

    int tc;
    tc = 1;
    while( tc-- ){
        int n;
        cin >> n;

        vector<int> g[n];
        vector<vector<int>> mk(n,vector<int>(n));
        for(int i=0; i<n-1; i++){
            int u, v;
            cin >> u >> v;
            v--, u--;
            g[u].push_back(v);
            g[v].push_back(u);
        }

        vector<int> vx;
        for(int i=0; i<n; i++)
            vx.push_back(i);
        int mxdist = query(vx);

        if( n == 2 ){
            cout << "! " << 1 << ' ' << 2 << '\n';
            cout.flush();
            return 0;
        }

        int edges = n - 1;
        int needed = edges / 2;

        while( edges != 1 ){
            set<int> s;
            for(int i=0; i<n; i++){
                function<void(int,int)> dfs = [&](int u,int p){
                    if( !needed ) return;
                    for( auto v : g[u] ){
                        if( v == p ) continue;
                        if( !needed ) return;
                        if( !mk[u][v] ){
                            mk[u][v] = 1;
                            mk[v][u] = 1;
                            s.insert(u);
                            s.insert(v);
                            needed --;db(u)db(v)
                            dfs(v,u);
                        }
                    }
                };
                dfs(i,i);
            }
            int x = query(s);
            edges = 0;
            pair<int,int> curr;
            vector<pair<pair<int,int>,int>> to;
            if( x == mxdist ){
                for(int i=0; i<n; i++){
                    function<void(int,int)> dfs2 = [&](int u,int p){
                        for( auto v : g[u] ){
                            if( v == p ) continue;
                            if( mk[u][v] == 1 ){
                                curr = { u , v };
                                to.push_back({{u,v},0});
                                mk[u][v] = 2;
                                mk[v][u] = 2;
                                edges ++;
                                dfs2(v,u);
                            }
                            if( mk[u][v] == 0 ){
                                to.push_back({{u,v},2});
                                mk[u][v] = 2;
                                mk[v][u] = 2;
                                dfs2(v,u);
                            }
                        }
                    };
                    dfs2(i,i);
                }
            }
            else{
                for(int i=0; i<n; i++){
                    function<void(int,int)> dfs2 = [&](int u,int p){
                        for( auto v : g[u] ){
                            if( v == p ) continue;
                            if( mk[u][v] == 0 ){
                                curr = { u , v };
                                to.push_back({{u,v},0});
                                mk[u][v] = 2;
                                mk[v][u] = 2;
                                edges ++;
                                dfs2(v,u);
                            }
                            if( mk[u][v] == 1 ){
                                to.push_back({{u,v},2});
                                mk[u][v] = 2;
                                mk[v][u] = 2;
                                dfs2(v,u);
                            }
                        }
                    };
                    dfs2(i,i);
                }
            }

            for( auto i : to ){
                mk[i.f.f][i.f.s] = i.s;
                mk[i.f.s][i.f.f] = i.s;
            }

            if( edges == 1 ){
                cout << "! " << curr.f+1 << ' ' << curr.s+1 << '\n';
                cout.flush();
                return 0;
            }
            else{
                needed = ( edges ) / 2;
            }
        }

    }

    return 0;
}