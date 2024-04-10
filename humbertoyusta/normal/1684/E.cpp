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

    int tc;
    cin >> tc;
    while (tc--)
    {
        map<int, int> cnt;

        int n, k;
        cin >> n >> k;

        for (int i=0; i<n; i++)
        {
            int u;
            cin >> u;
            cnt[u] ++;
        }

        int neededOp = 0, mex = 0;
        for (int i=0; i<n; i++)
        {
            neededOp += (cnt[i] == 0);
            if (neededOp <= k)
            {
                mex = i + 1;
            }
        }

        multiset<int> s;
        int diff = mex;
        for (auto i : cnt)
        {
            if (i.s >= 1)
            {
                if (i.f > mex)
                {
                    s.insert(i.s);
                    diff ++;
                }
            }
        }

        int op = k;
        while (!s.empty() && op >= *s.begin())
        {
            op -= *s.begin();
            diff --;
            s.erase(s.begin());
        }

        cout << diff - mex << '\n';
    }


    return 0;
}