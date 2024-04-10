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

int cnt[maxn];

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

        vector<int> a(n);
        for( auto &i : a ){
            cin >> i;
            cnt[i] ++;
        }
        sort(a.begin(),a.end());

        vector<pair<int,int>> ans;
        for(int i=n-1; i>0; i--){
            if( ans.size() == n / 2 )
                break;
            for(int j=0; j>=0; j--){
                if( cnt[ a[i] % a[j] ] == 0 ){
                    ans.push_back({a[i],a[j]});
                    if( ans.size() == n / 2 )
                        break;
                }
            }
        }

        for( auto i : ans )
            cout << i.f << ' ' << i.s << '\n';

        for( auto i : a )
            cnt[i] --;
    }

    return 0;
}