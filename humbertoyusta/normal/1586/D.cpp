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

int query(vector<int>& v){
    cout << "? ";
    for(auto i : v)
        cout << i << ' ';
    cout << '\n';
    cout.flush();
    int ret;
    cin >> ret;
    return ret;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.setf(ios::fixed); cout.precision(10);

    //freopen("a.in","r",stdin);
    //freopen("a.in","w",stdout);

    int n;
    cin >> n;

    vector<int> nxt(n+1);
    vector<int> prv(n+1);

    for(int i=0; i<n; i++){
        vector<int> v(n,1);
        v[i] = 2;
        int k = query(v);
        if( k != i + 1 )
            nxt[i+1] = k;

        for(int j=0; j<n; j++){
            if( v[j] == 1 ) v[j] = 2;
                else v[j] = 1;
        }
        k = query(v);
        if( k != i + 1 )
            prv[i+1] = k;
    }

    for(int i=1; i<=n; i++){
        if( prv[i] != 0 ) nxt[prv[i]] = i;
        if( nxt[i] != 0 ) prv[nxt[i]] = i;
    }

    vector<int> ans(n+1);
    for(int i=1; i<=n; i++){
        if( prv[i] == 0 )
            ans[i] = 1;
    }

    for(int i=1; i<n; i++){
        for(int j=1; j<=n; j++){
            if( ans[j] == i )
                ans[nxt[j]] = ans[j] + 1;
        }
    }

    cout << "! ";
    for(int i=1; i<=n; i++)
        cout << ans[i] << " \n"[i==n];
    cout.flush();

    return 0;
}