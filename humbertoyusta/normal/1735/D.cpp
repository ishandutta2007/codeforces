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
    tc = 1;//cin >> tc;
    while (tc--)
    {
        int n, k;

        cin >> n >> k;

        vector<vector<int>> a(n, vector<int> (k));

        set<ll> st;
        for (int i=0; i<n; i++)
        {
            for (int j=0; j<k; j++)
                cin >> a[i][j];
            st.insert(hash_(a[i]));
        }

         ll ans = 0;
        for (int i=0; i<n; i++)
        {
            int cnt = 0;
            for (int j=0; j<n; j++)
            {
                if (i == j)
                    continue;

                bool good = true;
                vector<int> v(k);
                for (int l=0; l<k; l++)
                {
                    for (int o=0; o<3; o++)
                    {
                        if (o == a[i][l] && o == a[j][l])
                            v[l] = o;
                        if (o != a[i][l] && o != a[j][l] && a[i][l] != a[j][l])
                            v[l] = o;
                    }
                    //good = false;
                }

                if (good)
                    cnt += (st.find(hash_(v)) != st.end());
            }
            cnt /= 2;
            ans += 1ll * cnt * (cnt - 1) / 2;
        }
        cout << ans << '\n';
    }

    return 0;
}