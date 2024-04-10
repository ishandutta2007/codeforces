//isaf27

#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

//defines
typedef long long ll;
typedef double ld;
#define TIME clock() * 1.0 / CLOCKS_PER_SEC
#define fast_read cin.sync_with_stdio(0)
#define PREX(number) cout << fixed << setprecision(number)
#define nul point(0, 0)
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
const ld eps = 1e-10;
const ll INF = 1e18 + 239;
const ll prost = 239;
const int two = 2;
const int th = 3;
const ll MOD = 1e9 + 9;
const ll MOD2 = MOD * MOD;
const int BIG = 1e9 + 239;
const int alf = 26;
const int M = 2 * 1e5 + 239;
const int N = 2 * 1e3 + 239;
const int L = 20;
const int T = (1 << 18);
const int B = trunc(sqrt(M)) + 1;
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

// Code starts here

bool mult(ll a, ll b, ll c, ll d)
{
    ll m1 = (1e9 + 7);
    ll m2 = (1e9 + 9);
    ll m3 = (1e9 + 11);
    ll m4 = (1e9 + 13);
    if (((a % m1) * (b % m1)) % m1 != ((c % m1) * (d % m1)) % m1) return false;
    if (((a % m2) * (b % m2)) % m2 != ((c % m2) * (d % m2)) % m2) return false;
    if (((a % m3) * (b % m3)) % m3 != ((c % m3) * (d % m3)) % m3) return false;
    if (((a % m4) * (b % m4)) % m4 != ((c % m4) * (d % m4)) % m4) return false;
    return true;
}

map<pair<ll, ll>, ll> kol;
vector<vector<ll> > v;
int n;
ll m, k, a[M], b[M];
vector<ll> x, y;

int main()
{   //*
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif /**/
    fast_read;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        ll s, f, c;
        cin >> s >> f >> c;
        x.push_back(s);
        y.push_back(f);
        kol[make_pair(s, f)] = c;
    }
    sort(x.begin(), x.end());
    x.resize(unique(x.begin(), x.end()) - x.begin());
    sort(y.begin(), y.end());
    y.resize(unique(y.begin(), y.end()) - y.begin());
    m = x.size();
    k = y.size();
    if (m * k > n)
    {
        cout << 0;
        return 0;
    }
    random_shuffle(x.begin(), x.end());
    random_shuffle(y.begin(), y.end());
    v.resize(m);
    for (int i = 0; i < m; i++)
        for (int j = 0; j < k; j++)
            v[i].push_back(kol[make_pair(x[i], y[j])]);
    for (int i = 0; i < m; i++)
        for (int j = 0; j < k; j++)
            if (!mult(v[i][0], v[0][j], v[0][0], v[i][j]))
            {
                cout << 0;
                return 0;
            }
    ll g = 0;
    for (int i = 0; i < k; i++)
        g = gcd(g, v[0][i]);
    ll r = 0;
    for (int i = 0; i < m; i++)
        r = gcd(r, v[i][0]);
    r = (v[0][0] / r);
    vector<ll> d;
    for (ll x = 1; x * x <= g; x++)
        if (g % x == 0)
        {
            d.push_back(x);
            d.push_back(g / x);
        }
    sort(d.begin(), d.end());
    d.resize(unique(d.begin(), d.end()) - d.begin());
    int ans = 0;
    for (ll x : d)
        if ((g % x == 0) && (x % r == 0))
            ans++;
    cout << ans;
    return 0;
}