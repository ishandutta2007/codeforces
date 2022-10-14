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

int cnt = 0;

ll query(int l,int r){
    cnt ++;
    if( cnt > 40 )
        return 1 / 0;
    cout << "? " << l << ' ' << r << '\n';
    cout.flush();
    ll ret;
    cin >> ret;
    return ret;
}

ll sqrtsum(ll x){
    x = 2ll * x;
    ll a = sqrt(1ll+4ll*x);
    ll c = -1;
    for(ll b=a-4; b<=a+4; b++){
        if( b * b == 1ll+4ll*x )
            c = b;
    }
    if( c == -1 )
        return -1;
    if( c % 2 == 1 )
        return ( 1ll + c ) / 2ll - 1ll;
    else
        return -1;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.setf(ios::fixed); cout.precision(10);

    //freopen("a.in","r",stdin);
    //freopen("a.in","w",stdout);

    int tc;
    cin >> tc;
    while( tc-- ){
        ll n;
        cnt = 0;

        cin >> n;

        ll all = query(1,n);

        ll l = n, r = n;
        ll prv = 0;
        for(int i=30; i>=0; i--){
            if( l - (1ll<<i) >= 1 ){
                ll x = query(l-(1ll<<i),r);
                if( sqrtsum(x) != -1 && x < all ){
                    if( prv == 0 ){
                        if( x == 0 ){
                            l -= (1ll<<i);
                            prv = x;
                            continue;
                        }
                        if( query(l-(1ll<<i)+sqrtsum(x),r) == 0 ){
                            l -= (1ll<<i);
                            prv = x;
                        }
                    }
                    else{
                        if( sqrtsum(x) - sqrtsum(prv) == (1ll<<i) ){
                            l -= (1ll<<i);
                            prv = x;
                        }
                    }
                }
            }
        }


        ll f = all - prv;
        ll s = all - f;
        f = sqrtsum(f);
        s = sqrtsum(s);
        cout << "! " << l - f - 1 << ' ' << l << ' ' << l + s << '\n';
        cout.flush();
    }

    return 0;
}