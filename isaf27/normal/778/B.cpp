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
const int MAX_N = 5002;
const int MAX_M = 1001;
const int BLOCK = trunc(sqrt(MAX_N)) + 1;
const int km = (1 << 18) - 1;
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

int n, m, kol[two][MAX_M];
vector<bitset<MAX_M> > a1;
vector<bitset<MAX_M> > a2;
map<string, int> pos;

int main()
{   //*
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif /**/
    fast_read;
    cin >> n >> m;
    a1.push_back(0);
    bitset<MAX_M> al = 0;
    for (int i = 0; i < m; i++)
        al[i] = 1;
    a2.push_back(al);
    pos["?"] = 0;
    for (int i = 0; i < n; i++)
    {
        string name, unus;
        cin >> name >> unus;
        string fr;
        cin >> fr;
        pos[name] = i + 1;
        if (fr[0] == '0' || fr[0] == '1')
        {
            bitset<MAX_M> now = 0;
            for (int j = 0; j < m; j++)
                now[j] = fr[j] - '0';
            a1.push_back(now);
            a2.push_back(now);
            continue;
        }
        string n1, oper, n2;
        n1 = fr;
        cin >> oper >> n2;
        int x1 = pos[n1];
        int x2 = pos[n2];
        if (oper == "OR")
        {
            a1.push_back(a1[x1] | a1[x2]);
            a2.push_back(a2[x1] | a2[x2]);
            continue;
        }
        if (oper == "XOR")
        {
            a1.push_back(a1[x1] ^ a1[x2]);
            a2.push_back(a2[x1] ^ a2[x2]);
            continue;
        }
        if (oper == "AND")
        {
            a1.push_back(a1[x1] & a1[x2]);
            a2.push_back(a2[x1] & a2[x2]);
            continue;
        }
    }
    for (int i = 0; i < m; i++)
    {
        kol[0][i] = 0;
        for (int j = 1; j <= n; j++)
            if (a1[j][i])
                kol[0][i]++;
        kol[1][i] = 0;
        for (int j = 1; j <= n; j++)
            if (a2[j][i])
                kol[1][i]++;
    }
    string ans1 = "";
    string ans2 = "";
    for (int i = 0; i < m; i++)
    {
        if (kol[0][i] <= kol[1][i])
            ans1 += '0';
        else
            ans1 += '1';
        if (kol[0][i] >= kol[1][i])
            ans2 += '0';
        else
            ans2 += '1';
    }
    cout << ans1 << "\n" << ans2;
    return 0;
}