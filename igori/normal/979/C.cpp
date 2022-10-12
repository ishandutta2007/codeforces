// Code it, hate me?
// .................
// WA 138 or TL 109?
// Hope, Accepted...

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <cstring>
#include <cmath>
using namespace std;
#define sqr(z) (z) * (z)
#define ch_NO(x) cout << "NO\n"; x = 1 - x;
#define b_NO cout << "NO\n"; break;
#define r_NO cout << "NO\n"; return 0;
#define c_NO cout << "NO\n"; continue;
#define ch_YES(x) cout << "YES\n"; x = 1 - x;
#define b_YES cout << "YES\n"; break;
#define r_YES cout << "YES\n"; return 0;
#define c_YES cout << "YES\n"; continue;
#define sz size()
#define pb push_back
#define int_ "%d",
#define fi first
#define se second
#define mm(k) memset((k), -1, sizeof(k));
#define all(k) (k).begin(), (k).end()
#define forn(i, n) for (int (i) = 0; (i) != (n); i++)
#define nfor(i, n) for (int (i) = (n) - 1; (i) != -1; i--)
#define do_nothing cout << " Work_Error ";
#define erace erase
#define incert insert
#define reverce reverse
#define re return
#define pre pre1234
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long long ll;
typedef double ld;
typedef pair<ll, ll> lpii;
const ll INF = 1e18 + 1;
const int MAX = 200001;
const ll MOD = 1000000007;
struct trio{
    int first;
    int second;
    int third;
};
struct long_trio{
    ll first;
    ll second;
    ll third;
};
double dist_point_line(int x1, int y1, int x2, int y2, int x3, int y3)
{
    double distance = abs((y3 - y1) * x2 - (x3 - x1) * y2 + x3 * y1 - x1 * y3) / (2 * sqrt(sqr(x3 - x1) + sqr(y3 - y1)));
    return distance;
}
double dist_point_point(int x1, int y1, int x2, int y2)
{
    double distance = sqrt(sqr(x1 - y1) + sqr(x2 - y2));
    return distance;
}
ll inq(ll k, ll q)
{
    if (q == 0)
        return 1;
    ll l = inq(k, q / 2);
    if (q % 2 == 0)
        return l * l % MOD;
    else
        return l * l * k % MOD;
}
ll gcd(ll a, ll b)
{
    if (a < b)
        swap(a, b);
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
ll cubr(ll a)
{
    ll l = -1, r = 1e6 + 2;
    while (l < r - 1)
    {
        ll mid = (l + r) / 2;
        if (mid * mid * mid > a)
            r = mid;
        else
            l = mid;
    }
    return l;
}
ll max(ll a, ll b)
{
    if (a > b)
        return a;
    return b;
}
ll min(ll a, ll b)
{
    return -1 * max(-a, -b);
}
ll possible(ll q)
{
    if (q == INF)
        return -1;
    return q;
}
bool correct(int x, int xx)
{
    if (x < 0)
        return 0;
    if (x >= xx)
        return 0;
    return 1;
}
ll dsumm(ll x)
{
    ll y = 1;
    ll z = 0;
    for (int i = 0; i < 18; i++)
    {
        z += x / y % 10;
        y *= 10;
    }
    return z;
}
string months[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
int days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
ll fact[13] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362280, 3622800, 39916800, 479001600};
int cx[7] = {1, -1, 0, 0, 0, 0, 0};
int cy[7] = {0, 0, 1, -1, 0, 0, 0};
int cz[7] = {0, 0, 0, 0, 0, 1, -1};
//______________________
ll n, x, y, a1, b1;
vi graph[500000];
int flague[500000];
vector<int> looking;
int way[500000];
int delta = 0;

struct marray{
    ll x[500000];
    ll n;
    void read(int i)
    {
        cin >> x[i];
        //x[i] = (i * 12345LL) % 100000000;
    }
    void readall()
    {
        forn(i, n)
        {
            cin >> x[i];
        }
    }
    void write(int i)
    {
        cout << x[i] << " ";
    }
    void writeall()
    {
        forn(i, n)
        {
            cout << x[i] << " ";
        }
    }
    void make()
    {
        ;
    }
};

void bfs(int a, int pp)
{
    if (delta == 1)
    {
        return;
    }
    looking.pb(a);
    if (a == y && delta == 0)
    {
        delta = 1;
        return;
    }
    flague[a] = 1;
    if (pp == 1)
    {
        a1++;
    }
    if (pp == 2)
    {
        b1++;
    }
    for (int i = 0; i < graph[a].sz; i++)
    {
        if (flague[graph[a][i]] == -1 && way[graph[a][i]] == 0)
        {
            bfs(graph[a][i], pp);
        }
    }
    if (delta != 1)
    looking.pop_back();
}

int main()
{
    mm(flague);
    cin >> n >> x >> y;
    forn(i, n)
    {
        int a, b;
        cin >> a >> b;
        graph[a].pb(b);
        graph[b].pb(a);
    }
    bfs(x, 0);
    forn(i, looking.sz)
    {
        way[looking[i]] = 1;
    }
    delta = 2;
    mm(flague);
    bfs(x, 1);
    mm(flague);
    bfs(y, 2);
    cout << n * (n - 1) - a1 * b1;
}