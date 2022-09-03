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
template< typename T >
T gcd(T a, T b) { return a ? gcd(b % a, a) : b; }
template< typename T >
T lcm(T a, T b) { return (a / gcd(a, b)) * b; }
string int_to_str_easy(ll n) { return n ? "" : int_to_str_easy(n / 10) + (char)('0' + n % 10); }
template< typename T >
T sum(vector<T> v) {T ans = 0; for (T i : v) ans += i; return ans; }
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
const ll su = 239;
const ll MOD = 1000000007;
const ll MID = 1000000009;
const int BIG = 1e9;
const int alf = 26;
const int MAX_M = 5001;
const int MAX_N = 2 * 1e5 + 1;
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

int n, k, g;
string s;
vector<int> pos;
vector<ll> pref1, pref2;
map<pair<ll, ll>, int> num;
vector<unordered_set<int> > q;

int main()
{   //*
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif /**/
    fast_read;
    cin >> n >> k >> s >> g;
    for (int i = 0; i < g; i++)
    {
        string w;
        cin >> w;
        ll h1 = 0;
        for (int j = 0; j < k; j++)
            h1 = (sr * h1 + (w[j] - 'a' + 1)) % MOD;
        ll h2 = 0;
        for (int j = 0; j < k; j++)
            h2 = (su * h2 + (w[j] - 'a' + 1)) % MID;
        num[{h1, h2}] = i;
    }
    pos.resize(n * k);
    for (int i = 0; i < k; i++)
        s += s[i];
    pref1.resize((n + 1) * k + 1);
    pref1[0] = 0;
    for (int i = 0; i < s.length(); i++)
        pref1[i + 1] = (sr * pref1[i] + (s[i] - 'a' + 1)) % MOD;
    pref2.resize((n + 1) * k + 1);
    pref2[0] = 0;
    for (int i = 0; i < s.length(); i++)
        pref2[i + 1] = (su * pref2[i] + (s[i] - 'a' + 1)) % MID;
    ll d1 = 1;
    for (int i = 0; i < k; i++)
        d1 = (sr * d1) % MOD;
    ll d2 = 1;
    for (int i = 0; i < k; i++)
        d2 = (su * d2) % MID;
    for (int i = 0; i < n * k; i++)
    {
        ll sub1 = pref1[i + k] - d1* pref1[i];
        sub1 %= MOD;
        if (sub1 < 0)
            sub1 += MOD;
        ll sub2 = pref2[i + k] - d2 * pref2[i];
        sub2 %= MID;
        if (sub2 < 0)
            sub2 += MID;
        if (num.find({sub1, sub2}) != num.end())
            pos[i] = num[{sub1, sub2}];
        else
            pos[i] = -1;
    }
    //for (int i = 0; i < n; i++)
     //   cerr << pos[i * k] << endl;
    q.resize(k);
    for (int i = 0; i < n * k; i++)
        q[i % k].insert(pos[i]);
    int ans = -1;
    for (int i = 0; i < k; i++)
        if (q[i].size() == n && q[i].find(-1) == q[i].end())
    {
        ans = i;
        break;
    }
    if (ans == -1)
    {
        cout << "NO";
        return 0;
    }
    cout << "YES\n";
    for (int i = 0; i < n; i++)
        cout << pos[i * k + ans] + 1 << " ";
    return 0;
}