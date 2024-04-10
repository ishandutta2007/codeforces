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

        string s, t;
        cin >> s >> t;

        vector<pair<int, int>> a, b;
        for (int i=0; i<n; i++)
        {
            if (s[i] == 'a')
                a.push_back({0, i});
            if (s[i] == 'c')
                a.push_back({1, i});

            if (t[i] == 'a')
                b.push_back({0, i});
            if (t[i] == 'c')
                b.push_back({1, i});
        }

        if (a.size() != b.size())
        {
            cout << "NO\n";
            continue;
        }

        bool possible = true;
        for (int i=0; i<a.size(); i++)
        {
            if (a[i].f != b[i].f)
                possible = false;

            if (a[i].f == 0 && b[i].f == 0)
            {
                if (a[i].s > b[i].s)
                    possible = false;
            }

            if (a[i].f == 1 && b[i].f == 1)
            {
                if (a[i].s < b[i].s)
                    possible = false;
            }
        }

        cout << (possible ? "YES" : "NO") << '\n';
    }


    return 0;
}