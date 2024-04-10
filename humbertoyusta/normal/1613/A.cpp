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

long long number(string a){
    ll res = 0;
    ll pot = 1;
    for(int i=(int)a.size()-1; i>=0; i--){
        res += pot * ( a[i] - '0' );
        pot *= 10;
    }
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
        string a, b;
        int n, m;
        cin >> a >> n;
        cin >> b >> m;

        if( a.size() + n < b.size() + m ){
            cout << "<\n";
            continue;
        }

        if( a.size() + n > b.size() + m ){
            cout << ">\n";
            continue;
        }

        while( n > m ){
            a += '0';
            n --;
        }

        while( m > n ){
            b += '0';
            m --;
        }

        long long x = number(a);
        long long y = number(b);

        if( x < y ){
            cout << "<\n";
            continue;
        }

        if( x > y ){
            cout << ">\n";
            continue;
        }

        if( x == y ){
            cout << "=\n";
            continue;
        }
    }

    return 0;
}