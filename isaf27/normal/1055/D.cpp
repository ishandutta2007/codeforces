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
#define what_is(x) cerr << #x << " is " << x << endl
#define solve_system int number; cin >> number; for (int i = 0; i < number; i++) solve()
#define solve_system_scanf int number; scanf("%d", &number); for (int i = 0; i < number; i++) solve()

//permanent constants
const ld pi = acos(-1.0);
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
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};
const int dxb[4] = {-1, 1, 1, -1};
const int dyb[4] = {-1, 1, -1, 1};
const int dxo[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
const int dyo[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
const int dig = 10;
const int day[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
const int digarr[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
const int bt = 31;

//easy functions
template< typename T >
inline T gcd(T a, T b)
{
    while (a)
    {
        b %= a;
        swap(a, b);
    }
    return b;
}
template< typename T >
inline T lcm(T a, T b) { return (a / gcd(a, b)) * b; }
inline bool is_down(char x) { return ('a' <= x && x <= 'z'); }
inline bool is_upper(char x) { return ('A' <= x && x <= 'Z'); }
inline bool is_digit(char x) { return ('0' <= x && x <= '9'); }

//random
//mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
mt19937 rnd(239);

//constants
const int M = 2e5 + 239;
const int N = 3e3 + 10;
const int L = 19;
const int T = (1 << 18);
const int B = trunc(sqrt(M)) + 1;
const int X = 1e4 + 239;

int n, k, kol, l[N], r[N];
string a[N], b[N], c[N];
string x, y;

void over()
{
    cout << "NO";
    exit(0);
}

string s;
int z[X];

bool check(int t, bool ok)
{
    s = x + a[t];
    int nn = s.length();
    z[0] = 0;
    int lf = 0;
    int r = 0;
    for (int i = 1; i < nn; i++)
    {
        z[i] = min(z[i - lf], r - i);
        if (z[i] < 0)
            z[i] = 0;
        while (i + z[i] < nn && s[z[i]] == s[i + z[i]])
            z[i]++;
        if (i + z[i] > r)
        {
            lf = i;
            r = i + z[i];
        }
    }
    for (int i = (int)x.size(); i < nn; i++)
        if (z[i] >= (int)x.size())
        {
            if (!ok) return false;
            if (i - (int)x.size() != l[t]) return false;
            return true;
        }
    if (ok) return false;
    return true;
}

int main()
{
    #ifdef ONPC
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    ios::sync_with_stdio(0); cin.tie(); cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    k = 0;
    vector<int> id;
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
        if (a[i] == b[i])
            c[k++] = a[i];
        else
            id.push_back(i);
    }
    n = (int)id.size();
    for (int i = 0; i < n; i++)
        a[i] = a[id[i]], b[i] = b[id[i]];
    for (int i = n; i < n + k; i++)
        a[i] = c[i - n], b[i] = c[i - n];
    for (int i = 0; i < n; i++)
    {
        l[i] = -1;
        for (int x = 0; x < (int)a[i].size(); x++)
        {
            if (a[i][x] == b[i][x]) continue;
            r[i] = x;
            if (l[i] == -1) l[i] = x;
        }
    }
    for (int i = 0; i < n - 1; i++)
    {
        if (r[i + 1] - l[i + 1] != r[i] - l[i]) over();
        for (int x = 0; x <= r[i] - l[i]; x++)
        {
            if (a[i][l[i] + x] != a[i + 1][l[i + 1] + x]) over();
            if (b[i][l[i] + x] != b[i + 1][l[i + 1] + x]) over();
        }
    }
    int lg = l[0];
    int rg = r[0];
    while (lg > 0)
    {
        bool ch = true;
        for (int i = 0; i < n; i++)
        {
            if (l[i] > 0 && a[i][l[i] - 1] == a[0][lg - 1] && b[i][l[i] - 1] == b[0][lg - 1]) continue;
            ch = false;
            break;
        }
        if (ch)
        {
            lg--;
            for (int i = 0; i < n; i++)
                l[i]--;
        }
        else break;
    }
    while (rg < (int)a[0].size() - 1)
    {
        bool ch = true;
        for (int i = 0; i < n; i++)
        {
            if (r[i] < (int)a[i].size() - 1 && a[i][r[i] + 1] == a[0][rg + 1] && b[i][r[i] + 1] == b[0][rg + 1]) continue;
            ch = false;
            break;
        }
        if (ch)
        {
            rg++;
            for (int i = 0; i < n; i++)
                r[i]++;
        }
        else break;
    }
    x = "";
    y = "";
    for (int i = lg; i <= rg; i++)
        x += a[0][i];
    for (int i = lg; i <= rg; i++)
        y += b[0][i];
    //cerr << x << " " << y << "\n";
    for (int i = 0; i < n; i++)
        if (!check(i, true))
            over();
    for (int i = n; i < n + k; i++)
        if (!check(i, false))
            over();
    cout << "YES\n";
    cout << x << "\n" << y;
    return 0;
}