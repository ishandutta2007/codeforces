/*
    Author: isaf27 (Ivan Safonov)
*/

#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

//defines
typedef long long ll;
typedef double ld;
#define TIME clock() * 1.0 / CLOCKS_PER_SEC
#define fastIO ios_base::sync_with_stdio(0)
#define nul point(0, 0)
#define str_to_int(stroka) atoi(stroka.c_str())
#define str_to_ll(stroka) atoll(stroka.c_str())
#define str_to_double(stroka) atof(stroka.c_str())
#define what_is(x) cerr << #x << " is " << x << endl
#define solve_system int number; cin >> number; for (int i = 0; i < number; i++) solve()
#define solve_system_scanf int number; scanf("%d", &number); for (int i = 0; i < number; i++) solve()

//permanent constants
const ld pi = 3.141592653589793238462643383279;
const ld log23 = 1.58496250072115618145373894394781;
const ld eps = 1e-8;
const ll INF = 1e18 + 239;
const ll prost = 239;
const int two = 2;
const int th = 3;
const ll MOD = 1e9 + 7; // 998244353
const ll MOD2 = MOD * MOD;
const int BIG = 1e9 + 239;
const int alf = 26;
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
const int fr = 4;

//easy functions
template< typename T >
inline T gcd(T a, T b) { return a ? gcd(b % a, a) : b; }
template< typename T >
inline T lcm(T a, T b) { return (a / gcd(a, b)) * b; }
inline bool is_down(char x) { return ('a' <= x && x <= 'z'); }
inline bool is_upper(char x) { return ('A' <= x && x <= 'Z'); }
inline bool is_digit(char x) { return ('0' <= x && x <= '9'); }
inline int power(ll a, int b)
{
    ll res = 1;
    while (b > 0)
    {
        if (b & 1) res = (res * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return res;
}

//random
mt19937 rnd(239);

//constants
const int M = 2 * 1e5 + 239;
const int N = 2 * 1e3 + 239;
const int L = 19;
const int T = (1 << 20);
const int B = trunc(sqrt(M)) + 1;
const int X = 2e6 + 239;

int n, x[N], y[N], cur, id[N], pos[N];
ll s;
tuple<int, int> ask[X];

ll gett(int i, int j, int h)
{
    ll vx1 = x[j] - x[i];
    ll vy1 = y[j] - y[i];
    ll vx2 = x[h] - x[i];
    ll vy2 = y[h] - y[i];
    ll sq = (vx1 * vy2 - vx2 * vy1);
    return abs(sq);
}

void answer(int i, int j, int h)
{
    cout << "Yes\n";
    cout << x[i] << " " << y[i] << "\n";
    cout << x[j] << " " << y[j] << "\n";
    cout << x[h] << " " << y[h] << "\n";
    exit(0);
}

void reinit(int &x, int &y)
{
    if (y < 0)
    {
        y = -y;
        x = -x;
        return;
    }
    if (y == 0)
    {
        if (x < 0)
        {
            y = -y;
            x = -x;
        }
    }
}

inline bool cmp(tuple<int, int> a, tuple<int, int> b)
{
	int vx1 = x[get<1>(a)] - x[get<0>(a)];
	int vy1 = y[get<1>(a)] - y[get<0>(a)];
	int vx2 = x[get<1>(b)] - x[get<0>(b)];
	int vy2 = y[get<1>(b)] - y[get<0>(b)];
	reinit(vx1, vy1);
	reinit(vx2, vy2);
	if ((ll)vx2 * (ll)vy1 == (ll)vx1 * (ll)vy2) return (a < b);
	return ((ll)vx2 * (ll)vy1 < (ll)vx1 * (ll)vy2);
}

inline void change(int i, int j)
{
    swap(id[pos[i]], id[pos[j]]);
    swap(pos[i], pos[j]);
}

int main()
{
    #ifdef ONPC
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    fastIO;
    cin >> n >> s;
    s *= 2LL;
    cur = 0;
	for (int i = 0; i < n; i++) cin >> x[i] >> y[i];
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
        {
            ask[cur] = make_tuple(i, j);
            cur++;
        }
    sort(ask, ask + cur, cmp);
    vector<tuple<int, int, int> > al;
    for (int i = 0; i < n; i++)
        al.push_back(make_tuple(y[i], x[i], i));
    sort(al.begin(), al.end());
    for (int i = 0; i < n; i++)
        id[i] = get<2>(al[i]);
    for (int i = 0; i < n; i++)
        pos[id[i]] = i;
    int xq, yq, l, r;
    for (int i = 0; i < cur; i++)
    {
        xq = get<0>(ask[i]);
        yq = get<1>(ask[i]);
        l = -1;
        r = pos[xq];
        while (r - l > 1)
        {
            int h = (l + r) / 2;
            if (gett(xq, yq, id[h]) > s)
                l = h;
            else
                r = h;
        }
        for (int u = l - 1; u <= l + 1; u++)
            if (0 <= u && u < n && gett(xq, yq, id[u]) == s)
                answer(xq, yq, id[u]);
        l = pos[xq];
        r = n;
        while (r - l > 1)
        {
            int h = (l + r) / 2;
            if (gett(xq, yq, id[h]) < s)
                l = h;
            else
                r = h;
        }
        for (int u = l - 1; u <= l + 1; u++)
            if (0 <= u && u < n && gett(xq, yq, id[u]) == s)
                answer(xq, yq, id[u]);
        change(xq, yq);
    }
    cout << "No\n";
    return 0;
}