#include<bits/stdc++.h>
using namespace std;
// Pragma
#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline","03")
// Macros:
#define f first
#define s second
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
// debugging macros
#define db(x) cerr << #x << ": " << (x) << '\n';
#define db_v(x) cerr << #x << ": ["; for( auto i : (x) ) cerr << i << ", "; cerr << "]\n";
#define db_p(x) cerr << #x << ": " << (x).first << " " << (x).second << '\n';
// Constraints:
const int maxn = 100010;
const int mod2 = 1000000007;
const int mod = 998244353;
const ll INF = 1ll * mod * mod;
const double eps = 1e-9;
// Quick Functions------------------------------------------
ll qpow(ll b,int e){
    if( !e ) return 1;
    if( e & 1 ) return 1ll * qpow(b,e-1) * b % mod;
    ll pwur = qpow(b,e>>1);
    return 1ll * pwur * pwur % mod;
}
// Problem starts here


int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.setf(ios::fixed); cout.precision(12);
    srand(time(0));

    //freopen("a.in","r",stdin);
    //freopen("a.in","w",stdout);

    int tc;
    cin >> tc;
    while (tc--)
    {
        int n;
        cin >> n;

        vector<int> a(n);
        for (auto &i : a)
        {
            cin >> i;
        }

        sort(a.begin(), a.end());

        int x = a[0] + a[0] - 1;

        int ans = 0;
        for (auto i : a)
        {
            ans += (i + x - 1) / x - 1;
        }
        cout << ans << '\n';
    }

    return 0;
}