    /**   Created by: Humberto Yusta
          Codeforces User: humbertoyusta
          Country: Cuba
          Copyright                    */
#include<bits/stdc++.h>
using namespace std;
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
typedef double ld;
typedef unsigned long long ull;
/// Constraints:
const int maxn = 100010;
const int mod = 1000000007;
const ld eps = 1e-12;
const int inf = ((1ll<<31ll)-1ll);
const int INF = (((1ll<<59ll)-1ll)*2ll)+1ll;
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

int tc;
ld n, res, rad;
vector<pair<ld,ld>> v;

ld len(int x){
    ld thuus = 0;
    for(ld i=0; i + eps <= 180.0; i += (180.0)/x ){
        if( fabs(i-0) < eps || fabs(i-180) < eps ) continue;
        thuus += sin(i*pi/180.0);
    }
    return thuus;
}

ld f(ld ang){
    ang = ang * pi / 180;
    ld mnx = mod;
    ld mny = mod;
    ld mxx = -mod;
    ld mxy = -mod;
    ld tmp = 0;
    ld add = ( 360.0 / ( 2 * n ) ) * pi / 180.0;
    for( auto i : v ){
        ld nx = ( rad * cos ( ( ang + tmp ) ) );
        mnx = min( mnx , nx );
        mxx = max( mxx , nx );

        ld ny = ( rad * sin ( ( ang + tmp ) ) );
        mny = min( mny , ny );
        mxy = max( mxy , ny );

        tmp += add;
    }
    return max( mxx - mnx , mxy - mny );
}

int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.setf(ios::fixed); cout.precision(9);
    srand(time(NULL));

    //freopen("a.in","r",stdin);
    //freopen("a.out","w",stdout);

    cin >> tc;
    while( tc-- ){

        n, res;
        v.clear();
        cin >> n;

        rad = ( len(n) / 2.0 ) / sin( ( ( 90.0 - 360.0 / (4.0*n) ) ) * pi / 180.0 );
        for(ld i=0; i<360.0-eps; i+=(360.0/(2*n)))
            v.pb({rad*cos(i*pi/180.0),rad*sin(i*pi/180.0)});

        pair<ld,ld> mn({mod,mod});
        ld l = 0.0 , r = 360.0, ch = ( r - l ) / 30.0;
        for(ld i=l; i<=r; i+=ch){
            mn = min( mn , { f(i) , i } );
        }

        for(int t=1; t<=6; t++){
            l = mn.s - ch, r = mn.s + ch, ch = ( r - l ) / 30.0;
            for(ld i=l; i<=r; i+=ch){
                mn = min( mn , { f(i) , i } );
            }
        }

        cout << mn.f << '\n';
    }

    return 0;
}