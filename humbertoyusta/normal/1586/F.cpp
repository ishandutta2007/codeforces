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
const int maxn = 2010;
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

int col[maxn][maxn];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.setf(ios::fixed); cout.precision(10);

    //freopen("a.in","r",stdin);
    //freopen("a.in","w",stdout);

    int n, k;
    cin >> n >> k;

    int sz = 1;
    vector<int> comp;
    for(int i=1; i<=n; i++)
        comp.push_back(i);

    int tcol = 0;
    while( sz < n ){
        tcol ++;
        for(int i=1; i<=n; i+=sz*k){
            for(int j=i; j<min(n+1,i+sz*k); j+=sz){
                for(int l=j+sz; l<min(n+1,i+sz*k); l+=sz){
                    for(int pj=0; pj<sz; pj++){
                        for(int pl=0; pl<sz; pl++){
                            if( j + pj <= n && l + pl <= n )
                                col[j+pj][l+pl] = tcol;
                        }
                    }
                }
            }
        }
        sz *= k;
    }

    cout << tcol << '\n';
    for(int i=1; i<=n; i++)
        for(int j=i+1; j<=n; j++)
            cout << col[i][j] << ' ';
    cout << '\n';

    return 0;
}