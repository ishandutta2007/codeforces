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
const int maxn = 110;
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

int p, m, dp[maxn][maxn][maxn], fact[maxn], C[maxn][maxn];

int DP(int sz,int see,int good){

    if( good && m - see > sz ) return 0;

    if( dp[sz][see][good] != -1 )
        return dp[sz][see][good];

    int ans = 0;
    for(int lsz=0; lsz<sz; lsz++){
        int rsz = sz - 1 - lsz;
        if( lsz > rsz ) break;
        int tgood = ( see + 1 == m );
        if( good - tgood < 0 ) continue;
        for(int lg=0; lg<=min(good-tgood,lsz); lg++){
            ans = ( ans + 1ll * DP(lsz,see+1,lg) * DP(rsz,see+1,good - tgood - lg) % p * C[lsz+rsz][lsz] ) % p;
            if( lsz != rsz )
                ans = ( ans + 1ll * DP(lsz,see+1,lg) * DP(rsz,see+1,good - tgood - lg) % p * C[lsz+rsz][lsz] ) % p;
        }
    }

    return dp[sz][see][good] = ans;
}

int main(){

    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.setf(ios::fixed); cout.precision(10);

    //freopen("a.in","r",stdin);
    //freopen("a.in","w",stdout);

    int n, k;
    cin >> n >> m >> k >> p;

    fact[0] = 1;
    for(int i=1; i<=n; i++)
        fact[i] = 1ll * fact[i-1] * i % p;

    for(int i=0; i<=n; i++)
        C[i][0] = 1;
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++)
            C[i][j] = ( C[i-1][j] + C[i-1][j-1] ) % p;

    for(int i=0; i<=n; i++)
        for(int j=0; j<=n; j++)
            for(int k=0; k<=n; k++){
                dp[i][j][k] = -1;
                if( k > i )
                    dp[i][j][k] = 0;
            }

    for(int i=0; i<=n; i++)
        for(int j=m; j<=n; j++)
            for(int k=0; k<=m; k++)
                dp[i][j][k] = fact[i] * ( k == 0 );


    for(int i=0; i<=n; i++)
        for(int j=0; j<=n; j++)
            dp[0][i][j] = ( j == 0 );

    cout << DP(n,0,k) << '\n';

    return 0;
}