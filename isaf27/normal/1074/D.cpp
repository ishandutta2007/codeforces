/*
    Author: isaf27 (Ivan Safonov)
*/

//#pragma GCC optimize("O3")
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
const int M = 5e5 + 239;
const int N = 1e3 + 239;
const int L = 20;
const int T = (1 << 18);
const int B = trunc(sqrt(M)) + 1;
const int X = 260;

map<int, int> val;
vector<int> v[M];
int cur, par[M], sd[M];

int getid(int x)
{
    if (val.find(x) != val.end()) return val[x];
    val[x] = cur++;
    return (cur - 1);
}

void add(int s, int f, int x)
{
    s = getid(s);
    f = getid(f);
    if (par[s] == par[f]) return;
    x ^= sd[s];
    x ^= sd[f];
    s = par[s];
    f = par[f];
    if ((int)v[s].size() > (int)v[f].size()) swap(s, f);
    for (int i : v[s])
    {
        sd[i] ^= x;
        par[i] = f;
        v[f].push_back(i);
    }
    v[s].clear();
}

int func(int s, int f)
{
    s = getid(s);
    f = getid(f);
    if (par[s] != par[f]) return (-1);
    return (sd[s] ^ sd[f]);
}

int main()
{
    #ifdef ONPC
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    ios::sync_with_stdio(0); cin.tie(); cout.tie(0);
    cur = 0;
    getid(0);
    int q;
    cin >> q;
    for (int i = 0; i < M; i++)
    {
        par[i] = i;
        v[i].push_back(i);
    }
    memset(sd, 0, sizeof(sd));
    int last = 0;
    for (int i = 0; i < q; i++)
    {
        int t, l, r;
        cin >> t >> l >> r;
        l ^= last;
        r ^= last;
        if (l > r) swap(l, r);
        if (t == 1)
        {
            int x;
            cin >> x;
            x ^= last;
            add(l, (r + 1), x);
        }
        else
        {
            int ans = func(l, (r + 1));
            cout << ans << "\n";
            last = ans;
            if (last == -1) last = 1;
        }
    }
    return 0;
}