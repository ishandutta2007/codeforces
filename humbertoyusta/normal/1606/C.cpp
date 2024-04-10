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
    if( e & 1 ) return qpow(b,e-1) * b;
    ll pwur = qpow(b,e>>1);
    return pwur * pwur;
}
mt19937_64 rnd(time(0));
ll rng (ll a, ll b){
    return uniform_int_distribution<ll>(a,b)(rnd);
}
// Problem starts here

void print(ll front_,ll nines_back){
    if( front_ )
        cout << front_;
    for(int i=0; i<nines_back; i++)
        cout << 9;
    cout << '\n';
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.setf(ios::fixed); cout.precision(10);

    //freopen("a.in","r",stdin);
    //freopen("a.in","w",stdout);

    int tc;
    cin >> tc;
    // tc = 1;
    while( tc-- ){
        ll n, k;
        cin >> n >> k;
        k ++;

        vector<ll> a(n);
        for(int i=0; i<n; i++)
            cin >> a[i];

        int nright(0), bad(0);
        for(int i=0; i<n-1; i++){
            if( qpow(10,a[i+1]-a[i]) - 1 > k ){
                print(k,nright);
                bad = 1;
                break;
            }
            else{
                k -= qpow(10,a[i+1]-a[i]) - 1;
                nright += a[i+1] - a[i];
            }
        }
        if( !bad )
            print(k,nright);
    }

    return 0;
}