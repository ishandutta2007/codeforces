    /**   Created by: Humberto Yusta
          Codeforces User: humbertoyusta
          Country: Cuba
          Copyright                    */
#include<bits/stdc++.h>
using namespace std;
/// Pragmas:
//#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline") //Optimization flags
//#pragma GCC option("arch=native","tune=native","no-zero-upper") //Enable AVX
//#pragma GCC target("avx2") //Enable AVX
/// Macros:
#define int long long
#define f first
#define s second
#define db(x) cerr << #x << ": " << (x) << '\n';
#define pb push_back
#define lb lower_bound
#define up upper_bound
#define all(x) x.begin() , x.end()
#define rall(x) x.rbegin() , x.rend()
#define enl '\n'
typedef pair<int,int> ii;
typedef long double ld;
typedef unsigned long long ull;
/// Constraints:
const int maxn = 1000010;
const int mod = 1000000007;
const ld eps = 1e-9;
const int inf = ((1ll<<31ll)-1ll);
const int INF = 2000000000000000000ll;
const ld pi = acos(-1);
/// Prime Numbers:
// 2, 173, 179, 181, 197, 311, 331, 737, 1009, 2011, 2027, 3079, 4001, 10037, 10079, 20011, 20089;
// 100003, 100019, 100043, 200003, 200017, 1000003, 1000033, 1000037, 1000081;
// 2000003, 2000029, 2000039, 1000000007, 1000000021, 2000000099;
/// Functions:
#define lg2(x) 31 - __builtin_clz(x)
#define lgx(x,b) ( log(x) / log(b) )
/// Red-Black Tree Template ---------------------------------
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
//typedef tree < long long ,  null_type ,  less<long long> ,  rb_tree_tag ,  tree_order_statistics_node_update > ordered_set;
/// Quick Pow------------------------------------------------
int qpow(int b,int e){
    if( !e ) return 1;
    if( e & 1 ) return qpow(b,e-1) * b % mod;
    int pwur = qpow(b,e>>1);
    return pwur * pwur % mod;
}
int modinv(int x){
    return qpow(x,mod-2);
}
/// My Code -------------------------------------------------

int n, ans[maxn], lv[maxn], subt[maxn], max_ans, dist[22][22], fx[2049];
ii dp[2049];
vector<int> g[maxn], w[maxn];

int calc_f(int x){
    vector<int> vk;
    for(int i=0; i<12; i++)
        if( ( (1<<i) & x ) != 0 )
            vk.pb(1+i);
    int result = 0;
    for(int i=0; i<vk.size(); i++){
        result += dist[vk[i]][vk[(i+1)%vk.size()]];
        //db(vk[i])
    }
    return result;
}

void back_track(int msk){
    if( msk == 0 ) return;
    //db(msk)
    vector<int> vk;
    for(int i=0; i<12; i++){
        if( ( (1<<i) & msk ) != 0 && ( (1<<i) & (msk^(dp[msk].s)) ) == 0 )
            vk.pb(i+1);
    }
    for(int i=0; i<vk.size(); i++){
        ans[vk[i]] = vk[(i+1)%vk.size()];
    }
    back_track(msk^(dp[msk].s));
}

void dfs_dist(int u,int p,int root){
    for( auto v : g[u] ){
        if( v != p ){
            dist[root][v] = dist[root][u] + 1;
            dfs_dist(v,u,root);
        }
    }
}

void first_dfs(int u,int p){
    if( u == p ) lv[u] = 1;
    subt[u] = 1;
    for( auto v : g[u] )
        if( v != p ){
            lv[v] = lv[u] + 1;
            first_dfs(v,u);
            subt[u] += subt[v];
        }
}

int get_centroid(int u,int p){
    int nxt = -1;
    for( auto v : g[u] )
        if( v != p ){
            if( lv[v] == lv[u] + 1 ){
                if( subt[v] > n / 2 )
                    return get_centroid(v,u);
            }
            else{
                if( subt[v] - subt[u] > n / 2 )
                    return get_centroid(v,u);
            }
        }
    if( nxt == -1 ) return u;
}

void dfs(int u,int p,int root){
    for( auto v : g[u] )
        if( v != p )
            dfs(v,u,root);
    w[root].pb(u);
}

