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
//#define int long long
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
const int maxn = 1010;
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

int tc, n, lv[maxn], root, lca, dist[maxn][maxn], distt, depth;
bool mk[maxn];
vector<int> g[maxn], bestroots, goodroots, nodlv[maxn];

void dfs_dist(int u,int r){
    for( auto v : g[u] ){
        if( dist[r][v] > dist[r][u] + 1 ){
            dist[r][v] = dist[r][u] + 1;
            dfs_dist(v,r);
        }
    }
}

ii query(int level){
    vector<int> vv;
    for(int i=level; i<=512; i++)
        for( auto j : nodlv[i] )
            vv.pb(j);
    cout << '?' << ' ' << vv.size() << ' ';
    for(int i=0; i<vv.size(); i++){
        cout << vv[i];
        if( i < vv.size() - 1 ) cout << ' ';
            else cout << '\n';
    }
    cout.flush();
    ii aa;
    cin >> aa.f >> aa.s;
    return aa;
}

void dfs(int u){
    for( auto v : g[u] )
        if( !lv[v] ){
            lv[v] = lv[u] + 1;
            dfs(v);
        }
}

void dfs2(int u){
    mk[u] = 1;
    for( auto v : g[u] )
        if( !mk[v] && v != lca ){
            dfs2(v);
        }
}

void try_root(int nod){
    for(int i=1; i<=n; i++)
        lv[i] = 0;
    lv[nod] = 1;
    dfs(nod);
    int mx = 0;
    for(int i=1; i<=n; i++)
        mx = max( lv[i] , mx );
    if( mx < 256 ) bestroots.pb(nod);
    if( mx < 512 ) goodroots.pb(nod);
}

void root_the_tree(int nod){
    root = nod;
    for(int i=1; i<=n; i++)
        lv[i] = 0;
    lv[nod] = 1;
    dfs(nod);
    for(int i=1; i<=n; i++){
        nodlv[lv[i]].pb(i);
        depth = max( depth , lv[i] );
    }
}

int findp(ii cl){
    if( cl.s <= 0 ) return cl.f;
    for( auto v : g[cl.f] )
        if( lv[v] < lv[cl.f] )
            return findp({v,cl.s-1});
       // db("RA")
}

int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.setf(ios::fixed); cout.precision(0);
    srand(time(NULL));

    //freopen("a.in","r",stdin);
    //freopen("a.in","w",stdout);

    cin >> tc;
    while( tc-- ){
        cin >> n;

        distt = 0;
        depth = 0;

        for(int i=1; i<=1000; i++)
            nodlv[i].clear();

        bestroots.clear();
        goodroots.clear();
        for(int i=1; i<=n; i++){
            g[i].clear();
            nodlv[i].clear();
        }

        for(int i=1; i<n; i++){
            int u, v;
            cin >> u >> v;
            g[u].pb(v);
            g[v].pb(u);
        }

        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                dist[i][j] = mod;
            }
        }

        for(int i=1; i<=n; i++){
            dist[i][i] = 0;
            dfs_dist(i,i);
        }

        for(int i=1; i<=n; i++)
            try_root(i);

        //db(1<<9)
        if( !bestroots.empty() ){
            root_the_tree(bestroots[0]);
            //ii nwt = query(1);
            //distt = nwt.s;
            int lvlca = depth + 1;//db(root)
            //lca = nwt.f;//db(distt)
            for(int i=(1<<9); i>0; i/=2){//db(i)
                ii a;
                if( lvlca - i <= 1 && lvlca - i/2 > 1 ){
                    a = query(1);
                    distt = a.s;
                    lca = a.f;//db(distt)
                }
                else{
                    if( lvlca - i <= 0 ) continue;//db(i)
                    a = query(lvlca-i);//db(a.f)db(a.s)
                }
                if( distt == 0 ){ distt = a.s; }
                if( a.s == distt ){
                    lca = a.f;
                }
                else{
                    lvlca -= i;
                }
                if(i==0)break;
            }
        }
        else{
            root_the_tree(goodroots[rand()%(int)goodroots.size()]);
            //ii nwt = query(1);
            //distt = nwt.s;
            int lvlca = depth + 1;//db(root)
            //lca = nwt.f;//db(distt)
            for(int i=(1<<9); i>0; i/=2){//db(i)
                ii a;
                if( lvlca - i <= 1 && lvlca - i/2 > 1 ){
                    a = query(1);
                    distt = a.s;
                    lca = a.f;//db(distt)
                }
                else{
                    if( lvlca - i <= 0 ) continue;
                    a = query(lvlca-i);//db(a.f)db(a.s)
                }
                if( distt == 0 ){ distt = a.s; }
                if( a.s == distt ){
                    lca = a.f;
                }
                else{
                    lvlca -= i;
                }
                if(i==0)break;
            }
        }

        /*
        vector<int> w;
        for(int i=1; i<=n; i++){
            if( g[i].size() == 1 && i != root )
                w.pb(i);
        }

        cout << '?' << ' ' << w.size() << ' ';
        for(int i=0; i<w.size(); i++){
            cout << w[i];
            if( i < w.size() - 1 ) cout << ' ';
                else cout << '\n';
        }
        cout.flush();
        ii cl;
        cin >> cl.f >> cl.s;//db("bu")

        //root_the_tree(lca);
        dfs2(cl.f);
        //root_the_tree(root);
        //db(cl.s)
        cl.s -= distt;//db(cl.s)
        cl.s /= 2;
        root_the_tree(lca);
        int f = findp(cl);


        w.clear();
        for(int i=1; i<=n; i++){
            if( g[i].size() == 1 && ( i != root && !mk[i] ) )
                w.pb(i);
            //db(mk[i])
        }

        int s;
        if( w.size() == 0 ){
            s = lca;//db(lca)
        }
        else{

            cout << '?' << ' ' << w.size() << ' ';
            for(int i=0; i<w.size(); i++){
                cout << w[i];
                if( i < w.size() - 1 ) cout << ' ';
                    else cout << '\n';
            }
            cout.flush();
            //ii cl;
            cin >> cl.f >> cl.s;

            //db(cl.s)
            cl.s -= dist[cl.f][f];
            int d = 0;
            //db(cl.s)

            s = findp(cl);//db("pra")
        }
        */

        int f = lca;

        vector<int> w;
        for(int i=1; i<=n; i++){
            if( dist[i][f] == distt ) w.pb(i);
        }

        cout << '?' << ' ' << w.size() << ' ';
        for(int i=0; i<w.size(); i++){
            cout << w[i];
            if( i < w.size() - 1 ) cout << ' ';
                else cout << '\n';
        }
        cout.flush();
        ii cl;
        cin >> cl.f >> cl.s;

        cout << "! " << f << ' ' << cl.f << '\n';
        cout.flush();
        string result;
        cin >> result;
        if( result == "Incorrect" ) return 0;
    }

    return 0;
}