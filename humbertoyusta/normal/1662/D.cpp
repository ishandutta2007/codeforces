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
        string s, t;
        cin >> s >> t;

        string a, b;
        vector<int> bpar(2);

        for (auto i : s)
        {
            if (i == 'B')
                bpar[0] ^= 1;
            else
                a += i;
        }

        for (auto i : t)
        {
            if (i == 'B')
                bpar[1] ^= 1;
            else
                b += i;
        }

        if (bpar[0] != bpar[1])
        {
            cout << "NO\n";
            continue;
        }

        vector<char> f1, f2;
        for (auto i : a)
        {
            if (!f1.empty() && f1.back() == i)
                f1.pop_back();
            else
                f1.push_back(i);
        }

        for (auto i : b)
        {
            if (!f2.empty() && f2.back() == i)
                f2.pop_back();
            else
                f2.push_back(i);
        }

        if (f1 == f2)
            cout << "YES\n";
        else
            cout << "NO\n";
    }


    return 0;
}