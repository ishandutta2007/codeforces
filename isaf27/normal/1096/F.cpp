/*
    Author: isaf27 (Ivan Safonov)
*/

#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

//defines
typedef long long ll;
typedef long double ld;
#define TIME clock() * 1.0 / CLOCKS_PER_SEC
#define what_is(x) cerr << #x << " is " << x << endl
#define solve_system int number; cin >> number; for (int i = 0; i < number; i++) solve()
#define solve_system_scanf int number; scanf("%d", &number); for (int i = 0; i < number; i++) solve()

//permanent constants
const ld pi = acos(-1.0);
const ld log23 = 1.58496250072115618145373894394781;
const ld eps = 1e-8;
const ll INF = 1e18 + 239;
const ll prost = 239;
const int two = 2;
const int th = 3;
const ll MOD = 998244353;
const ll MOD2 = MOD * MOD;
const int BIG = 1e9 + 239;
const int alf = 26;
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};
const int dxb[4] = {-1, 1, 1, -1};
const int dyb[4] = {-1, 1, -1, 1};
const int dxo[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
const int dyo[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
const int dig = 10;
const int day[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
const int digarr[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
const ll bt = 30;

//easy functions
template< typename T >
inline T gcd(T a, T b)
{
    while (a)
    {
        b %= a;
        swap(a, b);
    }
    return b;
}
template< typename T >
inline T lcm(T a, T b) { return (a / gcd(a, b)) * b; }
inline bool is_down(char x) { return ('a' <= x && x <= 'z'); }
inline bool is_upper(char x) { return ('A' <= x && x <= 'Z'); }
inline bool is_digit(char x) { return ('0' <= x && x <= '9'); }

//random
//mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
mt19937_64 rnd(239);

//constants
const int M = 2e5 + 239;
const int N = (2 * M);
const int L = 18;
const int T = (1 << 20);
const int B = trunc(sqrt(M)) + 1;
const int X = 110;

int n, p[M], tree[M];
vector<int> v;

void upd(int i)
{
    for (; i < n; i |= i + 1) tree[i]++;
}

int getsum(int i)
{
    int ans = 0;
    for (; i >= 0; i = (i & (i + 1)) - 1) ans += tree[i];
    return ans;
}

ll power(ll a, int k)
{
    if (k == 0) return 1;
    ll t = power(a, k >> 1);
    t = (t * t) % MOD;
    if (k & 1) t = (t * a) % MOD;
    return t;
}

int main()
{
    #ifdef ONPC
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> p[i];
        if (p[i] != -1)
        {
            p[i]--;
            v.push_back(p[i]);
        }
    }
    ll ans = 0;
    for (int i = (int)v.size() - 1; i >= 0; i--)
    {
        ans += getsum(v[i]);
        upd(v[i]);
    }
    sort(v.begin(), v.end());
    ll k = 0;
    for (int i = 0; i < n; i++)
        if (p[i] == -1)
            k++;
    ll t = (k * (k - 1)) / 2LL;
    t %= MOD;
    ans += (t * ((MOD + 1) / 2LL)) % MOD;
    ans %= MOD;
    ll s = 0;
    ll ik = power(k, MOD - 2);
    for (int i = 0; i < n; i++)
    {
        if (p[i] == -1)
            s++;
        else
        {
            ll l = s;
            ll r = (k - s);
            ll mn = lower_bound(v.begin(), v.end(), p[i]) - v.begin();
            ll ln = (p[i] - mn);
            ll rn = (k - ln);
            ll sum = (l * rn + ln * r) % MOD;
            sum = (sum * ik) % MOD;
            ans += sum;
        }
    }
    cout << (ans % MOD);
    return 0;
}