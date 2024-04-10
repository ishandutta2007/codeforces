/// Code by humbertoyusta
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
const int maxn = 1010;
const int mod = 1000000007;
const int mod2 = 998244353;
const double eps = 1e-9;
// Quick Functions------------------------------------------
int qpow(int b,int e){
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

        string s[2];
        cin >> s[0] >> s[1];

        s[0] = '&' + s[0];
        s[1] = '&' + s[1];

        int l0 = -1, l1 = -1;
        vector<int> dp(n+1);

        for(int i=1; i<=n; i++){
            dp[i] = dp[i-1];
            if( s[0][i] == '0' || s[1][i] == '0' ) l0 = i;
            if( s[0][i] == '1' || s[1][i] == '1' ) l1 = i;

            if( l0 != -1 )
                dp[i] = max( dp[i] , dp[l0-1] + 1 );

            if( l0 != -1 && l1 != -1 )
                dp[i] = max( dp[i] , dp[min(l0,l1)-1] + 2 );
        }

        cout << dp[n] << '\n';
    }

    return 0;
}