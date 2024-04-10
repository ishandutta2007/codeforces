#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <ctime>
#include <vector>
#include <queue>
#include <bitset>
#include <cmath>
#include <time.h>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <stdlib.h>
#include <deque>
#include <iomanip>

using namespace std;

//defines
typedef long long ll;
typedef long double ld;
#define TIME clock() * 1.0 / CLOCKS_PER_SEC
#define fast_read cin.sync_with_stdio(0)
#define PREX(number) cout << fixed << setprecision(number)
#define nul point(0, 0)
#define all(v) v.begin(), v.end()
#define random srand(time(NULL))
#define rand_int ((rand() << 15) | rand())
#define do_zero(massiv) memset(massiv, 0, sizeof(massiv))
#define forn(i, l, r) for (int i = l; i < r; i++)
#define str_to_int(stroka) atoi(stroka.c_str())
#define str_to_ll(stroka) atoll(stroka.c_str())
#define str_to_double(stroka) atof(stroka.c_str())
#define read_int(number) scanf("%d", &number)
#define what_is(x) cerr << #x << " is " << x << endl
#define russian_code_cup int number; cin >> number; forn(i, 0, number) solve()

//easy functions
ll gcd_ll(ll a, ll b) { return a ? gcd_ll(b % a, a) : b; }
ll lcm_ll(ll a, ll b) { return (a / gcd_ll(a, b)) * b; }
int gcd(int a, int b) { return a ? gcd(b % a, a) : b; }
int lcm(int a, int b) { return (a / gcd(a, b)) * b; }
string int_to_str_easy(ll n) { return n ? "" : int_to_str_easy(n / 10) + (char)('0' + n % 10); }
ll sum(vector<ll> v) {ll ans = 0; for (ll i : v) ans += i; return ans; }

//constants
const ld pi = 3.141592653589793238462643383279;
const ld eps = 1e-8;
const ld zero = 0;
const ll INF = 1e18;
const int prost = 239;
const ll prost64 = 239;
const ll MOD = 1000000007;
const int BIG = 1e9;
const int alf = 26;
const int MAX_N = 200001;
const int km = (1 << 18) - 1;
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};

//service functions
vector<ll> prime_divisors(ll n)
{
    ll k = n;
    vector<ll> ans;
    ll ogr = trunc(sqrt(n));
    for (ll i = 2; i <= ogr; i++)
        if (k % i == 0)
        {
            ans.push_back(i);
            while (k % i == 0)
                k /= i;
        }
    if (k - 1) ans.push_back(k);
    return ans;
}

bool is_prime(ll n)
{
    if (n <= 1)
        return false;
    ll ogr = trunc(sqrt(n));
    for (ll i = 2; i <= ogr; i++)
        if (n % i == 0)
            return false;
    return true;
}

vector<ll> divisors(ll n)
{
    vector<ll> ans;
    ll ogr = trunc(sqrt(n));
    for (ll i = 1; i <= ogr; i++)
    {
        ll k = n / i;
        if (n == k * i)
        {
            ans.push_back(k);
            if (k != i)
                ans.push_back(i);
        }
    }
    return ans;
}

int q;
map<pair<ll, ll>, ll > m;

int main()
{
    random;
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    fast_read;
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        ll f, u, v;
        cin >> f >> u >> v;
        if (f == 1)
        {
            ll w;
            cin >> w;
            ll uu = u;
            ll vv = v;
            unordered_set<ll> k;
            while (u >= 1)
                k.insert(u), u /= 2;
            ll p = 0;
            while (v >= 1)
            {
                if (k.find(v) != k.end())
                {
                    p = v;
                    break;
                }
                v /= 2;
            }
            while (uu != p)
                m[make_pair(uu / 2, uu)] += w, uu /= 2;
            while (vv != p)
                m[make_pair(vv / 2, vv)] += w, vv /= 2;
        }
        else
        {
            ll ans = 0;
            ll uu = u;
            ll vv = v;
            unordered_set<ll> k;
            while (u >= 1)
                k.insert(u), u /= 2;
            ll p = 0;
            while (v >= 1)
            {
                if (k.find(v) != k.end())
                {
                    p = v;
                    break;
                }
                v /= 2;
            }
            while (uu != p)
                ans += m[make_pair(uu / 2, uu)], uu /= 2;
            while (vv != p)
                ans += m[make_pair(vv / 2, vv)], vv /= 2;
            cout << ans << endl;
        }
    }
    return 0;
}