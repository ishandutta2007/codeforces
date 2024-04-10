#include<bits/stdc++.h>
using namespace std;
// Pragma
#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline","03")
// Macros:
#define f first
#define s second
typedef long double ld;
typedef long long ll;
// debugging macros
#define db(x) cerr << #x << ": " << (x) << '\n';
#define db_v(x) cerr << #x << ": ["; for( auto i : (x) ) cerr << i << ", "; cerr << "]\n";
#define db_p(x) cerr << #x << ": " << (x).first << " " << (x).second << '\n';
// Constraints:
const int maxn = 400010;
const int mod = 1000000007;
const ll INF = 1ll * mod * mod;
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

vector<ll> fact, ifact;

ll comb(ll n,ll k)
{
    if (k > n || k < 0 || n < 0)
        return 0;
    return fact[n] * ifact[k] % mod * ifact[n-k] % mod;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.setf(ios::fixed); cout.precision(12);
    srand(time(0));

    //freopen("a.in","r",stdin);
    //freopen("a.in","w",stdout);

    fact.push_back(1);
    for (int i=1; i<maxn; i++)
    {
        fact.push_back(fact[i-1] * i % mod);
        ifact.push_back(qpow(fact[i-1], mod - 2));
    }


    int tc = 1;
    //cin >> tc;
    while (tc--)
    {
        int n;
        cin >> n;

        vector<ll> a(n+1);
        ll ans = 0;
        for (int i=0; i<=n; i++)
        {
            cin >> a[i];
            if (i)
            {
//                for (int j=0; j<a[i]; j++)
//                {
//                    ans = (ans + comb(i+j-1, i-1) * (mod - j)) % mod;
//                }

                ans = (ans - (comb(i+a[i]-1, i) - comb(i - 1, i) + mod) * a[i]) % mod;
//                for (int j=0; j<a[i]; j++)
//                {
//                    ans = (ans + comb(i+j, i) + mod) % mod;
//                }
                ans = (ans + comb(i+a[i], i+1)) % mod;

                ans = (ans + (comb(i+a[i]-1, i) - comb(i - 1, i) + mod) * a[i]) % mod;
            }
            else
            {
                ans = (ans + a[i]) % mod;
            }
        }
        cout << ans << '\n';
    }


    return 0;
}