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
const ll bt = 62;

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
mt19937_64 rnd(239);

//constants
const int M = 2e5 + 239;
const int N = 2e3 + 239;
const int L = 19;
const int T = (1 << 18);
const int B = trunc(sqrt(M)) + 1;
const int X = 1e4 + 239;

ld ans;

ld dist(pair<ld, ld> a, pair<ld, ld> b)
{
    if (abs(a.first - b.first) > ans) return ans;
    if (abs(a.second - b.second) > ans) return ans;
    return sqrtl((a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second));
}

vector<pair<ld, ld> > func(ld a, ld b, ld c, ld x0, ld y0)
{
    vector<pair<ld, ld> > ansv;
    if (abs(b) > 0.5) ansv.push_back(make_pair(x0, (-c - x0 * a) / b));
    if (abs(a) > 0.5) ansv.push_back(make_pair((-c - y0 * b) / a, y0));
    return ansv;
}

int main()
{
    #ifdef ONPC
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    ios::sync_with_stdio(0); cin.tie(); cout.tie(0);
    cout << fixed << setprecision(20);
    ld a, b, c, x1, y1, x2, y2;
    cin >> a >> b >> c >> x1 >> y1 >> x2 >> y2;
    ans = abs(x1 - x2) + abs(y1 - y2);
    vector<pair<ld, ld> > v1 = func(a, b, c, x1, y1);
    vector<pair<ld, ld> > v2 = func(a, b, c, x2, y2);
    for (pair<ld, ld> t1 : v1)
        for (pair<ld, ld> t2 : v2)
        {
            ld now = 0;
            now += dist(t1, t2);
            now += dist(t1, make_pair(x1, y1));
            now += dist(t2, make_pair(x2, y2));
            ans = min(ans, now);
        }
    cout << ans;
    return 0;
}