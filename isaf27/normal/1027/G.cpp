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
#define fastIO ios_base::sync_with_stdio(0)
#define nul point(0, 0)
#define str_to_int(stroka) atoi(stroka.c_str())
#define str_to_ll(stroka) atoll(stroka.c_str())
#define str_to_double(stroka) atof(stroka.c_str())
#define what_is(x) cerr << #x << " is " << x << endl
#define solve_system int number; cin >> number; for (int i = 0; i < number; i++) solve()
#define solve_system_scanf int number; scanf("%d", &number); for (int i = 0; i < number; i++) solve()

//permanent constants
const ld pi = 3.141592653589793238462643383279;
const ld log23 = 1.58496250072115618145373894394781;
const ld eps = 1e-8;
const ll INF = 1e18 + 239;
const ll prost = 239;
const int two = 2;
const int th = 3;
const int MOD = 998244353; //1e9 + 7;
const ll MOD2 = MOD * MOD;
const int BIG = 2e9 + 239;
const int alf = 26;
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};
const int dxo[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
const int dyo[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
const int dig = 10;
const string str_alf = "abcdefghijklmnopqrstuvwxyz";
const string str_alf_big = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const int day[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
const int digarr[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
const int bt = 31;
const int fr = 4;

//easy functions
template< typename T >
inline T gcd(T a, T b) { return a ? gcd(b % a, a) : b; }
template< typename T >
inline T lcm(T a, T b) { return (a / gcd(a, b)) * b; }
inline bool is_down(char x) { return ('a' <= x && x <= 'z'); }
inline bool is_upper(char x) { return ('A' <= x && x <= 'Z'); }
inline bool is_digit(char x) { return ('0' <= x && x <= '9'); }
inline int power(ll a, int b)
{
    ll res = 1;
    while (b > 0)
    {
        if (b & 1) res = (res * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return res;
}

//random
mt19937 rnd(239);

//constants
const int M = 2 * 1e5 + 239;
const int N = 2 * 1e3 + 239;
const int L = 50;
const int T = (1 << 20);
const int B = trunc(sqrt(M)) + 1;
const int X = 1e6 + 239;

vector<pair<ll, int> > divs(ll m)
{
    vector<pair<ll, int> > pr;
    ll mm = m;
    for (ll i = 2; (i * i <= m && mm > 1); i++)
        if (mm % i == 0)
        {
            int kol = 0;
            while (mm % i == 0)
            {
                mm /= i;
                kol++;
            }
            pr.push_back(make_pair(i, kol));
        }
    if (mm > 1) pr.push_back(make_pair(mm, 1));
    return pr;
}

vector<pair<ll, int> > pr;
vector<pair<ll, int> > dv[L];
vector<ll> go[L];
ll m, x, ans;

ll prod(ll a, ll b, ll m)
{
    if (a == 0) return 0;
    ll t = prod(a >> 1LL, b, m);
    t += t;
    if (a & 1) t += b;
    t %= m;
    return t;
}

ll power(ll a, ll k, ll m)
{
    if (k == 0) return (1 % m);
    ll t = power(a, (k >> 1LL), m);
    t = prod(t, t, m);
    if (k & 1LL) t = prod(t, a, m);
    return t;
}

ll getd(ll x, ll nw, ll md, vector<pair<ll, int> > now)
{
    if (nw == 1) return 1;
    vector<pair<ll, int> > u = now;
    for (int i = 0; i < now.size(); i++)
        if (now[i].second > 0)
        {
            ll sd = (nw / now[i].first);
            if (power(x, sd, md) == (1 % md))
            {
                u[i].second--;
                return getd(x, sd, md, u);
            }
        }
    return nw;
}

ll gett(ll p, ll k, ll x, int id)
{
    ll md = 1;
    for (int i = 0; i < k; i++) md *= p;
    ll phi = (md - (md / p));
    vector<pair<ll, int> > now = dv[id];
    now.push_back(make_pair(p, k - 1));
    return getd(x, phi, md, now);
}

void gen(int b, ll phi, ll st)
{
    if (b == pr.size())
    {
        ans += (phi / st);
        return;
    }
    ll t = 1;
    for (int x = 0; x <= pr[b].second; x++)
    {
        gen(b + 1, phi * (t - (t / pr[b].first)), lcm(st, go[b][x]));
        if (x == pr[b].second) return;
        t *= pr[b].first;
    }
}

int main()
{
    #ifdef ONPC
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    fastIO;
    cin >> m >> x;
    ll mm = m;
    for (ll i = 2; (i * i <= m && mm > 1); i++)
        if (mm % i == 0)
        {
            int kol = 0;
            while (mm % i == 0)
            {
                mm /= i;
                kol++;
            }
            pr.push_back(make_pair(i, kol));
        }
    if (mm > 1) pr.push_back(make_pair(mm, 1));
    for (int i = 0; i < pr.size(); i++)
        dv[i] = divs(pr[i].first - 1);
    for (int i = 0; i < pr.size(); i++)
    {
        go[i].push_back(1);
        for (int xx = 0; xx < pr[i].second; xx++)
            go[i].push_back(gett(pr[i].first, xx + 1, x, i));
    }
    ans = 0;
    gen(0, 1, 1);
    cout << ans;
    return 0;
}