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
const int MAX_N = 2 * 1e5 + 1;
const int MAX_M = 2001;
const int km = (1 << 18) - 1;
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};
const int dxo[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
const int dyo[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
const int bit_max = 32;
const string str_alf = "abcdefghijklmnopqrstuvwxyz";
const string str_alf_big = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

// Code starts here

void solve()
{
    return;
}

int n, last[MAX_N], a[MAX_N], cost[MAX_N];
vector<vector<int> > pos(MAX_N);
set<pair<int, int> > q;

int main()
{   //*
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif /**/
    //fast_read;
    scanf("%d", &n);
    memset(last, -1, sizeof(last));
    for (int i = 0; i < n; i++)
    {
        scanf("%d%d", &a[i], &cost[i]);
        a[i]--;
        pos[a[i]].push_back(i);
        last[a[i]] = i;
    }
    for (int i = 0; i < n; i++)
        if (last[i] != -1)
            q.insert(make_pair(-last[i], i));
    int qq;
    scanf("%d", &qq);
    for (int z = 0; z < qq; z++)
    {
        int k;
        scanf("%d", &k);
        vector<int> now;
        for (int i = 0; i < k; i++)
        {
            int c;
            scanf("%d", &c);
            c--;
            if (last[c] != -1)
            {
                q.erase(make_pair(-last[c], c));
                now.push_back(c);
            }
        }
        if (q.empty())
        {
            cout << "0 0\n";
            for (int i : now)
                q.insert(make_pair(-last[i], i));
            continue;
        }
        int cur = q.begin()->second;
        q.erase(q.begin());
        int no = 0;
        if (!q.empty())
            no = -q.begin()->first;
        int p = lower_bound(pos[cur].begin(), pos[cur].end(), no) - pos[cur].begin();
        cout << cur + 1 << " " << cost[pos[cur][p]] << "\n";
        q.insert(make_pair(-last[cur], cur));
        for (int i : now)
            q.insert(make_pair(-last[i], i));
    }
    return 0;
}