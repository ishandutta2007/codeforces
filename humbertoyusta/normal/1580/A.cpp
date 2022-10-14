#include<bits/stdc++.h>
using namespace std;
// Pragma
#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline","03")
// Macros:
#define f first
#define s second
typedef long long ll;
// debugging macros
#define db(x) cerr << #x << ": " << (x) << '\n';
#define db_v(x) cerr << #x << ": ["; for( auto i : (x) ) cerr << i << ", "; cerr << "]\n";
#define db_p(x) cerr << #x << ": " << (x).first << " " << (x).second << '\n';
// Constraints:
const int maxn = 404;
const int mod = 1000000007;
const int mod2 = 998244353;
const double eps = 1e-9;
// Quick Functions------------------------------------------
ll qpow(ll b,int e){
    if( !e ) return 1;
    if( e & 1 ) return qpow(b,e-1) * b % mod;
    int pwur = qpow(b,e>>1);
    return pwur * pwur % mod;
}
mt19937_64 rnd(time(0));
ll rng (ll a, ll b){
    return uniform_int_distribution<ll>(a,b)(rnd);
}
// Problem starts here -------------------------------------

int a[maxn][maxn], b[maxn][maxn];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.setf(ios::fixed); cout.precision(10);

    //freopen("a.in","r",stdin);
    //freopen("a.in","w",stdout);

    int tc;
    cin >> tc;
    while( tc-- ){
        int n, m;
        cin >> n >> m;

        for(int i=1; i<=n; i++){
            string s;
            cin >> s;
            for(int j=1; j<=m; j++){
                a[i][j] = ( s[j-1] - '0' );
            }
        }

        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                b[i][j] = a[i][j] + b[i-1][j];
            }
        }

        int ans = 1000000000;
        for(int i=1; i<=n; i++){
            for(int nj=5; i+nj-1<=n; nj++){
                int j = i + nj - 1;

                vector<int> c(m+1), d(m+1);
                for(int k=1; k<=m; k++){
                    c[k] = ( b[j-1][k] - b[i][k] ) + ( a[j][k] == 0 ) + ( a[i][k] == 0 );
                    d[k] = ( nj - 2 ) - ( b[j-1][k] - b[i][k] );
                }

                int oldc = d[1] + c[2] + c[3];
                for(int k=4; k<=m; k++){
                    ans = min( ans , oldc + d[k] );
                    oldc = min( oldc + c[k] , d[k-2] + c[k-1] + c[k] );
                }
            }
        }
        cout << ans << '\n';
    }

    return 0;
}