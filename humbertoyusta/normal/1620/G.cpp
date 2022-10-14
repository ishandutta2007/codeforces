#include<bits/stdc++.h>
using namespace std;
// Pragma
#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline","03")
// Macros:
#define f first
#define s second
typedef long long ll;
typedef long double ld;
// debugging macros
#define db(x) cerr << #x << ": " << (x) << '\n';
#define db_v(x) cerr << #x << ": ["; for( auto i : (x) ) cerr << i << ", "; cerr << "]\n";
#define db_p(x) cerr << #x << ": " << (x).first << " " << (x).second << '\n';
// Constraints:
const int maxn = 55050;
const int mod2 = 1000000007;
const int mod = 998244353;
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

int cnt[25][26];
int mn[26][1<<23];
int A[1<<23], F[1<<23];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.setf(ios::fixed); cout.precision(10);

    //freopen("a.in","r",stdin);
    //freopen("a.in","w",stdout);

    int n;
    cin >> n;

    for(int i=0; i<n; i++){
        string s;
        cin >> s;
        for( auto j : s )
            cnt[i][int(j-'a')] ++;
    }

    for(int i=0; i<26; i++){
        for(int msk=0; msk<(1<<n); msk++){
            int lsb = ( msk & -msk );
            if( msk == lsb ){
                for(int j=0; j<n; j++){
                    if( (1<<j) == lsb )
                        mn[i][msk] = cnt[j][i];
                }
            }
            else{
                mn[i][msk] = min( mn[i][msk^lsb] , mn[i][lsb] );
            }
        }
    }

    for(int msk=0; msk<(1<<n); msk++){
        A[msk] = 1;
        for(int i=0; i<26; i++){
            A[msk] = ( 1ll * A[msk] * ( mn[i][msk] + 1 ) ) % mod;
        }
        A[msk] = ( A[msk] - 1 + mod ) % mod;

        if( __builtin_popcount(msk) % 2 == 0 ){
            A[msk] = ( mod - A[msk] ) % mod;
        }
    }

    for(int i = 0; i<(1<<n); ++i)
        F[i] = A[i];
    for(int i = 0;i < n; ++i)
        for(int mask = 0; mask < (1<<n); ++mask){
            if(mask & (1<<i)){
                F[mask] += F[mask^(1<<i)];
                if( F[mask] >= mod )
                    F[mask] -= mod;
            }
        }

    ll ans = 0;
    for(int i=0; i<(1<<n); i++){
        int sz = 0, sum = 0;//db(F[i])
        for(int j=0; j<n; j++){
            if( i & (1<<j) ){
                sum += j + 1;
                sz ++;
            }
        }
        ll res = 1ll * ( F[i] + 1 ) % mod * sz * sum;
        ans = ( ans ^ res );
    }
    cout << ans << '\n';

    return 0;
}