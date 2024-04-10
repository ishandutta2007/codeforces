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
const int INF = 1ll + mod + mod;
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

int n, mx;
vector<int> v[maxn];
vector<ii> ans;

void merge_(vector<int> vx){
    for(int i=0; (1<<i)<vx.size(); i++){
        for(int j=0; j<vx.size(); ){
            ans.pb({vx[j],vx[j+(1<<i)]});
            if( ( j + 1 ) & ( 1 << i ) ) j += ( 1 << i );
            j++;
        }
    }
}

vector<int> join_(vector<int> vx,vector<int> vy){
    vector<int> vz;
    for(int i=0; i<vx.size(); i++){
        ans.pb({vx[i],vy[i]});
        vz.pb(vx[i]);
        vz.pb(vy[i]);
    }
    return vz;
}

vector<int> split_(vector<int> vx,vector<int> vy){
    vector<int> vz;
    for(int i=0; i<vy.size(); i++){
        ans.pb({vx[i],vy[i]});
        vz.pb(vx[i]);
        vz.pb(vy[i]);
    }
    return vz;
}

vector<int> res_(vector<int> vx,vector<int> vy){
    vector<int> vz;
    for(int i=vy.size(); i<vx.size(); i++){
        //ans.pb({vx[i],vy[i]});
        vz.pb(vx[i]);
        //vz.pb(vy[i]);
    }
    return vz;
}

int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.setf(ios::fixed); cout.precision(0);
    srand(time(NULL));

    //freopen("a.in","r",stdin);
    //freopen("a.out","w",stdout);

    cin >> n;

    if( n <= 2 ){
        cout << 0 << '\n';
        return 0;
    }

    int st = 1;
    for(int i=20; i>=0; i--){
        if( st + ( 1 << i ) - 1 <= n ){
            for(int j=st; j<st+(1<<i); j++)
                v[i].pb(j);
            merge_(v[i]);
            st += ( 1 << i );
            mx = max( mx , i );
        }
    }

    while( true ){
        bool b = 0;
        bool b2 = 0;

        for(int i=0; i<=20; i++){
            if( b2 ) break;
            if( v[i].size() != 0 ){
                for(int j=0; j<=20; j++){
                    if( i != j && v[j].size() != 0 ){
                        if( v[i].size() == v[j].size() ){
                            v[j] = join_(v[i],v[j]);
                            v[i].clear();
                            b = 1;
                            b2 = 1;
                            break;
                        }
                        b = 0;
                        b2 = 1;
                        break;
                    }
                }
            }
        }

        if( b ) continue;
        b2 = 0;

        for(int i=20; i>=0; i--){
            if( b2 ) break;
            if( v[i].size() != 0 ){
                for(int j=0; j<=20; j++){
                    if( i != j && v[j].size() != 0 ){
                        if( i - j > 1 ){
                            vector<int> tmp = split_(v[i],v[j]);
                            vector<int> tmp2 = res_(v[i],v[j]);
                            v[i] = tmp2;
                            v[j] = tmp;
                            //db(i)db(j)
                            b = 0;
                            b2 = 1;
                            break;
                        }
                        b = 1;
                        b2 = 1;
                        break;
                    }
                }
            }
        }

        int cnt = 0;
        for(int i=0; i<=20; i++)
            if( v[i].size() > 0 ) cnt++;
        if( cnt <= 2 ) break;

    }

    cout << ans.size() << '\n';
    for( auto i : ans ) cout << i.f << ' ' << i.s << '\n';

    return 0;
}