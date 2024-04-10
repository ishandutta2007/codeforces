//isaf27

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
#define solve_system int number; cin >> number; for (int i = 0; i < number; i++) solve()
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
const ld eps = 1e-7;
const ld zero = 0;
const ll INF = 1e18;
const int COUT = 30;
const int prost = 239;
const ll prost64 = 239;
const int two = 2;
const int thr = 3;
const ll sr = 31;
const ll MOD = 1e9 + 7;
const int BIG = 2 * 1e9 + 1;
const int alf = 26;
const int MAX_N = 4 * 1e5 + 239;
const int MAX_M = 2001;
const int MAX_T = (1 << 20);
const int B = trunc(sqrt(MAX_N)) + 1;
const int MAX_LOG = 19;
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
const int digarr[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
const int bt = 31;

// Code starts here

ll cost[MAX_LOG][MAX_N];
ll sum[MAX_LOG][MAX_N];
int up[MAX_LOG][MAX_N];
int good[MAX_LOG][MAX_N];
ll a[MAX_N];
int kol;
int gl[MAX_N];

void add_norm(int p, int x)
{
    //cerr << p + 1 << " " << x + 1 << "\n";
    gl[x] = gl[p] + 1;
    sum[0][x] = a[x];
    good[0][x] = p;
    for (int i = 1; i < MAX_LOG; i++)
    {
        good[i][x] = good[i - 1][good[i - 1][x]];
        sum[i][x] = sum[i - 1][good[i - 1][x]] + sum[i - 1][x];
    }
}

void add(int p, ll w)
{
    //cerr << (p + 1) << " " << w << " ! 1\n";
    a[kol] = w;
    kol++;
    if (a[p] >= w)
        add_norm(p, kol - 1);
    else if (cost[MAX_LOG - 1][p] < w)
        add_norm(kol - 1, kol - 1);
    else
    {
        int to = p;
        for (int i = MAX_LOG - 1; i >= 0; i--)
        {
            if (cost[i][to] < w)
                to = up[i][to];
        }
        if (a[to] < w)
            to = up[0][to];
        add_norm(to, kol - 1);
    }
    up[0][kol - 1] = p;
    cost[0][kol - 1] = w;
    for (int i = 1; i < MAX_LOG; i++)
    {
        up[i][kol - 1] = up[i - 1][up[i - 1][kol - 1]];
        cost[i][kol - 1] = max(cost[i - 1][up[i - 1][kol - 1]], cost[i - 1][kol - 1]);
    }
}

int query(int p, ll w)
{
    //cerr << p << " " << w << " ! 2\n";
    if (a[p] > w)
        return 0;
    if (good[0][p] == p)
        return 1;
    int ans = 0;
    for (int i = MAX_LOG - 1; i >= 0; i--)
    {
        if (gl[p] >= (1 << i))
        {
            if (sum[i][p] <= w)
            {
                w -= sum[i][p];
                ans ^= (1 << i);
                if (gl[p] == (1 << i))
                    break;
                p = good[i][p];
            }
        }
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
    memset(gl, 0, sizeof(gl));
    int q;
    cin >> q;
    a[0] = 0;
    kol = 1;
    for (int i = 0; i < MAX_LOG; i++)
    {
        cost[i][0] = 0;
        sum[i][0] = 0;
        up[i][0] = 0;
        good[i][0] = 0;
    }
    gl[0] = 1;
    ll last = 0;
    for (int z = 0; z < q; z++)
    {
        int tp;
        ll p, q;
        cin >> tp >> p >> q;
        if (tp == 1)
            add((p ^ last) - 1, q ^ last);
        else
        {
            last = query((p ^ last) - 1, q ^ last);
            cout << last << "\n";
        }
    }
    return 0;
}