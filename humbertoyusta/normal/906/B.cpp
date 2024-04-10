    /**   Created by: Humberto Yusta
          Codeforces User: humbertoyusta
          Country: Cuba
          Copyright                    */
#include<bits/stdc++.h>
using namespace std;
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
const int maxn = 100010;
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
int modinv(int x){
    return qpow(x,mod-2);
}
/// My Code -------------------------------------------------

int n, m, b[maxn][2], c[maxn][2];
ii match[maxn];
set<int> s1, s2;

int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.setf(ios::fixed); cout.precision(0);
    srand(time(NULL));

    //freopen("a.in","r",stdin);
    //freopen("a.out","w",stdout);

    cin >> n >> m;

    if( n == 1 && m == 4 ){
        cout << "YES\n";
        cout << 2 << ' ' << 4 << ' ' << 1 << ' ' << 3 << '\n';
        return 0;
    }

    if( n == 4 && m == 1 ){
        cout << "YES\n";
        cout << 2 << '\n' << 4 << '\n' << 1 << '\n' << 3 << '\n';
        return 0;
    }

    if(  n == 1 && m == 1 ){
        cout << "YES\n";
        cout << 1 << '\n';
        return 0;
    }

    if( n == 3 && m == 3 ){
        cout << "YES\n";
        cout << 6 << ' ' << 1 << ' ' << 8 << '\n';
        cout << 7 << ' ' << 5 << ' ' << 3 << '\n';
        cout << 2 << ' ' << 9 << ' ' << 4 << '\n';
        return 0;
    }

    if( n <= 2 && m <= 2 ){ cout << "NO\n"; return 0; }
    if( n <= 3 && m <= 3 ){ cout << "NO\n"; return 0; }

    if( n == 1 ){
        cout << "YES\n";
        for(int i=1; i<=m; i+=2)
            cout << i << ' ';
        for(int i=2; i<=m; i+=2){
            cout << i;
            if( i == n || i == m - 1 ) cout << '\n';
                else cout << ' ';
        }
        return 0;
    }

    if( m == 1 ){
        cout << "YES\n";
        for(int i=1; i<=n; i+=2)
            cout << i << '\n';
        for(int i=2; i<=n; i+=2){
            cout << i;
            if( i == n || i == n - 1 ) cout << '\n';
                else cout << '\n';
        }
        return 0;
    }


    int a[n+1][m+1];
    memset( a , 0 , sizeof a );

    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if( ( i + j ) % 2 == 0 ) s1.insert((i-1)*m+j);
                else s2.insert((i-1)*m+j);
        }
    }

    s1.insert(mod);
    s2.insert(mod);

    if( n <= m ){
        for(int i=1; i<=m; i++){
            b[i][0] = i;
            if( *s1.lower_bound(i) == i ) s1.erase(i);
            if( *s2.lower_bound(i) == i ) s2.erase(i);
        }
        for(int i=1; i<=m; i++){
            b[i][1] = m+i;
            if( *s1.lower_bound(m+i) == m+i ) s1.erase(m+i);
            if( *s2.lower_bound(m+i) == m+i ) s2.erase(m+i);
        }
        for(int i=1; i<=m; i++){
            if( i == m - 1 ){
                if( i % 2 ) match[i] = { b[i][0] , b[1][1] };
                    else match[i] = { b[i][1] , b[1][1] };
                continue;
            }
            if( i == m ){
                if( i % 2 ) match[i] = { b[i][0] , b[2][0] };
                    else match[i] = { b[i][1] , b[2][0] };
                continue;
            }
            if( i % 2 ) match[i] = { b[i][0] , b[i+2][1] };
                else match[i] = { b[i][1] , b[i+2][0] };
        }

        int mx = 0;
        for(int i=1; i<=((n*m+1)/2%m); i++){
            a[(n+2)/2][i] = match[i].f;
            a[(n+2)/2+1][i] = match[i].s;
            mx = i;
        }
        for(int i=mx+1; i<=m; i++){
            a[(n+2)/2-1][i] = match[i].f;
            a[(n+2)/2][i] = match[i].s;
        }

        for(int i=1; i<=n/2; i++){
            for(int j=1; j<=m; j++){
                if( !a[i][j] ){
                    a[i][j] = *s1.begin();
                    s1.erase(s1.begin());
                }
            }
        }

        for(int i=n/2+1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if( !a[i][j] ){
                    a[i][j] = *s2.begin();
                    s2.erase(s2.begin());
                }
            }
        }
    }
    else{
        for(int i=1; i<=n; i++){
            b[i][0] = (i-1)*m+1;
            if( *s1.lower_bound((i-1)*m+1) == (i-1)*m+1 ) s1.erase((i-1)*m+1);
            if( *s2.lower_bound((i-1)*m+1) == (i-1)*m+1 ) s2.erase((i-1)*m+1);
        }
        for(int i=1; i<=n; i++){
            b[i][1] = (i-1)*m+2;
            if( *s1.lower_bound((i-1)*m+2) == (i-1)*m+2 ) s1.erase((i-1)*m+2);
            if( *s2.lower_bound((i-1)*m+2) == (i-1)*m+2 ) s2.erase((i-1)*m+2);
        }
        for(int i=1; i<=n; i++){
            if( i == n - 1 ){
                if( i % 2 ) match[i] = { b[i][0] , b[1][1] };
                    else match[i] = { b[i][1] , b[1][1] };
                continue;
            }
            if( i == n ){
                if( i % 2 ) match[i] = { b[i][0] , b[2][0] };
                    else match[i] = { b[i][1] , b[2][0] };
                continue;
            }
            if( i % 2 ) match[i] = { b[i][0] , b[i+2][1] };
                else match[i] = { b[i][1] , b[i+2][0] };
        }

        int mx = 0;
        for(int i=1; i<=((n*m+1)/2%n); i++){
            a[i][(m+2)/2] = match[i].f;
            a[i][(m+2)/2+1] = match[i].s;
            mx = i;
        }
        for(int i=mx+1; i<=n; i++){
            a[i][(m+2)/2-1] = match[i].f;
            a[i][(m+2)/2] = match[i].s;
        }

        for(int i=1; i<=m/2; i++){
            for(int j=1; j<=n; j++){
                if( !a[j][i] ){
                    a[j][i] = *s1.begin();
                    s1.erase(s1.begin());
                }
            }
        }
        for(int i=m/2+1; i<=m; i++){
            for(int j=1; j<=n; j++){
                if( !a[j][i] ){
                    a[j][i] = *s2.begin();
                    s2.erase(s2.begin());
                }
            }
        }
    }

    cout << "YES\n";

    for(int i=1; i<=n; i ++){
        for(int j=1; j<=m; j++){
            cout << a[i][j];
            if( j < m ) cout << ' ';
                else cout << '\n';
        }
    }

    return 0;
}