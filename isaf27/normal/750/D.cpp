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
#define ones(v) v.resize(unique(all(v)) - v.begin())
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
const int MAX_N = 31;
const int MAX_M = 301;
const int km = (1 << 18) - 1;
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};
const int dxo[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
const int dyo[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
const int bit_max = 32;
const string str_alf = "abcdefghijklmnopqrstuvwxyz";
const string str_alf_big = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const int day[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
const int napr = 8;

// Code starts here

void solve()
{
    return;
}

int n, t[MAX_N];
bool done[napr][MAX_M][MAX_M];
bool used[MAX_M][MAX_M];
bool go[MAX_M][MAX_M];
int stop;
vector<pair<int, int> > r[napr];

void gen(int to, int x, int y, int turn)
{
    if (turn == stop)
        return;
    for (int i = 0; i < t[turn]; i++)
    {
        used[x][y] = true;
        if (i != t[turn] - 1)
        {
            x += dxo[to];
            y += dyo[to];
        }
    }
    gen((to + 7) & 7, x + dxo[(to + 7) & 7], y + dyo[(to + 7) & 7], turn + 1);
    gen((to + 1) & 7, x + dxo[(to + 1) & 7], y + dyo[(to + 1) & 7], turn + 1);
}

void gen_t(int to, int x, int y, int turn)
{
    if (turn == stop)
        return;
    for (int i = 0; i < t[turn]; i++)
    {
        go[x][y] = true;
        if (i != t[turn] - 1)
        {
            x += dxo[to];
            y += dyo[to];
        }
    }
    gen_t((to + 7) & 7, x + dxo[(to + 7) & 7], y + dyo[(to + 7) & 7], turn + 1);
    gen_t((to + 1) & 7, x + dxo[(to + 1) & 7], y + dyo[(to + 1) & 7], turn + 1);
}

void gen_cool(int to, int x, int y, int turn)
{
    if (turn == stop && !done[to][x][y])
    {
        done[to][x][y] = true;
        for (pair<int, int> t : r[to])
            used[x + t.first][y + t.second] = true;
        return;
    }
    else if (turn == stop)
        return;
    for (int i = 0; i < t[turn]; i++)
    {
        used[x][y] = true;
        if (i != t[turn] - 1)
        {
            x += dxo[to];
            y += dyo[to];
        }
    }
    gen_cool((to + 7) & 7, x + dxo[(to + 7) & 7], y + dyo[(to + 7) & 7], turn + 1);
    gen_cool((to + 1) & 7, x + dxo[(to + 1) & 7], y + dyo[(to + 1) & 7], turn + 1);
}

int main()
{   //*
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif /**/
    fast_read;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> t[i];
    if (n <= 20)
    {
        stop = n;
        gen(1, 150, 150, 0);
        int ans = 0;
        for (int i = 0; i < MAX_M; i++)
            for (int j = 0; j < MAX_M; j++)
                ans += used[i][j];
        cout << ans;
        return 0;
    }
    stop = n;
    for (int h = 0; h < napr; h++)
    {
        memset(go, 0, sizeof(go));
        gen_t(h, 150, 150, 21);
        for (int i = 0; i < MAX_M; i++)
            for (int j = 0; j < MAX_M; j++)
                if (go[i][j])
                    r[h].push_back(make_pair(i - 150, j - 150));
    }
    stop = 21;
    gen_cool(1, 150, 150, 0);
    int ans = 0;
    for (int i = 0; i < MAX_M; i++)
        for (int j = 0; j < MAX_M; j++)
            ans += used[i][j];
    cout << ans;
    return 0;
}