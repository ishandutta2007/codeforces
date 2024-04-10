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

bool f(int k,vector<pair<int,int>> &a){
    int n = a.size();
    int cnt = 0;
    for(int i=0; i<n; i++){
        if( cnt < k && ( a[i].s >= cnt && a[i].f >= k - cnt - 1 ) )
            cnt ++;
    }
    return ( cnt == k );
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

        vector<pair<int,int>> a(n);
        for( auto &i : a )
            cin >> i.f >> i.s;

        int l = 1, r = n;
        while( l < r ){
            int mi = ( l + r ) >> 1;
            if( f(mi,a) )
                l = mi + 1;
            else
                r = mi;
        }
        if( !f(l,a) ) l --;
        if( f(l+1,a) ) l ++;

        cout << l << '\n';
    }

    return 0;
}