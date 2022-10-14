    /**   Created by: Humberto Yusta
          Codeforces User: humbertoyusta
          Country: Cuba                    */
#include<bits/stdc++.h>
using namespace std;
/// Pragmas
#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline","03") // Optimization flags
//#pragma GCC option("arch=native","tune=native","no-zero=upper") // Enable AVX
//#pragma GCC target("avx2") // Enable AVX
//#pragma comment(linker, "/STACK:1024000000,1024000000") // Increase stack limit
//#pragma GCC target("sse,sse2,sse,ssse3,sse4,popcnt,abm,mmx,avx,tune=native") // I don't know what it is
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
const int maxn = 1000010;
const int maxm = 2020;
const int mod = 1000000007;
const int mod2 = 998244353;
const ld eps = 1e-9;
const int inf = ((1ll<<31ll)-1ll);
const int INF = mod;
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
    if( e & 1 ) return qpow(b,e-1) * b;
    int pwur = qpow(b,e>>1);
    return pwur * pwur;
}
int modinv(int x){ return qpow(x,mod-2); }
bool isprime(int x){
    for(int i=2; i*i<=x; i++)
        if( x % i == 0 )
            return false;
    return true;
}
/// My Code -------------------------------------------------

int pr[maxn];

ull hash_(vector<int> v){
    ull h_ = 0;
    for( auto i : v )
        h_ = h_ * 311 + i;
    return h_;
}

int mult(vector<int> v){
    int mult_ = 1;
    for( auto i : v )
        mult_ *= ( i + 1 );
    return mult_;
}

vector<int> fact(int x){
    vector<int> ret;
    int prv = 0;
    while( x > 1 ){
        if( ret.empty() || prv != pr[x] )
            ret.pb(1);
        else
            ret[ret.size()-1] ++;
        prv = pr[x];
        x /= pr[x];
    }
    return ret;
}

int diff(vector<int> a,vector<int> b){
    int ret = 0;
    if( a.size() < b.size() )
        swap( a, b );
    reverse(all(a));
    reverse(all(b));
    for(int i=0; i<b.size(); i++)
        ret += abs( a[i] - b[i] );
    for(int i=b.size(); i<a.size(); i++)
        ret += a[i];
    return ret;
}

set<vector<int>> sv;

void generate_(int x,vector<int> vx){
    if( x == 1 ){
        reverse(all(vx));
        sv.insert(vx);
        return;
    }
    for(int i=1; i<x; i++){
        if( vx.empty() || i <= vx.back() )
            if( x % ( i + 1 ) == 0 ){
                vx.pb(i);
                generate_(x/(i+1),vx);
                vx.pop_back();
            }
    }
}

int dist[maxm][maxm];
int ans[maxm][maxm];
int sol[maxm][maxm];

int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.setf(ios::fixed); cout.precision(10);
    srand(time(NULL));

    //freopen("a.in","r",stdin);
    //freopen("a.in","w",stdout);

    for(int i=1; i<maxn; i++)
        pr[i] = i;
    for(int i=2; i*i<maxn; i++){
        if( pr[i] == i ){
            for(int j=i*i; j<maxn; j+=i){
                pr[j] = min( pr[j] , i );
            }
        }
    }

    set<pair<ull,int>> s;
    for(int i=1; i<maxn; i++){
        vector<int> v = fact(i);
        sort(all(v));

        pair<ull,int> h = { hash_(v) , mult(v) };
        auto it = s.lower_bound(h);
        if( it == s.end() || *it != h ){
            for(int j=0; j<v.size(); j++){
                vector<int> w = v;

                w[j] ++;
                sort(all(w));
                sv.insert(w);

                w = v;

                w[j] --;
                if( w[j] < 0 ) continue;
                if( w[j] == 0 ){
                    sort(all(w));
                    reverse(all(w));
                    w.pop_back();
                }
                sort(all(w));
                sv.insert(w);
            }
            vector<int> w = v;
            w.pb(1);
            sort(all(w));
            sv.insert(w);
            sv.insert(v);
        }
        s.insert(h);
    }

    for(int t=1; t<=1; t++){
        set<vector<int>> sv2;
        for( auto v : sv ){
            for(int j=0; j<v.size(); j++){
                vector<int> w = v;

                w[j] ++;
                sort(all(w));
                sv2.insert(w);

                w = v;

                w[j] --;
                if( w[j] < 0 ) continue;
                if( w[j] == 0 ){
                    sort(all(w));
                    reverse(all(w));
                    w.pop_back();
                }
                sort(all(w));
                sv2.insert(w);
            }
            vector<int> w = v;
            w.pb(1);
            sort(all(w));
            sv2.insert(w);
        }
        for( auto i : sv2 )
            sv.insert(i);
    }

    vector<int> empty_vector;
    for(int i=1; i<=300; i++)
        generate_(i,empty_vector);

    int cnt = 0;
    map<ull,int> mp;
    vector<vector<int>> vx;
    for( auto i : sv ){
        mp[hash_(i)] = cnt++;
        vx.pb(i);
    }

    db(cnt)

    for(int i=0; i<cnt; i++)
        for(int j=0; j<maxm; j++){
            ans[i][j] = INF;
            sol[i][j] = INF;
        }

    for(int i=0; i<cnt; i++)
        for(int j=0; j<cnt; j++)
            dist[i][j] = diff(vx[i],vx[j]);

//    for(int k=0; k<cnt; k++)
//        for(int i=0; i<cnt; i++)
//            for(int j=0; j<cnt; j++)
//                dist[i][j] = min( dist[i][j] , dist[i][k] + dist[k][j] );

    set<int> adj;
    vector<int> ad;
    for(int i=0; i<cnt; i++)
        for(int j=0; j<cnt; j++){
            ans[i][mult(vx[j])] = min( ans[i][mult(vx[j])] , dist[i][j] );
            if( i == 0 )
                adj.insert(mult(vx[j]));
        }

    for( auto i : adj )
        ad.pb(i);

    for(int i=0; i<cnt; i++)
        for(int j=i; j<cnt; j++){
            for( auto k : ad ){
                sol[i][j] = min( sol[i][j] , ans[i][k] + ans[j][k] );
            }
        }

    int q;
    cin >> q;
    for(int i=1; i<=q; i++){
        int u, v;
        cin >> u >> v;
        vector<int> a = fact(u), b = fact(v);
        sort(all(a)); sort(all(b));
        if( mult(a) == mult(b) ){
            cout << 0 << '\n';
            continue;
        }
        int x = mp[hash_(a)];
        int y = mp[hash_(b)];
        if( x > y ) swap( x ,y );
        cout << sol[x][y] << '\n';
    }

    return 0;
}