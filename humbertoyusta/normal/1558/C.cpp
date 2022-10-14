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
const int maxn = 2050;
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
        bool can = 1;
        for(int i=0; i<n; i++){
            cin >> a[i];
            if( ( i & 1 ) && ( a[i] & 1 ) ) can = 0;
            if( ( i & 1 ) == 0 && ( a[i] & 1 ) == 0 ) can = 0;
        }

        if( !can ){
            cout << -1 << '\n';
            continue;
        }

        vector<int> ans;
        for(int i=n; i>1; i-=2){
            for(int j=0; j<n; j+=2)
                if( a[j] == i ){
                    ans.push_back(j+1);
                    reverse(a.begin(),a.begin()+j+1);
                    break;
                }
            for(int j=1; j<n; j+=2)
                if( a[j] == i - 1 ){
                    ans.push_back(j);
                    reverse(a.begin(),a.begin()+j);
                    ans.push_back(j+2);
                    reverse(a.begin(),a.begin()+j+2);
                    break;
                }
            ans.push_back(3);
            reverse(a.begin(),a.begin()+3);
            ans.push_back(i);
            reverse(a.begin(),a.begin()+i);
        }
        //db_v(a)

        cout << ans.size() << '\n';
        for( auto i : ans )
            cout << i << ' ';
        cout << '\n';
    }

    return 0;
}