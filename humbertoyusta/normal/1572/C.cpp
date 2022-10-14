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
const int maxn = 3030;
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

int dp[maxn][maxn][2], a[maxn];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.setf(ios::fixed); cout.precision(10);

    //freopen("a.in","r",stdin);
    //freopen("a.in","w",stdout);

    int tc;
    cin >> tc;
    while( tc-- ){

        int n;
        cin >> n;

        vector<int> occ[n+1];
        for(int i=1; i<=n; i++){
            cin >> a[i];
            occ[a[i]].push_back(i);
        }

        for(int i=0; i<=n+1; i++)
            for(int j=0; j<=n+1; j++)
                dp[i][j][0] = dp[i][j][1] = mod;

        for(int i=1; i<=n; i++)
            dp[i][i][0] = dp[i][i][1] = 0;

        for(int sz=2; sz<=n; sz++){
            for(int i=1; i+sz-1<=n; i++){
                int j = i + sz - 1;

                dp[i][j][0] = min( dp[i][j][0] , dp[i][j-1][0] + 1 - ( a[i] == a[j] ) );
                dp[i][j][0] = min( dp[i][j][0] , dp[i+1][j][1] + 1 - ( a[i] == a[j] ) );

                dp[i][j][1] = min( dp[i][j][1] , dp[i][j-1][0] + 1 - ( a[i] == a[j] ) );
                dp[i][j][1] = min( dp[i][j][1] , dp[i+1][j][1] + 1 - ( a[i] == a[j] ) );

                for(auto k : occ[a[i]]){
                    if( k > i && k <= j ){
                        dp[i][j][0] = min( dp[i][j][0] , dp[i][k-1][0] + dp[k][j][0] );
                    }
                }
                for( auto k : occ[a[j]] ){
                    if( k >= i && k < j ){
                        dp[i][j][1] = min( dp[i][j][1] , dp[i][k][1] + dp[k+1][j][1] );
                    }
                }
//                for( auto k : occ[a[j]] ){
//                    if( k >= i && k <= j - 1 ){
//                        //dp[i][j][0] = min( dp[i][j][0] , dp[i][k][0] + dp[k+1][j][0] + 1 - ( a[k+1] == a[i] ) );
//                        dp[i][j][0] = min( dp[i][j][0] , dp[i][k][0] + dp[k+1][j][1] + 1 - ( a[j] == a[i] ) );
//
//                        dp[i][j][1] = min( dp[i][j][1] , dp[i][k][0] + dp[k+1][j][1] + 1 - ( a[j] == a[i] ) );
//                        dp[i][j][1] = min( dp[i][j][1] , dp[i][k][1] + dp[k+1][j][1] + 1 - ( a[j] == a[k] ) );
//                    }
//                    if( k >= i + 1 && k <= j ){
//                        //dp[i][j][0] = min( dp[i][j][0] , dp[i][k-1][0] + dp[k][j][0] + 1 - ( a[k] == a[i] ) );
//                        dp[i][j][0] = min( dp[i][j][0] , dp[i][k-1][0] + dp[k][j][1] + 1 - ( a[j] == a[i] ) );
//
//                        dp[i][j][1] = min( dp[i][j][1] , dp[i][k-1][0] + dp[k][j][1] + 1 - ( a[j] == a[i] ) );
//                        dp[i][j][1] = min( dp[i][j][1] , dp[i][k-1][1] + dp[k][j][1] + 1 - ( a[k-1] == a[j] ) );
//                    }
//                }
                ///
//                for(int k=i; k<=j-1; k++){
//                    dp[i][j][0] = min( dp[i][j][0] , dp[i][k][0] + dp[k+1][j][0] + 1 - ( a[k+1] == a[i] ) );
//                    dp[i][j][0] = min( dp[i][j][0] , dp[i][k][0] + dp[k+1][j][1] + 1 - ( a[j] == a[i] ) );
//
//                    dp[i][j][1] = min( dp[i][j][1] , dp[i][k][0] + dp[k+1][j][1] + 1 - ( a[j] == a[i] ) );
//                    dp[i][j][1] = min( dp[i][j][1] , dp[i][k][1] + dp[k+1][j][1] + 1 - ( a[j] == a[k] ) );
//                }
//                for(int k=i+1; k<=j; k++){
//                    dp[i][j][0] = min( dp[i][j][0] , dp[i][k-1][0] + dp[k][j][0] + 1 - ( a[k] == a[i] ) );
//                    dp[i][j][0] = min( dp[i][j][0] , dp[i][k-1][0] + dp[k][j][1] + 1 - ( a[j] == a[i] ) );
//
//                    dp[i][j][1] = min( dp[i][j][1] , dp[i][k-1][0] + dp[k][j][1] + 1 - ( a[j] == a[i] ) );
//                    dp[i][j][1] = min( dp[i][j][1] , dp[i][k-1][1] + dp[k][j][1] + 1 - ( a[k-1] == a[j] ) );
//                }
                //db(i)db(j)db(dp[i][j][0])db(dp[i][j][1])
            }
        }

        cout << min( dp[1][n][0] , dp[1][n][1] ) << '\n';
    }

    return 0;
}