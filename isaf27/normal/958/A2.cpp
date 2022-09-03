//isaf27

//#pragma GCC optimize("O3")
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
const ld eps = 1e-8;
const ll INF = 1e18 + 239;
const ll prost = 239;
const int two = 2;
const int th = 3;
const ll MOD = 1e9 + 7;
const ll MOD2 = MOD * MOD;
const int BIG = 1e9 + 239;
const int alf = 26;
const int M = 2 * 1e5 + 239;
const int N = 2 * 1e3 + 239;
const int L = 80;
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
const ll p1 = 239;
const ll p2 = 31;

// Code starts here

ll pr1[N], pr2[N], h1[N], h2[N];
int n, m;
string a[N], b[N];

int main()
{   //*
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif /**/
    fast_read;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int j = 0; j < m; j++)
        cin >> b[j];
    pr1[0] = 0;
    for (int i = 0; i < n; i++)
    {
        pr1[i + 1] = pr1[i] * p1;
        ll s = 0;
        for (int j = 0; j < m; j++)
            s = p2 * s + (b[j][i] - 'a' + 1);
        pr1[i + 1] += s;
    }
    pr2[0] = 0;
    for (int i = 0; i < n; i++)
    {
        pr2[i + 1] = pr2[i] * p2;
        ll s = 0;
        for (int j = 0; j < m; j++)
            s = p1 * s + (a[i][j] - 'a' + 1);
        pr2[i + 1] += s;
    }
    ll pw1 = 1;
    for (int i = 0; i < m; i++)
        pw1 *= p1;
    for (int i = 0; i <= n - m; i++)
        h1[i] = pr1[i + m] - pr1[i] * pw1;
    ll pw2 = 1;
    for (int i = 0; i < m; i++)
        pw2 *= p2;
    for (int i = 0; i <= n - m; i++)
        h2[i] = pr2[i + m] - pr2[i] * pw2;
    /*for (int i = 0; i <= n - m; i++)
        cerr << h1[i] << " ";
    cerr << "\n";
    for (int i = 0; i <= n - m; i++)
        cerr << h2[i] << " ";
    cerr << "\n";*/
    for (int i = 0; i <= n - m; i++)
        for (int j = 0; j <= n - m; j++)
            if (h1[i] == h2[j])
            {
                cout << j + 1 << " " << i + 1;
                return 0;
            }
    return 0;
}