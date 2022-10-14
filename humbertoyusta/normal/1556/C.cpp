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



int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.setf(ios::fixed); cout.precision(10);

    //freopen("a.in","r",stdin);
    //freopen("a.in","w",stdout);

    int tc;
    tc = 1;
    //cin >> tc;
    while( tc-- ){
        int n;
        cin >> n;

        vector<ll> a(n);
        for(int i=0; i<n; i++){
            cin >> a[i];
        }

        ll ans = 0;
        for(int i=0; i<n; i+=2){
            ll mn = 0, sum = 0;
            for(int j=i+1; j<n; j+=2){
                if( j > i + 1 ){
                    sum -= a[j-2];
                    mn = min( mn , sum );
                    sum += a[j-1];
                    mn = min( mn , sum );
                }
                ll csum = sum - mn;
                if( csum <= 0 )
                    ans += max( 0ll , min( a[i] + csum , a[j] ) + ( i + 1 < j ) );
                else
                    ans += max( 0ll , min( a[i] + mn , a[j] - csum ) + ( i + 1 < j ) );
            }
        }

        cout << ans << '\n';
    }

    return 0;
}