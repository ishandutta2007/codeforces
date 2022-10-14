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
const int maxn = 2020;
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

int n, m, k, l[maxn], r[maxn], lazym[maxn], lazyn[maxn], a[maxn][maxn], ans[maxn], bestans, mx[maxn], fm[maxn], lm[maxn];

int intersection(int a,int b,int c,int d){
    return max( 0ll , min( b , d ) - max( a , c ) + 1 );
}

int f(int seg,int st){
    return intersection(l[seg],r[seg],st,st+k-1);
}

void plus_x(int x,int y,int val){
    if( x > y ) return;
    lazym[x] += val;
    lazym[y+1] -= val;
}

void plus_inc_one(int x,int y){
    if( x < 1 ){
        x = 1;
        plus_x(x,y,1-x);
    }
    if( x > y ) return;
    lazyn[x] ++;
    lazyn[y+1] --;
    lazym[x] -= x - 1;
    lazym[y+1] += x - 1;
}

void plus_dec_one(int x,int y){
    int tmp = 0;
    if( y > n ){
        tmp = y - n;
        y = n;
    }
    if( x > y ) return;
    lazyn[x] --;
    lazyn[y+1] ++;
    lazym[x] += y + 1 + tmp;
    lazym[y+1] -= y + 1 + tmp;
}

int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.setf(ios::fixed); cout.precision(0);
    srand(time(NULL));

    //freopen("a.in","r",stdin);
    //freopen("a.out","w",stdout);

    cin >> n >> m >> k;

    for(int i=1; i<=m; i++){
        cin >> l[i] >> r[i];
    }

    for(int i=1; i<=m; i++){
        fm[i] = 1;
        for(int j=1; j<=n; j++){
            a[i][j] = f(i,j);
            if( a[i][j] == mx[i] )
                lm[i] = j;
            if( a[i][j] > mx[i] ){
                mx[i] = a[i][j];
                fm[i] = lm[i] = j;
            }
        }
    }

    for(int i=1; i<=n; i++){
        for(int j=0; j<=n; j++)
            lazyn[j] = lazym[j] = 0;
        for(int j=1; j<=m; j++){
            plus_x(1,n,f(j,i));
            if( mx[j] <= f(j,i) ){
                continue;
            }
            int c1 = fm[j] - ( mx[j] - f(j,i) );
            int c2 = lm[j] + ( mx[j] - f(j,i) );
            if( fm[j] < lm[j] ){
                plus_inc_one(c1+1,fm[j]);
                plus_x(fm[j]+1,lm[j]-1,mx[j]-f(j,i));
                plus_dec_one(lm[j],c2-1);
            }
            else{
                plus_inc_one(c1+1,fm[j]);
                plus_dec_one(lm[j]+1,c2-1);
            }
        }
        for(int j=1; j<=n; j++){
            lazyn[j] += lazyn[j-1];
            lazym[j] += lazym[j-1];
            //db(lazyn[j])
            //db(lazym[j])
            //if( j > i )
                bestans = max( bestans , lazyn[j] * j + lazym[j] );
        }
        //cout << bestans << '\n';
        //return 0;
    }
    cout << bestans << '\n';

    return 0;
}