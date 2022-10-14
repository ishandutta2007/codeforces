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

void add(ll u,vector<pair<ll, ll>> &a)
{
    ll v = 1;
    if (!a.empty() && a.back().f == u)
        v = a.back().s + 1;
    a.push_back(make_pair(u, v));
}

void reduce(vector<pair<ll, ll>> &a,int m)
{
    ll u = a.back().f * m;
    for (int i=0; i<m; i++)
        a.pop_back();
    add(u, a);
}

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
        int n, m;
        cin >> n >> m;

        vector<pair<ll, ll>> a, b;

        for (int i=0; i<n; i++)
        {
            ll u;
            cin >> u;
            ll v = 1;
            while (u % m == 0)
            {
                v *= m;
                u /= m;
            }
            if (!a.empty() && a.back().f == u)
            {
                a[a.size()-1].s += v;
            }
            else
            {
                a.push_back(make_pair(u, v));
            }
        }

        int n2;
        cin >> n2;
        for (int i=0; i<n2; i++)
        {
            ll u;
            cin >> u;
            ll v = 1;
            while (u % m == 0)
            {
                v *= m;
                u /= m;
            }
            if (!b.empty() && b.back().f == u)
            {
                b[b.size()-1].s += v;
            }
            else
            {
                b.push_back(make_pair(u, v));
            }
        }

        if (a == b) cout << "Yes\n";
            else cout << "No\n";
    }


    return 0;
}