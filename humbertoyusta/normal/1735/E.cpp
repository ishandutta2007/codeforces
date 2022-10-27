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
const int zero = 1000000000;
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

int find_(int x, vector<int> &p)
{
    return (p[x] == x) ? x : p[x] = find_(p[x], p);
}

bool join(int u,int v, vector<int> &p)
{
    u = find_(u, p);
    v = find_(v, p);
    if (u == v)
        return false;
    p[v] = u;
    return true;
}

ll hash_(const vector<int> &v)
{
    ll h_ = 0;
    for (auto i : v)
        h_ = h_ * 3 + i;
    return h_;
}

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

        vector<ll> d1(n);
        for (auto &i : d1)
            cin >> i;

        vector<ll> d2(n);
        for (auto &i : d2)
            cin >> i;

        sort(d1.begin(), d1.end());
        sort(d2.begin(), d2.end());
        reverse(d2.begin(), d2.end());

        set<ll> xs;
        for (int i=0; i<n; i++)
        {
            xs.insert(d1[0] + d2[i]);
            xs.insert(abs(d1[0] - d2[i]));
        }

        bool done = false;
        for (auto x : xs)
        {
            multiset<pair<pair<ll, ll>, ll>> a;
            multiset<pair<ll, ll>> b;
            for (int i=0; i<n; i++)
            {
                a.insert({{-(x + d1[i]), -abs(x - d1[i])}, d1[i]});
            }

            bool good = true;
            vector<ll> pos(n);

            for (int i=0; i<n; i++)
            {
                while (!a.empty() && -(*a.begin()).f.f > d2[i])
                {
                    auto bg = a.begin();
                    b.insert({(*bg).f.s, (*bg).s});
                    a.erase(bg);
                }

                while (!b.empty() && -(*b.begin()).f > d2[i])
                    b.erase(b.begin());

                if (!b.empty() && -(*b.begin()).f == d2[i])
                {
                    pos[i] = zero + (*b.begin()).s;
                    b.erase(b.begin());
                    continue;
                }

                if (!a.empty() && -(*a.begin()).f.f == d2[i])
                {
                    pos[i] = zero - (*a.begin()).s;
                    a.erase(a.begin());
                    continue;
                }

                good = false;
                break;
            }

            if (good)
            {
                cout << "YES\n";
                ll mn = zero;
                for (auto i : pos)
                    mn = min(mn, i);

                for (auto i : pos)
                    cout << i - mn << ' ';
                cout << '\n';
                cout << zero - mn << ' ' << zero + x - mn << '\n';
                done = true;
                break;
            }
        }

        if (!done)
            cout << "NO\n";
    }

    return 0;
}