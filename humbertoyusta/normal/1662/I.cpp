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

bool can(ll needed,const vector<ll> &people,const vector<ll> &shop,int n,int m)
{
    for (int i=1; i<=n; i++)
    {
        if (people[n+1] - people[i-1] < needed)
            continue;

        int j = lower_bound(people.begin(), people.end(), needed + people[i-1]) - people.begin();

        int lshop = lower_bound(shop.begin(), shop.end(), (i-1) * 100) - shop.begin() - 1;

        int rshop = upper_bound(shop.begin(), shop.end(), (j-1) * 100) - shop.begin();

        if ((i-1) * 100 + ((i-1) * 100 - shop[lshop]) > (j-1) * 100 - (shop[rshop] - (j-1) * 100) && lshop + 1 == rshop)
            return true;
    }
    return false;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.setf(ios::fixed); cout.precision(12);
    srand(time(0));

    //freopen("a.in","r",stdin);
    //freopen("a.in","w",stdout);

    int n, m;
    cin >> n >> m;

    vector<ll> people(n+2);
    for (int i=1; i<=n+1; i++)
    {
        if (i <= n)
            cin >> people[i];
        people[i] += people[i-1];
    }

    vector<ll> shop(m+2);
    for (int i=1; i<=m; i++)
        cin >> shop[i];
    shop[0] = -mod;
    shop[m+1] = mod + mod;
    sort(shop.begin(), shop.end());

    ll l = 1, r = 1ll * 200'000 * mod;
    while (l < r)
    {
        ll mi = (l + r) / 2ll;
        if (can(mi, people, shop, n, m))
            l = mi + 1;
        else
            r = mi;
    }
    if (!can(l, people, shop, n, m))
        l --;
    cout << l << '\n';

    return 0;
}