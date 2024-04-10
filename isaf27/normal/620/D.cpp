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
const int thr = 3;
const ll sr = 31;
const int MOD = 1e9 + 7;
const int BIG = 2 * 1e9 + 1;
const int alf = 26;
const int MAX_N = 2 * 1e3 + 10;
const int MAX_M = 2001;
const int MAX_T = (1 << 20);
const int BLOCK = trunc(sqrt(MAX_N)) + 1;
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

int n, m;
ll a[MAX_N], b[MAX_N], sa, sb;

int main()
{   //*
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif /**/
    fast_read;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sa = 0;
    for (int i = 0; i < n; i++)
        sa += a[i];
    cin >> m;
    for (int i = 0; i < m; i++)
        cin >> b[i];
    sb = 0;
    for (int i = 0; i < m; i++)
        sb += b[i];
    ll delta = abs(sa - sb);
    vector<pair<int, int> > ans;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (abs(sa - sb + 2 * b[j] - 2 * a[i]) < delta)
            {
                delta = abs(sa - sb + 2 * b[j] - 2 * a[i]);
                ans = {{i, j}};
            }
    vector<tuple<ll, int, int> > v;
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            v.push_back(make_tuple((sa - 2 * a[i] - 2 * a[j]), i, j));
    sort(v.begin(), v.end());
    for (int i = 0; i < m; i++)
        for (int j = i + 1; j < m; j++)
        {
            ll sn = sb - 2 * b[i] - 2 * b[j];
            int it = lower_bound(v.begin(), v.end(), make_tuple(sn, 0, 0)) - v.begin();
            if (it < v.size())
            {
                ll sna = get<0>(v[it]);
                if (abs(sna - sn) < delta)
                {
                    delta = abs(sna - sn);
                    ans = {{get<1>(v[it]), i}, {get<2>(v[it]), j}};
                }
            }
            if (it > 0)
            {
                ll sna = get<0>(v[it - 1]);
                if (abs(sna - sn) < delta)
                {
                    delta = abs(sna - sn);
                    ans = {{get<1>(v[it - 1]), i}, {get<2>(v[it - 1]), j}};
                }
            }
        }
    cout << delta << "\n";
    cout << ans.size() << "\n";
    for (pair<int, int> t : ans)
        cout << t.first + 1 << " " << t.second + 1 << "\n";
    return 0;
}