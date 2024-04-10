#include<bits/stdc++.h>
using namespace std;
// Pragma
#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline","03")
// Macros:
#define f first
#define s second
typedef long double ld;
typedef long long ll;
// debugging macros
#define db(x) cerr << #x << ": " << (x) << '\n';
#define db_v(x) cerr << #x << ": ["; for( auto i : (x) ) cerr << i << ", "; cerr << "]\n";
#define db_p(x) cerr << #x << ": " << (x).first << " " << (x).second << '\n';
// Constraints:
const int maxn = 1000010;
const int mod = 1000000007;
const ll INF = 1ll * mod * mod;
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
// Problem starts here


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.setf(ios::fixed); cout.precision(12);
    srand(time(0));

    //freopen("a.in","r",stdin);
    //freopen("a.in","w",stdout);

    int tc = 1;
    cin >> tc;
    while (tc--)
    {
        int n;
        cin >> n;

        vector<int> a(n);
        for (int i=0; i<n; i++)
        {
            cin >> a[i];
            a[i] --;
        }

        int lst = a[0];
        int mx = max(a[0], a[1]);
        int mn = min(a[0], a[1]);
        int ans = 1;
        for (int i=2; i<n; i++)
        {
            if (mx > lst)
            {
                if (a[i] < lst)
                {
                    ans ++;
                    lst = mx;
                    mx = mx;
                    mn = a[i];
                }
                else
                    mx = max(mx, a[i]);
            }
            if (mn < lst)
            {
                if (a[i] > lst)
                {
                    ans ++;
                    lst = mn;
                    mn = mn;
                    mx = a[i];
                }
                else
                    mn = min(mn, a[i]);
            }
        }

        vector<int> id(n);
        for (int i=0; i<n; i++)
        {
            id[a[i]] = i;
        }

        vector<int> smin(n), smax(n);
        smin[n-1] = smax[n-1] = a[n-1];
        for (int i=n-2; i>=0; i--)
        {
            smin[i] = min(smin[i+1], a[i]);
            smax[i] = max(smax[i+1], a[i]);
        }

        while(lst != a[n-1])
        {
            if (lst == smin[id[lst]])
            {
                ans ++;
                lst = smax[id[lst]];
            }
            else
            if (lst == smax[id[lst]])
            {
                ans ++;
                lst = smin[id[lst]];
            }
        }

        cout << ans - 1 << '\n';
    }


    return 0;
}