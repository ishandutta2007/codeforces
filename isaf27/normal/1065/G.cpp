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
const ll MOD = 998244353;
const ll MOD2 = MOD * MOD;
const int BIG = 1e9 + 239;
const int alf = 26;
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};
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
mt19937 rnd(239);

//constants
const int M = 1e6 + 239;
const int N = 2 * 1e3 + 239;
const int L = 20;
const int T = (1 << 18);
const int B = trunc(sqrt(M)) + 1;
const int X = 210;

string s[X], f[X];
string t;
ll kol[two][X];

vector<int> z_function(string s)
{
    int n = s.length();
    vector<int> z;
    z.resize(n);
    z[0] = 0;
    int l = 0;
    int r = 0;
    for (int i = 1; i < n; i++)
    {
        z[i] = min(z[i - l], r - i);
        if (z[i] < 0)
            z[i] = 0;
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            z[i]++;
        if (i + z[i] > r)
        {
            l = i;
            r = i + z[i];
        }
    }
    return z;
}

void compute(int x)
{
    kol[0][x] = 0;
    kol[1][x] = 0;
    if (x <= 1)
    {
        if (x == 1) compute(x - 1);
        for (int i = 0; i < (int)s[x].size() - (int)t.size(); i++)
            if (s[x].substr(i, (int)t.size()) == t)
                kol[s[x][i + (int)t.size()] - '0'][x]++;
        return;
    }
    compute(x - 1);
    if (kol[0][x - 1] >= INF || kol[0][x - 2] >= INF)
        kol[0][x] = INF;
    else
        kol[0][x] = kol[0][x - 1] + kol[0][x - 2];
    if (kol[1][x - 1] >= INF || kol[1][x - 2] >= INF)
        kol[1][x] = INF;
    else
        kol[1][x] = kol[1][x - 1] + kol[1][x - 2];
    string nw = "";
    nw += t;
    nw += '$';
    nw += f[x - 2];
    nw += s[x - 1];
    vector<int> z = z_function(nw);
    for (int i = (int)f[x - 2].size() - (int)t.size(); i < (int)f[x - 2].size(); i++)
    {
        int r = i + (int)t.size();
        int p = (r - f[x - 2].size());
        if (p >= (int)s[x - 1].size()) continue;
        if (z[i + (int)t.size() + 1] == (int)t.size())
            kol[s[x - 1][p] - '0'][x]++;
    }
}

int main()
{
    #ifdef ONPC
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    s[0] = "0";
    f[0] = "0";
    s[1] = "1";
    f[1] = "1";
    for (int i = 2; i < X; i++)
    {
        if (s[i - 2].size() == X)
            s[i] = s[i - 2];
        else
        {
            string w = s[i - 2] + s[i - 1];
            for (int t = 0; t < min((int)w.size(), X); t++)
                s[i] += w[t];
        }
        if (f[i - 1].size() == X)
            f[i] = f[i - 1];
        else
        {
            string w = f[i - 2] + f[i - 1];
            for (int t = 0; t < min((int)w.size(), X); t++)
                f[i] += w[(int)w.size() - t - 1];
            reverse(f[i].begin(), f[i].end());
        }
    }
    ll n, k, m;
    cin >> n >> k >> m;
    t = "";
    for (int i = 0; i < m; i++)
    {
        string ls = "";
        for (int x = 0; x < min(i, (int)f[n].size()); x++)
            ls += f[n][(int)f[n].size() - x - 1];
        reverse(ls.begin(), ls.end());
        if (ls == t && k == 0)
        {
            cout << ls;
            return 0;
        }
        if (ls == t) k--;
        compute(n);
        if (k < kol[0][n])
        {
            t += '0';
            continue;
        }
        t += '1';
        k -= kol[0][n];
    }
    cout << t;
    return 0;
}