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
#define rand_int (abs((rand() << 15) | rand()))
#define do_zero(massiv) memset(massiv, 0, sizeof(massiv))
#define forn(i, l, r) for (int i = l; i < r; i++)
#define str_to_int(stroka) atoi(stroka.c_str())
#define str_to_ll(stroka) atoll(stroka.c_str())
#define str_to_double(stroka) atof(stroka.c_str())
#define read_int(number) scanf("%d", &number)
#define what_is(x) cerr << #x << " is " << x << endl
#define solve_system int number; cin >> number; forn(i, 0, number) solve()
#define solve_system_scanf int number; scanf("%d", &number); forn(i, 0, number) solve()
#define unique(v) v.resize(unique(all(v)) - v.begin())
#define bits(number) __builtin_popcount(number)

//easy functions
template< typename T >
T gcd(T a, T b) { return a ? gcd(b % a, a) : b; }
template< typename T >
T lcm(T a, T b) { return (a / gcd(a, b)) * b; }
string int_to_str_easy(ll n) { return n ? "" : int_to_str_easy(n / 10) + (char)('0' + n % 10); }
//template< typename T >
//T sum(vector<T> v) {T ans = 0; for (T i : v) ans += i; return ans; }
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
const int MAX_N = 1e5 + 1;
const int MAX_T = (1 << 20);
const int BLOCK = trunc(sqrt(MAX_N)) + 1;
const int MAX_LOG = 21;
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
const ll MOD2 = 1e9 + 9;

// Code starts here

ll hash_(string s)
{
    ll ans1 = 0;
    for (int i = 0; i < s.size(); i++)
        if (s[i] != 'f')
            ans1 = (ans1 * 7LL + (s[i] - 'a' + 1)) % MOD;
    ll ans2 = 0;
    for (int i = 0; i < s.size(); i++)
        if (s[i] != 'f')
            ans2 = (ans2 * 13LL + (s[i] - 'a' + 1)) % MOD2;
    return ((ans1 << 30LL) ^ ans2);
}

vector<ll> al;
vector<int> p;
ll ch1, ch2;
ll st1[52], st2[52];
vector<int> len;
vector<ll> hs1, hs2;

void gen(int b)
{
    if (b == p.size())
    {
        al.push_back((ch1 << 30LL) ^ ch2);
        return;
    }
    ll pr1 = ch1;
    ll pr2 = ch2;
    for (char x = 'a'; x <= 'f'; x++)
    {
        if (x != 'f')
        {
            ch1 = (ch1 * 7LL + (x - 'a' + 1)) % MOD;
            ch2 = (ch2 * 13LL + (x - 'a' + 1)) % MOD2;
        }
        ch1 = (ch1 * st1[len[b]] + hs1[b]) % MOD;
        ch2 = (ch2 * st2[len[b]] + hs2[b]) % MOD2;
        gen(b + 1);
        ch1 = pr1;
        ch2 = pr2;
    }
}

int main()
{   //*
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif /**/
    fast_read;
    unordered_map<ll, int> kol;
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        kol[hash_(s)]++;
    }
    st1[0] = 1;
    st2[0] = 1;
    for (int i = 0; i < 51; i++)
    {
        st1[i + 1] = (st1[i] * 7LL) % MOD;
        st2[i + 1] = (st2[i] * 13LL) % MOD2;
        //cerr << st1[i] << " " << st2[i] << "\n";
    }
    for (int r = 0; r < m; r++)
    {
        string s;
        cin >> s;
        al.clear();
        ch1 = 0;
        ch2 = 0;
        p.clear();
        for (int i = 0; i < s.size(); i++)
            if (s[i] == '?')
                p.push_back(i);
        for (int i = 0; i < s.size() && s[i] != '?'; i++)
        {
            ch1 = (ch1 * 7LL + (s[i] - 'a' + 1)) % MOD;
            ch2 = (ch2 * 13LL + (s[i] - 'a' + 1)) % MOD2;
        }
        len.clear();
        hs1.clear();
        hs2.clear();
        for (int b = 0; b < p.size(); b++)
        {
            len.push_back(0);
            hs1.push_back(0);
            hs2.push_back(0);
            for (int i = p[b] + 1; i < s.size() && s[i] != '?'; i++)
            {
                len[b]++;
                hs1[b] = (hs1[b] * 7LL + (s[i] - 'a' + 1)) % MOD;
                hs2[b] = (hs2[b] * 13LL + (s[i] - 'a' + 1)) % MOD2;
            }
        }
        gen(0);
        sort(al.begin(), al.end());
        unique(al);
        int ans = 0;
        for (ll h : al)
            ans += kol[h];
        cout << ans << "\n";
    }
    return 0;
}