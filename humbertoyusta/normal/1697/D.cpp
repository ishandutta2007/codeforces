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

char queryGet(int id)
{
    cout << "? 1 " << id << '\n';
    cout.flush();
    char ret;
    cin >> ret;
    return ret;
}

int queryHowManyDiff(int l,int r)
{
    cout << "? 2 " << l << ' ' << r << '\n';
    cout.flush();
    int ret;
    cin >> ret;
    return ret;
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

        vector<pair<int, char>> v;

        v.push_back({1, queryGet(1)});

        string s;
        s += v[0].s;

        for (int i=2; i<=n; i++)
        {
            int lastFalse = v.size();
            for (int j=32; j>0; j/=2)
            {
                if (lastFalse - j >= 0)
                {
                    if (queryHowManyDiff(v[lastFalse - j].f, i) == v.size() - (lastFalse - j))
                    {
                        ;
                    }
                    else
                    {
                        lastFalse -= j;
                    }
                }
            }
            if (lastFalse - 1 >= 0)
            {
                s += v[lastFalse - 1].s;
                v[lastFalse - 1].f = i;
                sort(v.begin(), v.end());
            }
            else
            {
                char x = queryGet(i);
                v.push_back({i, x});
                s += x;
            }
        }

        cout << "! " << s << '\n';
        cout.flush();
    }


    return 0;
}