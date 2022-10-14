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
const int maxn = 505;
const int mod = 1000000007;
const ld eps = 1e-9;
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
/// My Code -------------------------------------------------

int n, a[maxn][maxn];

void odd(int i,int j,int num){
    a[i][j] = num;
    if( i == n-3 && j == 2 ) i++;
    if( i == n && j == n - 1 ){ odd(1,j,num+1); return; }
    if( i == 1 && j == n - 1 ){ if( n == 3 ){ odd(i,n,num+1); return; } odd(1,2,num+1); return; }
    if( i == 1 && j == n ){ odd(i+1,j,num+1); return; }
    if( i == 1 ){ if( j + 1 == n - 1 ) j++; odd(i,j+1,num+1); return; }
    if( j == n ){ if( i == n ) return; odd(i+1,j,num+1); return; }
    if( i == 2 && j % 2 == 1 ){ odd(i,j+1,num+1); return; }
    if( i == n && j % 2 == 0 ){ odd(i,j+1,num+1); return; }
    if( i > 2 && j % 2 == 1 ){ odd(i-1,j,num+1); return; }
    if( i < n && j % 2 == 0 ){ odd(i+1,j,num+1); return; }
}

void even(int i,int j,int num){
    a[i][j] = num;
    if( i == n-3 && j == 2 ) i++;
    if( i == 2 && j == n - 1 ){ even(1,j,num+1); return; }
    if( i == 1 && j == n - 1 ){ even(1,2,num+1); return; }
    if( i == 1 && j == n ){ even(i+1,j,num+1); return; }
    if( i == 1 ){ if( j + 1 == n - 1 ) j++; even(i,j+1,num+1); return; }
    if( j == n ){ if( i == n ) return; even(i+1,j,num+1); return; }
    if( i == 2 && j % 2 == 1 ){ even(i,j+1,num+1); return; }
    if( i == n && j % 2 == 0 ){ even(i,j+1,num+1); return; }
    if( i > 2 && j % 2 == 1 ){ even(i-1,j,num+1); return; }
    if( i < n && j % 2 == 0 ){ even(i+1,j,num+1); return; }
}

int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.setf(ios::fixed); cout.precision(0);
    srand(time(NULL));

    //freopen("a.in","r",stdin);
    //freopen("a.out","w",stdout);

    cin >> n;

    if ( n == 3 ){
        cout << "6 2 1\n";
        cout << "5 4 9\n";
        cout << "8 3 7\n";
        return 0;
    }

    if ( n == 4 ){
        cout << "13 9 3 2\n";
        cout << "11 10 4 1\n";
        cout << "12 8 5 16\n";
        cout << "15 7 6 14\n";
        return 0;
    }

    if( n < 5 ){ cout << -1; return 0; }

    if( n % 2 == 1 ) odd(n-1,1,1);
        else even(n-1,1,1);

    a[1][1] = n * n - 3;
    a[n][1] = n * n - 1;
    a[n][n] = n * n - 2;
    a[n-1][n] = n * n;
    a[n-2][2] = n * n - 4;

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cout << a[i][j];
            if( j < n ) cout << ' ';
                else cout << '\n';
        }
    }

    return 0;
}