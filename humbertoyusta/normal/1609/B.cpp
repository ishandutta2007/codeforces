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

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.setf(ios::fixed); cout.precision(10);

    //freopen("a.in","r",stdin);
    //freopen("a.in","w",stdout);

    int tc;
    tc = 1;//cin >> tc;
    while( tc-- ){
        int n, q;
        cin >> n >> q;
        string s;
        cin >> s;
        s = "$$" + s + "$$";

        int ans = 0;
        for(int i=2; i<=n+2; i++)
            ans += ( s[i] == 'a' && s[i+1] == 'b' && s[i+2] == 'c' );

        for(int t=1; t<=q; t++){
            int x;
            cin >> x;
            char c;
            cin >> c;
            for(int i=x-1; i<=x+1; i++){
                ans -= ( s[i] == 'a' && s[i+1] == 'b' && s[i+2] == 'c' );
            }
            s[x+1] = c;

            for(int i=x-1; i<=x+1; i++){
                ans += ( s[i] == 'a' && s[i+1] == 'b' && s[i+2] == 'c' );
            }
            cout << ans << '\n';
        }
    }

    return 0;
}