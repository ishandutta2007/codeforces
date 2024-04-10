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
const int MAX_N = 1e5 + 1;
const int MAX_M = 2001;
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

int n, m, q;

struct polka
{
    vector<bool> v;
    int kol;

    polka()
    {
        this->kol = 0;
        this->v.resize(m);
        for (int i = 0; i < m; i++)
            this->v[i] = false;
    }
};

vector<vector<polka*> > vers;

int main()
{   //*
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif /**/
    fast_read;
    scanf("%d%d%d", &n, &m, &q);
    vers.resize(1);
    for (int i = 0; i < n; i++)
    {
        polka* u = new polka();
        vers[0].push_back(u);
    }
    for (int i = 1; i <= q; i++)
    {
        int ind;
        scanf("%d", &ind);
        if (ind == 4)
        {
            int k;
            scanf("%d", &k);
            vers.push_back(vers[k]);
        }
        else if (ind == 3)
        {
            int u;
            scanf("%d", &u);
            u--;
            vector<polka*> now = vers.back();
            polka* t = new polka();
            for (int i = 0; i < m; i++)
                t->v[i] = !now[u]->v[i];
            t->kol = m - now[u]->kol;
            now[u] = t;
            vers.push_back(now);
        }
        else if (ind == 1)
        {
            int u, v;
            scanf("%d%d", &u, &v);
            u--, v--;
            vector<polka*> now = vers.back();
            polka* t = new polka();
            t->kol = now[u]->kol;
            t->v = now[u]->v;
            if (!t->v[v])
            {
                t->kol++;
                t->v[v] = true;
            }
            now[u] = t;
            vers.push_back(now);
        }
        else
        {
            int u, v;
            scanf("%d%d", &u, &v);
            u--, v--;
            vector<polka*> now = vers.back();
            polka* t = new polka();
            t->kol = now[u]->kol;
            t->v = now[u]->v;
            if (t->v[v])
            {
                t->kol--;
                t->v[v] = false;
            }
            now[u] = t;
            vers.push_back(now);
        }
        int ans = 0;
        for (int i = 0; i < n; i++)
            ans += vers.back()[i]->kol;
        cout << ans << endl;
    }
    return 0;
}