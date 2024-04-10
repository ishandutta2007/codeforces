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

//easy functions
ll gcd_ll(ll a, ll b) { return a ? gcd_ll(b % a, a) : b; }
ll lcm_ll(ll a, ll b) { return (a / gcd_ll(a, b)) * b; }
int gcd(int a, int b) { return a ? gcd(b % a, a) : b; }
int lcm(int a, int b) { return (a / gcd(a, b)) * b; }
string int_to_str_easy(ll n) { return n ? "" : int_to_str_easy(n / 10) + (char)('0' + n % 10); }
ll sum(vector<ll> v) {ll ans = 0; for (ll i : v) ans += i; return ans; }
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
const ll MOD = 1000000007;
const int BIG = 1e9;
const int alf = 26;
const int MAX_N = 2 * 1e5 + 1;
const int MAX_D = 7001;
const int MAX_M = 1001;
const int km = (1 << 18) - 1;
const int dxo[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
const int dyo[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};
const int bit_max = 32;

// Code starts here

void solve()
{
    return;
}

unordered_map<ll, int> num;
int n, kol, ogr;
ll k, a[MAX_M];
vector<ll> d;
pair<int, ll> dp[MAX_M][MAX_D];
pair<int, int> pr[MAX_M][MAX_D];

void go(int siz, int del)
{
    if (siz == 0 || kol == ogr)
        return;
    kol++;
    cout << pr[siz][del].first + 1 << " ";
    go(pr[siz][del].first, pr[siz][del].second);
}

int main()
{   //*
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif /**/
    fast_read;
    cin >> n >> k; //kek lol
    for (int i = 0; i < n; i++)
        cin >> a[i];
    if (k == 1)
    {
        int t = 0;
        for (int i = 1; i < n; i++)
            if (a[t] > a[i])
                t = i;
        cout << 1 << endl << t + 1;
        return 0;
    }
    //check answer
    ll kn = k;
    for (int i = 0; i < n; i++)
        kn /= gcd_ll(kn, a[i]);
    if (kn != 1)
    {
        cout << -1;
        return 0;
    }
    for (ll i = 1; i * i <= k; i++)
        if (k % i == 0)
        {
            ll sec = k / i;
            d.push_back(i);
            if (sec != i)
                d.push_back(sec);
        }
    sort(d.begin(), d.end());
    int it = 0;
    for (ll i : d)
        num[i] = it, it++;
    for (int i = 0; i < d.size(); i++)
        dp[0][i] = make_pair(BIG, 0), pr[0][i] = make_pair(0, -1);
    dp[0][0] = make_pair(0, 0);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < d.size(); j++)
        {
            dp[i][j] = dp[i - 1][j];
            pr[i][j] = pr[i - 1][j];
            int nxt = num[d[j] / gcd_ll(d[j], a[i - 1])];
            pair<int, ll> go = make_pair(dp[i - 1][nxt].first + 1, dp[i - 1][nxt].second + a[i - 1]);
            if (go < dp[i][j])
            {
                dp[i][j] = go;
                pr[i][j] = make_pair(i - 1, nxt);
            }
        }
    }
    ogr = dp[n][d.size() - 1].first;
    kol = 0;
    cout << dp[n][d.size() - 1].first << endl;
    go(n, d.size() - 1);
    return 0;
}