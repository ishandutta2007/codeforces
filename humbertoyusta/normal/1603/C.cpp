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
const int maxn = 100010;
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

int cnt[maxn], mk[maxn];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.setf(ios::fixed); cout.precision(10);

    //freopen("a.in","r",stdin);
    //freopen("a.in","w",stdout);

    int tc;
    cin >> tc;
    // tc = 1;
    while( tc-- ){
        int n;
        cin >> n;
        vector<int> a(n);
        for(int i=0; i<n; i++)
            cin >> a[i];

        ll ans = 0;
        vector<pair<int,int>> dp;
        dp.push_back({a[n-1],1});

        for(int i=n-2; i>=0; i--){
            vector<int> v;
            for( auto j : dp ){

                int p = j.f;
                if( p > a[i] )
                    p = a[i];

                int k = p;
                if( a[i] % p ){

//                    for(int l=18; l>=0; l--)
//                        if( (1<<l) < k && a[i] / ( k - (1<<l) ) < ( a[i] + p - 1 ) / p )
//                            k -= (1<<l);
//
//                    if( a[i] / k < ( a[i] + p - 1 ) / p )
//                        k --;

                    k = a[i] / (( a[i] + p - 1 ) / p);

                }//db(p)db(k)


                ans = ( ans + 1ll * (  ( a[i] + p - 1 ) / p - 1 ) * j.s % mod * (i+1) ) % mod;//db(ans)
                cnt[k] += j.s;
                mk[k] = 1;
                v.push_back(k);
            }

            dp.clear();

            cnt[a[i]] ++;
            mk[a[i]] = 1;
            v.push_back(a[i]);

            for( auto j : v ){
                if( mk[j] ){
                    dp.push_back({j,cnt[j]});
                    cnt[j] = 0;
                    mk[j] = 0;
                }
            }
        }

        cout << ans << '\n';
    }

    return 0;
}