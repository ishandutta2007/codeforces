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
#define solve_system_scanf int number; scanf("%d", &number); forn(i, 0, number) solve()
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
const int MAX_N = 1e5 + 1;
const int BLOCK = trunc(sqrt(MAX_N)) + 1;
const int MAX_LOG = 21;
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

// Code starts here

int n, m, q, r, comp[MAX_N], kol[MAX_N], up[MAX_N], diam[MAX_N], indd[MAX_N];
vector<vector<int> > v(MAX_N);
vector<vector<int> > w(MAX_N);
vector<vector<ll> > summ(MAX_N);
bool used[MAX_N];
vector<int> now;

vector<vector<int> > pref(MAX_N), suf(MAX_N);

void dfs(int p)
{
    now.push_back(p);
    used[p] = true;
    comp[p] = r;
    for (int i : v[p])
        if (!used[i])
            dfs(i);
}

void dfs_down(int p, int pr, int l)
{
    indd[p] = l;
    kol[p] = 0;
    int it = 0;
    vector<int> dn;
    for (int i : v[p])
    {
        if (i != pr)
        {
            dfs_down(i, p, dn.size());
            dn.push_back(kol[i] + 1);
            kol[p] = max(kol[p], kol[i] + 1);
        }
        it++;
    }
    if (dn.empty())
        return;
    pref[p].resize(dn.size());
    suf[p].resize(dn.size());
    pref[p][0] = 0;
    for (int i = 1; i < dn.size(); i++)
        pref[p][i] = max(pref[p][i - 1], dn[i - 1]);
    suf[p][dn.size() - 1] = 0;
    for (int i = (int)(dn.size()) - 2; i >= 0; i--)
        suf[p][i] = max(suf[p][i + 1], dn[i + 1]);
}

void dfs_up(int p, int pr)
{
    if (pr == -1)
        up[p] = 0;
    else
    {
        up[p] = up[pr];
        up[p] = max(up[p], pref[pr][indd[p]]);
        up[p] = max(up[p], suf[pr][indd[p]]);
        up[p] += 1;
    }
    for (int i : v[p])
        if (i != pr)
            dfs_up(i, p);
}

void answer(int p)
{
    now.clear();
    dfs(p);
    dfs_down(p, -1, -1);
    dfs_up(p, -1);
    for (int i : now)
        diam[r] = max(diam[r], up[i] + kol[i]);
    for (int i : now)
        for (int x = 0; x < (int)pref[i].size() - 1; x++)
            diam[r] = max(diam[r], pref[i][x + 1] + suf[i][x]);
    for (int i : now)
        w[r].push_back(max(up[i], kol[i]));
    sort(w[r].begin(), w[r].end());
    summ[r].resize(w[r].size() + 1);
    summ[r][w[r].size()] = 0;
    for (int i = (int)w[r].size() - 1; i >= 0; i--)
        summ[r][i] = summ[r][i + 1] + (ll)w[r][i];
}

map<pair<int, int>, ll> ans;

void query(int s, int f)
{
    if (comp[s] == comp[f])
    {
        cout << "-1\n";
        return;
    }
    s = comp[s];
    f = comp[f];
    if (w[s].size() > w[f].size())
        swap(s, f);
    if (w[s].size() == w[f].size() && s > f)
        swap(s, f);
    if (ans.find(make_pair(s, f)) != ans.end())
    {
        cout << ((ld)ans[make_pair(s, f)]) / ((ld)w[s].size() * (ld)w[f].size()) << "\n";
        return;
    }
    ll now = (ll)w[s].size() * (ll)w[f].size();
    int d = max(diam[s], diam[f]) - 1;
    //cerr << d << "\n";
    for (int i : w[s])
    {
        int ind = upper_bound(w[f].begin(), w[f].end(), d - i) - w[f].begin();
        //cerr << i << " " << ind << "\n";
        //cerr << summ[f][ind] + (ll)ind * (ll)d << "\n";
        now += summ[f][ind] + (ll)ind * (ll)d + (ll)(w[f].size() - ind) * (ll)i;
    }
    ans[make_pair(s, f)] = now;
    cout << ((ld)now) / ((ld)w[s].size() * (ld)w[f].size()) << "\n";
}

int main()
{   //*
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif /**/
    fast_read;
    scanf("%d%d%d", &n, &m, &q);
    for (int i = 0; i < m; i++)
    {
        int s, f;
        scanf("%d%d", &s, &f);
        s--, f--;
        v[s].push_back(f);
        v[f].push_back(s);
    }
    r = 0;
    for (int i = 0; i < n; i++)
        if (!used[i])
        {
            answer(i);
            r++;
        }
    PREX(15);
    for (int i = 0; i < q; i++)
    {
        int s, f;
        scanf("%d%d", &s, &f);
        s--, f--;
        query(s, f);
    }
    return 0;
}