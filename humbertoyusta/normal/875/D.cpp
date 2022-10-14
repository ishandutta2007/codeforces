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
typedef long double ld;
typedef unsigned long long ull;
/// Constraints:
const int maxn = 200002;
const int mod = 1000000000;
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
    if( e & 1 ) return qpow(b,e-1) * b;
    int pwur = qpow(b,e>>1);
    return pwur * pwur;
}
int modinv(int x){
    return qpow(x,mod-2);
}
/// My Code -------------------------------------------------

int n, a[maxn], roq[18][maxn], ans;
ii rmq[18][maxn];

ii query_max(int l, int r){
    int lg = log2(r-l+1);
    return max( rmq[lg][l] , rmq[lg][r-(1<<lg)+1] );
}

int query_or(int l, int r){
    int lg = log2(r-l+1);
    return roq[lg][l] | roq[lg][r-(1<<lg)+1];
}

void DandC(int l,int r){
    if( l >= r ) return;
    int mid = query_max(l,r).s;
    if( mid - l <= r - mid ){
        for(int i=l; i<=mid; i++){
            int bsl = mid, bsr = r;
            while( bsl < bsr ){
                int bsmid = ( bsl + bsr ) >> 1;
                if( query_or(i,bsmid) <= a[mid] ) bsl = bsmid + 1;
                    else bsr = bsmid;
            }
            if( query_or(i,bsl) <= a[mid] && bsl + 1 <= r + 1 ) bsl++;
            if( query_or(i,bsl-1) > a[mid] && bsl - 1 >= mid ) bsl--;//if(l==1&&r==3)db(bsl)
            ans += max( 0ll , r - bsl + 1 );
        }
    }
    else{
        for(int i=r; i>=mid; i--){
            int bsl = l, bsr = mid;
            while( bsl < bsr ){
                int bsmid = ( bsl + bsr ) >> 1;
                if( query_or(bsmid,i) > a[mid] ) bsl = bsmid + 1;
                    else bsr = bsmid;
            }
            if( query_or(bsl,i) <= a[mid] && bsl - 1 >= l - 1 ) bsl--;
            if( query_or(bsl+1,i) > a[mid] && bsl + 1 <= mid ) bsl++;
            ans += max( 0ll , bsl - l + 1 );
        }
    }
    //db(l)db(r)db(ans)
    DandC(l,mid-1);
    DandC(mid+1,r);
}

int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.setf(ios::fixed); cout.precision(0);
    srand(time(NULL));

    //freopen("a.in","r",stdin);
//    freopen("a.out","w",stdout);

    cin >> n;

    for(int i=1; i<=n; i++){
        cin >> a[i];
        roq[0][i] = a[i];
        rmq[0][i] = { a[i] , i };
    }

    for(int i=1; i<18; i++)
        for(int j=1; j+(1<<(i-1))<=n; j++){
            rmq[i][j] = max( rmq[i-1][j] , rmq[i-1][j+(1<<(i-1))] );
            roq[i][j] = roq[i-1][j] | roq[i-1][j+(1<<(i-1))];
        }

    DandC(1,n);

    cout << ans << '\n';

    return 0;
}