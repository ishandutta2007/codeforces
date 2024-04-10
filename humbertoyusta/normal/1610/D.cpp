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
const int maxn = 200010;
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

ll fact[maxn], ifact[maxn];

ll comb(int n,int k){
    return fact[n] * ifact[k] % mod * ifact[n-k] % mod;
}

ll solve(vector<int> a){

    if( a.empty() )
        return 0;

    vector<int> cnt(4);
    for( auto i : a )
        cnt[i%4] ++;

    ll ans = ( qpow(2,cnt[1]+cnt[3]) + mod - 1 ) * qpow(2,cnt[0]+cnt[2]) % mod;

    for(int i=2; i<=cnt[2]; i+=2)
        ans = ( ans + qpow(2,cnt[0]) * comb(cnt[2],i) ) % mod;

    vector<int> b;
    for(int i=0; i<a.size(); i++)
        if( a[i] % 4 == 0 )
            b.push_back(a[i]/2);

    return ( ans + solve(b) ) % mod;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.setf(ios::fixed); cout.precision(10);

    fact[0] = 1;
    for(int i=1; i<maxn; i++)
        fact[i] = fact[i-1] * i % mod;

    ifact[maxn-1] = qpow(fact[maxn-1],mod-2);
    for(int i=maxn-2; i>=0; i--)
        ifact[i] = ifact[i+1] * ( i + 1 ) % mod;

    //freopen("a.in","r",stdin);
    //freopen("a.in","w",stdout);

    int n;
    cin >> n;

    vector<int> cnt(4);

    vector<int> a(n);
    for( auto &i : a )
        cin >> i;

    cout << solve(a) << '\n';

    return 0;
}