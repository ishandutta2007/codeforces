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
const int maxn = 1000010;
const int mod = 1000000007;
const int mod2 = 998244353;
const ll INF = 1ll * mod * mod;
const double eps = 1e-9;
// Quick Functions------------------------------------------
ll qpow(ll b,int e){
    if( !e ) return 1;
    if( e & 1 ) return qpow(b,e-1) * b % mod;
    ll pwur = qpow(b,e>>1);
    return pwur * pwur % mod;
}
mt19937_64 rnd(time(0));
ll rng (ll a, ll b){
    return uniform_int_distribution<ll>(a,b)(rnd);
}
// Problem starts here

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.setf(ios::fixed); cout.precision(10);

    //freopen("a.in","r",stdin);
    //freopen("a.in","w",stdout);

    int tc;
    //tc = 1;
    cin >> tc;
    while( tc-- ){
        int n;
        cin >> n;

        ll sum = 0, ans = INF;
        vector<vector<int>> c(2*n,vector<int>(2*n));
        for(int i=0; i<2*n; i++)
            for(int j=0; j<2*n; j++){
                cin >> c[i][j];
                if( i >= n && j >= n ){
                    sum += c[i][j];
                }
            }

        for(int i=0; i<n; i+=n-1+(n==1)){
            for(int j=0; j<n; j+=n-1+(n==1)){

                ll lft = 0;
                for(int k=0; k<i; k++){
                    lft += c[k][n+j];
                }

                ll rit = 0;
                for(int k=i+1; k<n; k++)
                    rit += c[k][n+j];

                ll up = 0;
                for(int k=0; k<j; k++){
                    up += c[i][n+k];
                }

                ll down = 0;
                for(int k=j+1; k<n; k++){
                    down += c[i][n+k];
                }

                ans = min( ans , sum + min( lft , rit ) + min( up , down ) + c[i][n+j] );
            }
        }

        for(int i=0; i<n; i+=n-1+(n==1)){
            for(int j=0; j<n; j+=n-1+(n==1)){

                ll lft = 0;
                for(int k=0; k<i; k++){
                    lft += c[n+k][j];
                }

                ll rit = 0;
                for(int k=i+1; k<n; k++)
                    rit += c[n+k][j];

                ll up = 0;
                for(int k=0; k<j; k++){
                    up += c[n+i][k];
                }

                ll down = 0;
                for(int k=j+1; k<n; k++){
                    down += c[n+i][k];
                }

                ans = min( ans , sum + min( lft , rit ) + min( up , down ) + c[n+i][j] );
            }
        }

        cout << ans << '\n';
    }

    return 0;
}