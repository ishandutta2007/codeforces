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
const int mod2 = 1000000007;
const int mod = 998244353;
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
// Problem starts here

ll dp[505][505], C[505][505], P[505][505];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.setf(ios::fixed); cout.precision(10);

    //freopen("a.in","r",stdin);
    //freopen("a.in","w",stdout);

    int N, X;
    cin >> N >> X;

    C[0][0] = 1;
    for(int i=1; i<=N; i++){
        for(int j=0; j<=i; j++){
            C[i][j] = C[i-1][j];
            if( j ){
                C[i][j] += C[i-1][j-1];
                C[i][j] %= mod;
            }
        }
    }

    for(int i=0; i<=X; i++)
        P[i][0] = 1;
    for(int i=0; i<=X; i++)
        for(int j=1; j<=max(N,X); j++)
            P[i][j] = ( P[i][j-1] * i ) % mod;

    dp[N][0] = 1;
    for(int d=0; d<=X; d++){
        for(int n=2; n<=N; n++){
            for(int c=0; c<=n; c++){
                dp[n-c][min(X,d+(n-1))] = ( dp[n-c][min(X,d+(n-1))] + dp[n][d] * C[n][c] % mod * P[min(X,d+(n-1))-d][c] ) % mod;
            }
        }
    }

    ll ans = 0;
    for(int i=0; i<=X; i++)
        ans = ( ans + dp[0][i] ) % mod;
    cout << ans << '\n';

    return 0;
}