    /**   Created by: Humberto Yusta
          Codeforces User: humbertoyusta
          Country: Cuba
          Copyright                    */
#include<bits/stdc++.h>
using namespace std;
/// Pragmas:
#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline") //Optimization flags
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
const int maxn = 300010;
const int mod = 1000000007;
const ld eps = 1e-9;
const int inf = ((1ll<<31ll)-1ll);
const int INF = 1ll * mod * mod;
const ld pi = acos(-1);
/// Prime Numbers:
// 2, 173, 179, 181, 197, 311, 331, 737, 1009, 2011, 2027, 3079, 4001, 10037, 10079, 20011, 20089;
// 100003, 100019, 100043, 200003, 200017, 1000003, 1000033, 1000037, 1000081;
// 2000003, 2000029, 2000039, 1000000007, 1000000021, 2000000099;
/// rng
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
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

const int K = 26;

struct node{
    int nxt[K];
    int go[K];
    int slink;
    int elink;
    int leaf;
    int pch;
    int p;
    set<ii> s;
    int val;
    node(){}
    node(int tp,int tpch){
        s.clear();
        for(int i=0; i<K; i++)
            nxt[i] = go[i] = -1;
        slink = -1;
        elink = -1;
        leaf = 0;
        pch = tpch;
        p = tp;
        val = 0;
    }
};
vector<node> AHC;
int id[maxn], n, q, val[maxn];

void AHC_insert(string& s,int idx){
    int curr = 0;
    for(int i=0; i<s.size(); i++){
        int nch = ( s[i] - 'a' );
        if( AHC[curr].nxt[nch] == -1 ){
            AHC.pb(node(curr,nch));
            AHC[curr].nxt[nch] = AHC.size() - 1;
        }
        curr = AHC[curr].nxt[nch];
    }
    AHC[curr].leaf ++;
    id[idx] = curr;
}

int go(int nod,int ch);

int get_link(int nod){
    if( AHC[nod].slink == -1 ){
        if( nod == 0 || AHC[nod].p == 0 )
                AHC[nod].slink = 0;
            else
                AHC[nod].slink = go(get_link(AHC[nod].p),AHC[nod].pch);
    }
    return AHC[nod].slink;
}

int go(int nod,int ch){
    if( AHC[nod].go[ch] == -1 ){
        if( AHC[nod].nxt[ch] != -1 )
                AHC[nod].go[ch] = AHC[nod].nxt[ch];
            else{ if ( nod == 0 )
                        AHC[nod].go[ch] = 0;
                    else
                        AHC[nod].go[ch] = go(get_link(nod),ch); }
    }
    return AHC[nod].go[ch];
}

int end_link(int nod){
    if( AHC[nod].elink == -1 ){
        if( nod == 0 || AHC[nod].p == 0 )
                AHC[nod].elink = 0;
            else{
                int slink = get_link(nod);
                if( AHC[slink].leaf ) AHC[nod].elink = slink;
                    else AHC[nod].elink = end_link(slink);
            }

    }
    return AHC[nod].elink;
}

void AHC_build(int nod){

    get_link(nod);

    for(int i=0; i<K; i++)
        go(nod,i);

    end_link(nod);

    for(int i=0; i<K; i++)
        if( AHC[nod].nxt[i] != -1 )
            AHC_build(AHC[nod].nxt[i]);
}

int check(int nod){
    int ret = -1;
    if( nod >= 0 && !AHC[nod].s.empty() ) ret = max( ret , (*(--(AHC[nod].s).end())).f );
    if( nod <= 0 ) return ret;
    ret = max( ret , check(end_link(nod)) );
    return ret;
}

int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.setf(ios::fixed); cout.precision(0);
    srand(time(NULL));

    //freopen("a.in","r",stdin);
    //freopen("a.out","w",stdout);

    cin >> n >> q;

    AHC.pb(node(0,0));
    AHC[0].slink = AHC[0].elink = 0;

    for(int i=1; i<=n; i++){
        string s;
        cin >> s;
        AHC_insert(s,i);
    }

    AHC_build(0);

    for(int i=1; i<=n; i++){
        AHC[id[i]].s.insert({0,i});
    }

    for(int i=1; i<=q; i++){
        int typ; cin >> typ;
        if( typ == 1 ){
            int u, v;
            cin >> u >> v;
            AHC[id[u]].s.erase({val[u],u});
            val[u] = v;
            AHC[id[u]].s.insert({val[u],u});
        }
        if( typ == 2 ){
            string s;
            cin >> s;
            int curr = 0, mx = -1;
            for(int i=0; i<s.size(); i++){
                curr = go(curr,s[i]-'a');
                mx = max( mx , check(curr) );
            }
            cout << mx << '\n';
        }
    }

    return 0;
}