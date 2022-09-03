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
#include <deque>
#include <iomanip>

using namespace std;

typedef long long ll;
typedef long double ld;
#define TIME clock() * 1.0 / CLOCKS_PER_SEC
#define fast_read cin.sync_with_stdio(0)
#define PREX(number) cout << fixed << setprecision(number)
#define nul point(0, 0)
#define random srand(time(NULL))
#define rand_int (rand() << 15) | rand()
#define do_zero(massiv) memset(massiv, 0, sizeof(massiv))
#define forn(i, l, r) for (int i = l; i < r; i++)
const ld pi = 3.141592653589793238462643383279;
const ld eps = 1e-8;
const ld zero = 0;
const ll INF = 1e18;
const int prost = 239;
const ll prost64 = 239;
const ll MOD = 1000000007;
const int BIG = 1e9;
const int MAX_N = 200001;
const int km = (1 << 18) - 1;

string int_to_str(ll n)
{
    if (n == 0)
        return "";
    return int_to_str(n / 10) + (char)('0' + n % 10);
}

ll str_to_int(string s)
{
    ll ans = 0;
    for (char x : s)
        ans = 10LL * ans + (x - '0');
    return ans;
}

vector<ll> prime_divisors(ll n)
{
    ll k = n;
    vector<ll> ans;
    ll ogr = trunc(sqrt(n));
    for (ll i = 2; i <= ogr; i++)
    {
        if (k % i == 0)
        {
            ans.push_back(i);
            while (k % i == 0)
                k /= i;
        }
    }
    if (k - 1)
        ans.push_back(k);
    return ans;
}

bool is_prime(ll n)
{
    if (n <= 1)
        return false;
    ll ogr = trunc(sqrt(n));
    for (int i = 2; i <= ogr; i++)
        if (n % i == 0)
            return false;
    return true;
}

int n, a[MAX_N];

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    fast_read;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            swap(a[i], a[j]);
            int pm = 0;
            int px = 0;
            for (int h = 0; h < n; h++)
            {
                if (a[pm] < a[h])
                    pm = h;
                if (a[px] > a[h])
                    px = h;
            }
            ans = max(ans, abs(px - pm));
            swap(a[i], a[j]);
        }
    }
    cout << ans;
    return 0;
}