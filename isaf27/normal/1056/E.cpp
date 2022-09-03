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
const ll MOD = 1e9 + 7; //998244353;
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
const ll bt = 30;

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
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
//mt19937_64 rnd(239);

//constants
const int M = 1e6 + 239;
const int N = 2e3 + 239;
const int L = 19;
const int T = (1 << 19);
const int B = trunc(sqrt(M)) + 1;
const int X = 110;

string s, t;
int n, m, c[two];
ll pref[two][M], st[two][M], mod[two], pr[two];

ll gethash(int l, int r)
{
    ll h1 = (pref[0][r + 1] - pref[0][l] * st[0][r - l + 1]) % mod[0];
    ll h2 = (pref[1][r + 1] - pref[1][l] * st[1][r - l + 1]) % mod[1];
    //cerr << h1 << " " << h2 << "!\n";
    if (h1 < 0) h1 += mod[0];
    if (h2 < 0) h2 += mod[1];
    return ((h1 << 31LL) | h2);
}

bool check(int l0, int l1)
{
    //cerr << "here\n";
    //cerr << l0 << " " << l1 << "\n";
    set<ll> q0, q1;
    int l = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '0')
        {
            ll nw = gethash(l, l + l0 - 1);
            q0.insert(nw);
            if (q0.size() > 1) return false;
            l += l0;
        }
        else
        {
            ll nw = gethash(l, l + l1 - 1);
            q1.insert(nw);
            if (q1.size() > 1) return false;
            l += l1;
        }
    }
    //cerr << (*q0.begin()) << " " << (*q1.begin()) << "!!\n";
    if (*q0.begin() == *q1.begin()) return false;
    return true;
}

bool is_prime(int x)
{
    for (int i = 2; i * i <= x; i++)
        if (x % i == 0)
            return false;
    return true;
}

int main()
{
    #ifdef ONPC
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int pos = (abs((int)rnd()) % 600000000) + 600000000;
    vector<int> md;
    while (md.size() < 2)
    {
        if (is_prime(pos))
            md.push_back(pos);
        pos--;
    }
    mod[0] = md[0];
    mod[1] = md[1];
    pr[0] = (abs((ll)rnd()) % (mod[0] - 1000)) + 239;
    pr[1] = (abs((ll)rnd()) % (mod[1] - 1000)) + 239;
    //cerr << mod[0] << " " << pr[0] << "\n";
    //cerr << mod[1] << " " << pr[1] << "\n";
    cin >> s >> t;
    n = (int)s.size();
    m = (int)t.size();
    for (int c = 0; c < 2; c++)
    {
        st[c][0] = 1;
        for (int x = 0; x < m; x++)
            st[c][x + 1] = (st[c][x] * pr[c]) % mod[c];
        pref[c][0] = 0;
        for (int x = 0; x < m; x++)
            pref[c][x + 1] = (pref[c][x] * pr[c] + (t[x] - 'a' + 1)) % mod[c];
    }
    //cerr << gethash(4, 4) << "!\n";
    //return 0;
    c[0] = c[1] = 0;
    for (int i = 0; i < n; i++)
        c[s[i] - '0']++;
    int ans = 0;
    for (int l0 = 1; l0 <= m; l0++)
    {
        if ((ll)m <= (ll)l0 * (ll)c[0]) break;
        int l1 = m - l0 * c[0];
        if (l1 % c[1] == 0)
        {
            l1 /= c[1];
            ans += check(l0, l1);
            continue;
        }
    }
    cout << ans;
    return 0;
}