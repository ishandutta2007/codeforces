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
#include <complex>
//#include <ext/rope>

using namespace std;
//using namespace __gnu_cxx;

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
#define solve_system int number; cin >> number; forn(i, 0, number) solve()
#define unique(v) v.resize(unique(all(v)) - v.begin())
#define bits(number) __builtin_popcount(number)

//easy functions
template< typename T >
T gcd(T a, T b) { return a ? gcd(b % a, a) : b; }
template< typename T >
T lcm(T a, T b) { return (a / gcd(a, b)) * b; }
string int_to_str_easy(ll n) { return n ? "" : int_to_str_easy(n / 10) + (char)('0' + n % 10); }
template< typename T >
T sum(vector<T> v) {T ans = 0; for (T i : v) ans += i; return ans; }
template< typename T >
bool is_prime_sqrt(T n)
{
    if (n == 1)
        return false;
    T k = trunc(sqrt(n));
    for (T i = 2; i <= k; i++)
        if (n % i == 0)
            return false;
    return true;
}
bool is_down(char x) { return ('a' <= x && x <= 'z'); }
bool is_upper(char x) { return ('A' <= x && x <= 'Z'); }
bool is_digit(char x) { return ('0' <= x && x <= '9'); }
string follow(string s) { for (int i = 0; i < s.length(); i++) if (is_upper(s[i])) s[i] += 'a' - 'A'; return s; }

//constants
const ld pi = 3.141592653589793238462643383279;
const ld log23 = 1.58496250072115618145373894394781;
const ld eps = 1e-8;
const ld zero = 0;
const ll INF = 1e18;
const int COUT = 30;
const int prost = 239;
const ll prost64 = 239;
const int two = 2;
const ll sr = 31;
const ll MOD = 1000000007;
const int BIG = 1e9;
const int alf = 26;
const int MAX_N = 2 * 1e5 + 1;
const int BLOCK = trunc(sqrt(MAX_N)) + 1;
const int km = (1 << 18);
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};
const int dxo[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
const int dyo[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
const int bit_max = 32;
const int dig = 10;
const string str_alf = "abcdefghijklmnopqrstuvwxyz";
const string str_alf_big = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const int day[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

// Code starts here

int n, m;
bool is[MAX_N];
vector<pair<int, int> > p;
vector<int> can;
int pr[MAX_N];
int kk;
int last[MAX_N];
int dp[MAX_N];
vector<vector<int> > v;

int convert(int x)
{
    if (x == 0)
        return m;
    int a = 1;
    for (int i = 0; i < p.size(); i++)
    {
        int t = p[i].first;
        int now = 0;
        while (x % t == 0 && now < p[i].second)
        {
            now++;
            x /= t;
            a *= t;
        }
    }
    return a;
}

int power(int a, int b, int m)
{
    if (b == 0)
        return 1;
    int x = power(a, b / 2, m);
    int t = ((ll)(x) * (ll)x) % (ll)m;
    if (b % 2 == 0)
        return t;
    return ((ll)t * (ll)a) % (ll)(m);
}

int main()
{   //*
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif /**/
    fast_read;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
        is[i] = true;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        is[x] = false;
    }
    kk = 1;
    int mm = m;
    for (int i = 2; i * i <= mm; i++)
        if (mm % i == 0)
        {
            int kol = 0;
            while (mm % i == 0)
            {
                mm /= i;
                kol++;
            }
            kk *= (i - 1);
            for (int j = 0; j < kol - 1; j++)
                kk *= i;
            p.push_back(make_pair(i, kol));
        }
    if (mm != 1)
    {
        kk *= mm - 1;
        p.push_back(make_pair(mm, 1));
    }
    v.resize(m + 1);
    for (int i = 0; i < m; i++)
        if (is[i])
        {
            int u = convert(i);
            can.push_back(u);
            v[u].push_back(i);
        }
    sort(can.begin(), can.end());
    for (int i = 0; i <= m; i++)
        pr[i] = -1;
    memset(last, -1, sizeof(last));
    for (int i = 0; i < can.size(); i++)
    {
        int x = can[i];
        //cerr << x << "\n";
        if (last[x] != -1)
        {
            dp[x] = dp[x] + 1;
            continue;
        }
        last[x] = i;
        int to = 0;
        for (int j = 0; j < p.size(); j++)
        {
            int t = p[j].first;
            if (x % t == 0)
                if (dp[to] < dp[x / t])
                    to = x / t;
        }
        dp[x] = dp[to] + 1;
        pr[x] = to;
    }
    int ans = 0;
    for (int i = 0; i <= m; i++)
        if (dp[ans] < dp[i])
            ans = i;
    vector<int> l;
    while (ans != 0)
    {
        l.push_back(ans);
        ans = pr[ans];
    }
    reverse(l.begin(), l.end());
    vector<int> perm = {1};
    //cout answer
    for (int i : l)
    {
        for (int x : v[i])
            perm.push_back(x);
    }
    cout << perm.size() - 1 << "\n";
    for (int i = 1; i < perm.size(); i++)
    {
        int x, y;
        x = perm[i - 1];
        y = perm[i];
        int g = __gcd(x, y);
        x /= g;
        y /= g;
        cout << ((ll)power(x, kk - 1, m) * (ll)y) % (ll)m << " ";
    }
    return 0;
}