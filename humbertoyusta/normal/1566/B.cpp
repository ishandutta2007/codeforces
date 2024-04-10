/// Code by humbertoyusta
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
const int maxn = 1010;
const int mod = 1000000007;
const int mod2 = 998244353;
const double eps = 1e-9;
// Quick Functions------------------------------------------
int qpow(int b,int e){
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
    cin >> tc;
    while( tc-- ){
        string s;
        cin >> s;
        int cnt(0), l(mod), r(0);
        for(int i=0; i<s.size(); i++){
            if( s[i] == '0' ){
                l = min( l , i );
                r = max( r , i );
                cnt ++;
            }
        }
        if( cnt == 0 ){
            cout << 0 << '\n';
            continue;
        }
        if( r - l + 1 == cnt ){
            cout << 1 << '\n';
            continue;
        }
        cout << 2 << '\n';
    }

    return 0;
}