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
const int mod2 = 1000000007;
const int mod = 998244353;
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

int dist(pair<int, int> a,pair<int, int> b)
{
    return abs(a.f - b.f) + abs(a.s - b.s);
}

bool jNotIn(int x, vector<int> v)
{
    for (auto i : v)
        if (x == i)
            return false;
    return true;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.setf(ios::fixed); cout.precision(12);
    srand(time(0));

    //freopen("a.in","r",stdin);
    //freopen("a.in","w",stdout);

    int tc = 1;
    //cin >> tc;
    while (tc--)
    {
        int n;
        cin >> n;

        vector<pair<int, int>> a(n);
        for (int i=0; i<n; i++)
        {
            cin >> a[i].f >> a[i].s;
        }

        vector<vector<int>> comb;

        /// get the quadruplets
        for (int i=0; i<n; i++)
            for (int j=i+1; j<n; j++)
                for (int k=j+1; k<n; k++)
                    for (int l=k+1; l<n; l++)
                    {
                        vector<int> ids = {i, j, k, l};

                        int reqDist = dist(a[i], a[j]);

                        bool quadruplet = true;

                        for (int pid=0; pid<4; pid++)
                            for(int qid=pid+1; qid<4; qid++)
                                if (dist(a[ids[pid]], a[ids[qid]]) != reqDist)
                                    quadruplet = false;

                        if (quadruplet)
                            comb.push_back(ids);
                    }

        /// get the triplets
        for (int i=0; i<n; i++)
            for (int j=i+1; j<n; j++)
                for (int k=j+1; k<n; k++)
                {
                    vector<int> ids = {i, j, k};

                    int reqDist = dist(a[i], a[j]);

                    bool triplet = true;

                    for (int pid=0; pid<3; pid++)
                        for(int qid=pid+1; qid<3; qid++)
                            if (dist(a[ids[pid]], a[ids[qid]]) != reqDist)
                                triplet = false;

                    if (triplet)
                        comb.push_back(ids);
                }

        /// get the pairs
        for (int i=0; i<n; i++)
            for (int j=i+1; j<n; j++)
                comb.push_back({i, j});

        vector<vector<int>> tuples;
        /// validate the tuples
        for (auto i : comb)
        {
            bool ok = true;
            for (int j=0; j<n; j++)
            {
                if (jNotIn(j, i))
                {
                    for (int curr=0; curr<i.size(); curr++)
                        if (dist(a[j], a[i[curr]]) <= dist(a[i[0]], a[i[1]]))
                            ok = false;
                }
            }
            if (ok){
                tuples.push_back(i);
            }
        }

        vector<int> dp(n+1), ndp(n+1), zeros(n+1);
        dp[0] = 1;
        int sumOfTuples = 0;
        for (auto i : tuples)
        {
            sumOfTuples += (int)i.size();
            for (int j=0; j<=n; j++)
            {
                if (j + 1 <= n)
                    ndp[j + 1] = (ndp[j + 1] + dp[j]) % mod;
                int sz = (int)i.size();
                if (j + sz <= n)
                    ndp[j + sz] = (ndp[j + sz] + dp[j]) % mod;
            }
            dp = ndp;
            ndp = zeros;
        }
        for (int i=0; i<n-sumOfTuples; i++)
        {
            for (int j=0; j<=n; j++)
            {
                if (j + 1 <= n)
                    ndp[j + 1] = (ndp[j + 1] + dp[j]) % mod;
            }
            dp = ndp;
            ndp = zeros;
        }

        vector<ll> fact(n+1);
        fact[0] = 1;
        for (ll i=1; i<=n; i++)
            fact[i] = fact[i-1] * i % mod;

        ll ans = 0;
        for (int i=0; i<=n; i++)
        {
            ans = (ans + dp[i] * (fact[n] * qpow(fact[n-i], mod - 2) % mod)) % mod;
            //db(ans)
        }
        cout << ans << '\n';
    }


    return 0;
}