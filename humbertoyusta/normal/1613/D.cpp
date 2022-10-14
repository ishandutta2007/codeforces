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

int abi[maxn];

void update(int id,int val){
    for( ; id > 0 ; id -= ( id & -id ) )
        abi[id] += val;
}

int query(int id){
    int res = 0;
    for( ; id < maxn ; id += ( id & -id ) )
        res += abi[id];
    return res;
}

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

        vector<ll> a(n+1);
        vector<ll> cnt(n+10);
        for(int i=1; i<=n; i++){
            cin >> a[i];
            cnt[a[i]] ++;
        }

        vector<ll> pot(n+10);
        pot[0] = 1;
        for(int i=0; i<=n; i++)
            pot[i+1] = pot[i] * 2 % mod;

        vector<ll> dp(n+10), ed(n+10);
        dp[0] = 1;
        //ed[0] = 1;
        ll ans = 0;// ( pot[cnt[1]] + mod - 1 ) % mod;
        for(int i=1; i<=n; i++){

            cnt[a[i]] --;

            ll sum = ( dp[a[i]] + dp[a[i]+1] ) % mod;

            ll asum = ed[a[i]+1];
            if( a[i] ){
                asum = ( asum + dp[a[i]-1] + ed[a[i]-1] ) % mod;
            }

            if( a[i] )
                ed[a[i]-1] = ( ed[a[i]-1] + dp[a[i]-1] + ed[a[i]-1] ) % mod;

            ed[a[i]+1] = ( ed[a[i]+1] + ed[a[i]+1] ) % mod;

            ans = ( ans + sum + asum ) % mod;

            dp[a[i]+1] += sum;
            dp[a[i]+1] %= mod;
        }

        cout << ans << '\n';
    }

    return 0;
}