int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.setf(ios::fixed); cout.precision(0);
    srand(time(NULL));

    //freopen("a.in","r",stdin);
    //freopen("a.in","w",stdout);

    cin >> n;

    if( n == 1 ){
        cout << 0 << '\n';
        cout << 1 << '\n';
        return 0;
    }
    if( n == 2 ){
        cout << 2 << '\n';
        cout << 2 << ' ' << 1 << '\n';
        return 0;
    }


    for(int i=1; i<n; i++){
        int u, v;
        cin >> u >> v;
        //db(u)db(v)
        g[u].pb(v);
        g[v].pb(u);
    }

    if( n <= 10 ){
        for(int i=1; i<=n; i++)
            dfs_dist(i,i,i);
        for(int i=1; i<(1<<n); i++){
            if( __builtin_popcountll(i) <= 1 ) continue;
            fx[i] = calc_f(i);
            //db(fx[i])
        }
        for(int i=1; i<(1<<n); i++){
            for(int j=1; j<(1<<n); j++){
                if( ( i & j ) != j ) continue;
                if( __builtin_popcountll(j) <= 1 ) continue;
                if( __builtin_popcountll(i^j) == 1 ) continue;
                //if(i==12){db(i)db(j)}
                if( dp[i^j].f + fx[j] > dp[i].f ){
                    dp[i] = { dp[i^j].f + fx[j] , j };
                }
            }
        }
        back_track((1<<n)-1);
        cout << dp[(1<<n)-1].f << '\n';
        for(int i=1; i<=n; i++)
            cout << ans[i] << ' ';
        cout << '\n';
        return 0;
    }

    first_dfs(1,1);

    int centroid = get_centroid(1,1);

    first_dfs(centroid,centroid);

    vector<ii> vx;
    for(auto i : g[centroid] )
        vx.pb({subt[i],i});
    sort(all(vx));
    reverse(all(vx));

    int cnt = 0;
    for( auto i : vx )
        dfs(i.s,centroid,++cnt);


    for(int i=1; i<=cnt; i++)
        reverse(all(w[i]));

    w[++cnt].pb(centroid);

    int step = n;

    if( step % 2 ){
        int p1, p2, p3;
        vector<ii> vx;
        for(int i=1; i<=cnt; i++)
            vx.pb({lv[w[i].back()],i});
        sort(all(vx));
        reverse(all(vx));
        p1 = vx[0].s;
        p2 = vx[1].s;
        p3 = vx[2].s;
        while( w[p1].empty() ) p1++;
        while( w[p2].empty() || p2 <= p1 ) p2++;
        while( w[p3].empty() || p3 <= p2 ) p3++;
        ans[w[p1].back()] = w[p2].back();
        max_ans += lv[w[p1].back()] + lv[w[p2].back()] - 2 * lv[centroid];
        ans[w[p2].back()] = w[p3].back();
        max_ans += lv[w[p2].back()] + lv[w[p3].back()] - 2 * lv[centroid];
        ans[w[p3].back()] = w[p1].back();
        max_ans += lv[w[p3].back()] + lv[w[p1].back()] - 2 * lv[centroid];
        w[p1].pop_back();
        w[p2].pop_back();
        w[p3].pop_back();
        step -= 3;
    }

    //for(int i=1; i<=cnt; i++){db(i)
    //    for(auto j:w[i])db(j)
    //}

//    int r = 2, l = 1;
//    while( step > 0 ){
//
//        while( w[r].empty() ) r++;
//        while( w[l].empty() ) l++;
//        while( l >= r ) r++;
//        while( w[r].empty() ) r++;
//        while( w[l].empty() ) l++;
//        //db(l)db(r)
//
//        ans[w[l].back()] = w[r].back();
//        max_ans += lv[w[l].back()] + lv[w[r].back()] - 2 * lv[centroid];
//        ans[w[r].back()] = w[l].back();
//        max_ans += lv[w[l].back()] + lv[w[r].back()] - 2 * lv[centroid];
//        w[l].pop_back();
//        w[r].pop_back();
//        step -= 2;
//    }
    vector<int> ed;
    for(int i=1; i<=cnt; i++){
        for(auto j : w[i] )
            ed.pb(j);
    }
    for(int i=0; i<ed.size(); i++){
        int u = ed[i];
        int v = ed[(i+w[1].size())%ed.size()];
        ans[u] = v;
        max_ans += lv[u] + lv[v] -2 * lv[centroid];
    }

    cout << max_ans << '\n';
    for(int i=1; i<=n; i++){
        if( ans[i] == 0 ) return 1 / 0;
        cout << ans[i] << ' ';
    }
    cout << '\n';

    return 0;
}