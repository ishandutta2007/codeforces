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
const int mod = 1000000007;
const int mod2 = 998244353;
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

ll INF = 1ll * mod * mod;
ll safe_sum(ll a,ll b){
    return min( a + b , INF );
}
ll safe_mul(ll a,ll b){
    if( a == 0 || b == 0 )
        return 0;
    if( a >= INF || b >= INF )
        return INF;
    if( a >= ( INF + b - 1 ) / b )
        return INF;
    return a * b;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.setf(ios::fixed); cout.precision(10);

    //freopen("a.in","r",stdin);
    //freopen("a.in","w",stdout);

    int tc;
    cin >> tc;
    while( tc-- ){
        ll n, k, x;
        cin >> n >> k >> x;
        x --;

        vector<ll> pot(n+1);
        pot[0] = 1;
        for(int i=1; i<=n; i++)
            pot[i] = safe_mul( pot[i-1] , k );

        string s;
        cin >> s;

        int cnt = 0;
        for( auto i : s )
            cnt += ( i == '*' );

        string t;
        for(int i=0; i<n; ){
            if( s[i] == 'a' ){
                t += 'a';
                i ++;
                continue;
            }
            else{
                int c = 0;
                int p = i;
                while( s[p] == '*' ){
                    p ++;
                    c ++;
                    cnt --;
                }

                ll rt = 1;
                for( ; p<n; ){
                    if( s[p] == 'a' ){
                        p++;
                        continue;
                    }
                    else{
                        int cc = 0;
                        while( s[p] == '*' ){
                            cc ++;
                            p ++;
                        }
                        rt = safe_mul( rt , k * cc + 1 );
                    }
                }

                for(int j=0; j<k*c; j++){
                    if( x >= rt ){
                        x -= rt;
                        t += 'b';
                    }
                }

                i += c;
                continue;
            }
        }

        cout << t << '\n';
    }

    return 0;
}