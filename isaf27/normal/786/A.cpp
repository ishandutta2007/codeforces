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
const int MAX_N = 7001;
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

int win[two][MAX_N];
int z[two][MAX_N];
int s[two], n;
int h[two][MAX_N];

void bfs()
{
    for (int i = 0; i < n; i++)
    {
        win[0][i] = win[1][i] = 2;
        z[0][i] = s[0];
        z[1][i] = s[1];
    }
    win[0][0] = 0;
    win[1][0] = 0;
    queue<pair<int, int> > q;
    q.push(make_pair(0, 0));
    q.push(make_pair(1, 0));
    while (!q.empty())
    {
        pair<int, int> nw = q.front();
        q.pop();
        int t = nw.first;
        int u = nw.second;
        int x = (t + 1) & 1;
        if (win[t][u] == 0)
        {
            for (int g = 0; g < s[x]; g++)
            {
                int pos = (u - h[x][g] + n) % n;
                if (win[x][pos] == 2)
                {
                    win[x][pos] = 1;
                    q.push(make_pair(x, pos));
                }
            }
        }
        else
        {
            for (int g = 0; g < s[x]; g++)
            {
                int pos = (u - h[x][g] + n) % n;
                z[x][pos]--;
                if (win[x][pos] == 2 && z[x][pos] == 0)
                {
                    win[x][pos] = 0;
                    q.push(make_pair(x, pos));
                }
            }
        }
    }
}

int main()
{   //*
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif /**/
    fast_read;
    cin >> n;
    for (int x = 0; x < two; x++)
    {
        cin >> s[x];
        for (int i = 0; i < s[x]; i++)
            cin >> h[x][i];
    }
    bfs();
    vector<string> ans = {"Lose", "Win", "Loop"};
    for (int i = 1; i < n; i++)
        cout << ans[win[0][i]] << " ";
    cout << "\n";
    for (int i = 1; i < n; i++)
        cout << ans[win[1][i]] << " ";
    return 0;
}