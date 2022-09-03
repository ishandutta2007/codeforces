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
const ll MOD = 1e9 + 7;
const ll MOD2 = MOD * MOD;
const int BIG = 2 * 1e9 + 239;
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

//easy functions
template< typename T >
inline T gcd(T a, T b) { return a ? gcd(b % a, a) : b; }
template< typename T >
inline T lcm(T a, T b) { return (a / gcd(a, b)) * b; }
inline bool is_down(char x) { return ('a' <= x && x <= 'z'); }
inline bool is_upper(char x) { return ('A' <= x && x <= 'Z'); }
inline bool is_digit(char x) { return ('0' <= x && x <= '9'); }
ll power(ll a, int k)
{
    if (k == 0) return 1;
    ll t = power(a, k >> 1);
    t = (t * t) % MOD;
    if (k & 1) t = (t * a) % MOD;
    return t;
}

//random
mt19937 rnd(239);

//constants
const int M = 2 * 1e5 + 239;
const int N = 2 * 1e3 + 239;
const int L = 20;
const int T = (1 << 20);
const int B = trunc(sqrt(M)) + 1;
const int X = 101;
const int fr = 4;

int n, k, a[fr][X];
vector<tuple<int, int, int> > ans;

void fin()
{
    cout << "-1";
    exit(0);
}

void oper()
{
    for (int x = 0; x < n; x++)
        if (a[1][x] > 0 && a[0][x] == a[1][x])
        {
            ans.push_back(make_tuple(a[1][x], 0, x));
            a[0][x] = 0;
            a[1][x] = 0;
        }
    for (int x = 0; x < n; x++)
        if (a[2][x] > 0 && a[2][x] == a[3][x])
        {
            ans.push_back(make_tuple(a[2][x], 3, x));
            a[2][x] = 0;
            a[3][x] = 0;
        }
}

vector<pair<int, int> > order;

void sdv()
{
    for (int i = 0; i < 2 * n; i++)
        if (a[order[i].first][order[i].second] == 0)
        {
            for (int j = 0; j < 2 * n; j++)
            {
                int t = (i - j + 2 * n) % (2 * n);
                if (a[order[t].first][order[t].second] == 0) continue;
                ans.push_back(make_tuple(a[order[t].first][order[t].second], order[(t + 1) % (2 * n)].first, order[(t + 1) % (2 * n)].second));
                a[order[(t + 1) % (2 * n)].first][order[(t + 1) % (2 * n)].second] = a[order[t].first][order[t].second];
                a[order[t].first][order[t].second] = 0;
            }
            return;
        }
}

int main()
{
    #ifdef ONPC
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    fastIO;
    cin >> n >> k;
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < n; j++)
            cin >> a[i][j];
    for (int i = 0; i < n; i++)
        order.push_back(make_pair(1, i));
    for (int i = n - 1; i >= 0; i--)
        order.push_back(make_pair(2, i));
    if (k == 2 * n)
    {
        bool ch = false;
        for (int x = 0; !ch && x < n; x++)
            if (a[1][x] > 0 && a[0][x] == a[1][x])
            {
                ans.push_back(make_tuple(a[1][x], 0, x));
                a[0][x] = 0;
                a[1][x] = 0;
                ch = true;
            }
        for (int x = 0; !ch && x < n; x++)
            if (a[2][x] > 0 && a[2][x] == a[3][x])
            {
                ans.push_back(make_tuple(a[2][x], 3, x));
                a[2][x] = 0;
                a[3][x] = 0;
                ch = true;
            }
        if (!ch) fin();
    }
    oper();
    for (int i = 0; i < 2 * n; i++)
    {
        sdv();
        oper();
    }
    cout << ans.size() << "\n";
    for (tuple<int, int, int> t : ans)
        cout << get<0>(t) << " " << get<1>(t) + 1 << " " << get<2>(t) + 1 << "\n";
    return 0;
}