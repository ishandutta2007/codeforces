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
#define random srand(time(NULL))
#define rand_int abs((rand() << 15) | rand())
#define str_to_int(stroka) atoi(stroka.c_str())
#define str_to_ll(stroka) atoll(stroka.c_str())
#define str_to_double(stroka) atof(stroka.c_str())
#define what_is(x) cerr << #x << " is " << x << endl
#define solve_system int number; cin >> number; forn(i, 0, number) solve()
#define solve_system_scanf int number; scanf("%d", &number); forn(i, 0, number) solve()

//easy functions
template< typename T >
T gcd(T a, T b) { return a ? gcd(b % a, a) : b; }
template< typename T >
T lcm(T a, T b) { return (a / gcd(a, b)) * b; }
bool is_down(char x) { return ('a' <= x && x <= 'z'); }
bool is_upper(char x) { return ('A' <= x && x <= 'Z'); }
bool is_digit(char x) { return ('0' <= x && x <= '9'); }

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
const int MOD = 1e9 + 7;
const int BIG = 2 * 1e9 + 1;
const int alf = 26;
const int MAX_N = 2 * 1e6 + 10;
const int MAX_M = 2001;
const int MAX_T = (1 << 20);
const int BLOCK = trunc(sqrt(MAX_N)) + 1;
const int MAX_LOG = 18;
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
const int bt = 31;

// Code starts here

int n, k;
int mn[MAX_N];
int mb[MAX_N];
ll pw[MAX_N];
ll f[MAX_N];
ll ans;

ll power(ll a, int k)
{
    if (k == 0) return 1;
    ll t = power(a, k >> 1);
    t = (t * t) % MOD;
    if (k & 1) t = (t * a) % MOD;
    return t;
}

void compute(int n)
{
    int nn = n;
    int kol = 0;
    while (n > 1)
    {
        int p = mn[n];
        int t = 0;
        while (n % p == 0)
        {
            t++;
            n /= p;
        }
        if (t > 1)
        {
            kol = -1;
            break;
        }
        kol++;
    }
    if (kol == -1)
        mb[nn] = 0;
    else if (kol & 1)
        mb[nn] = -1;
    else
        mb[nn] = 1;
}

vector<int> divs(int n)
{
    vector<int> pp;
    while (n > 1)
    {
        int p = mn[n];
        int t = 0;
        while (n % p == 0)
        {
            t++;
            n /= p;
        }
        pp.push_back(p);
    }
    vector<int> ans;
    for (int i = 0; i < (1 << pp.size()); i++)
    {
        int pr = 1;
        for (int j = 0; j < pp.size(); j++)
            if ((i >> j) & 1)
                pr *= pp[j];
        ans.push_back(pr);
    }
    return ans;
}

int main()
{   //*
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif /**/
    fast_read;
    memset(mn, -1, sizeof(mn));
    for (int i = 2; i < MAX_N; i++)
        if (mn[i] == -1)
            for (int j = i + i; j < MAX_N; j += i)
                if (mn[j] == -1)
                    mn[j] = i;
    for (int i = 2; i < MAX_N; i++)
        if (mn[i] == -1)
            mn[i] = i;
    for (int i = 1; i < MAX_N; i++)
        compute(i);
    cin >> n >> k;
    for (int i = 1; i < MAX_N; i++)
        pw[i] = power(i, n);
    ll sum = 0;
    ans = 0;
    for (int t = 1; t <= k; t++)
    {
        vector<int> dd = divs(t);
        for (int i : dd)
        {
            ans = (ans + mb[i] * (pw[f[i] + 1] - pw[f[i]]) + MOD + MOD) % MOD;\
            f[i]++;
        }
        sum += (ans ^ t);
    }
    cout << (sum % MOD);
    return 0;
}