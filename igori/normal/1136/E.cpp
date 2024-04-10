//Updated 29.09.18
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <cstring>
#include <cmath>
#include <stdio.h>
#include <time.h>
#include <iomanip>
#include <bitset>
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
#define prev prev1234
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long long ll;
typedef double ld;
typedef pair<ll, ll> lpii;
typedef unsigned long long ull;
const int INF = 1e9;
const ll INFLL = 1e18 + 1;
const int MAX = 200001;
const ll MOD = 1000000007;
const int SZ = 300100;
const double PI = 3.14159265358979323846264338327;
ll inq(ll k, ll q, ll mod)
{
    if (q == 0)
        return 1;
    ll l = inq(k, q / 2, mod);
    if (q % 2 == 0)
        return l * l % mod;
    else
        return l * l % mod * k % mod;
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
ll dsumm(ll x, ll k)
{
    ll y = 1;
    ll z = 0;
    for (int i = 0; y < 1e18; i++)
    {
        z += x / y % k;
        y *= k;
    }
    return z;
}
ll dcount(ll x)
{
    ll y = 1;
    ll z = 0;
    int c[100];
    for (int i = 0; i < 10; i++)
    c[i] = 0;
    for (int i = 0; x > 0; i++)
    {
        if (c[x / y % 10] == 0)
        z++;
        c[x / y % 10] = 1;
        x /= 10;
    }
    return z;
}
ll lg10(ll x)
{
    if (10000 <= x && x < 100000)
        re 5;
    if (x == 0)
        return 0;
    return lg10(x / 10) + 1;
}
ll g(ll x, ll mod)
{
    if (x == 0)
        re 0;
    return x / mod + g(x / mod, mod);
}
bool is_digit(char c)
{
    re ('0' <= c && c <= '9');
}

#define bitcount __builtin_popcount
#define bitcountl __builtin_popcountll

#define RA(n, arr) cin >> n; forn(i, n) cin >> (arr)[i];
#define WA(n, arr) cout << n << "\n"; forn(i, n) cout << (arr)[i] << " ";
#define WWA(n, arr) forn(i, n) cout << (arr)[i] << " ";
#define RSA(n, arr) cin >> n; forn(i, n) cin >> (arr)[i]; sort(arr, arr + n);
#define WSA(n, arr) cout << n << "\n"; sort(arr, arr + n); forn(i, n) cout << (arr)[i] << " ";
#define WWSA(n, arr) sort(arr, arr + n); forn(i, n) cout << (arr)[i] << " ";
#define WSV(vec) cout << vec.size() << "\n"; sort(all(vec)); forn(i, vec.sz) cout << (vec)[i] << " ";
#define WWSV(vec) sort(all(vec)); forn(i, vec.sz) cout << (vec)[i] << " ";
//string months[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
//int days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
//vi cx, cy;
//______________________
#include <deque>
#define endl "\n"
#define int long long
ll n, m;
ll a[525000];
ll k[525000];
ll p[525000];
ll add[525000];
ll added_since[525000];

ll tree[1000200];
ll push[1000200];

int build(int v, int L, int R)
{
    push[v] = -INFLL;
    if (L + 1 == R)
    {
        tree[v] = a[L];
        return tree[v];
    }
    else
    {
        int M = (L + R) / 2;
        tree[v] = build(2 * v + 1, L, M) + build(2 * v + 2, M, R);
        return tree[v];
    }
}

void psuh(int V, int L, int R)
{
    if (push[V] == -INFLL)
        return;
    int M = (L + R) / 2;
    tree[2 * V + 1] = (M - L) * push[V];
    tree[2 * V + 2] = (R - M) * push[V];
    push[2 * V + 1] = push[V];
    push[2 * V + 2] = push[V];
    push[V] = -INFLL;
}

int get(int l, int r, int V, int L, int R)
{
    //cout << l << " " << r << " " << L << " " << R << endl;
    if (r <= L || R <= l)
    {
        return 0;
    }
    if (l <= L && R <= r)
    {
        //cout << "g " << L << " " << R << " " << tree[V] << endl;
        return tree[V];
    }
    psuh(V, L, R);
    int M = (L + R) / 2;
    return get(l, r, 2 * V + 1, L, M) + get(l, r, 2 * V + 2, M, R);
}

void adds(int l, int r, int V, int L, int R, int x)
{
    if (r <= L || R <= l)
    {
        return;
    }
    if (l <= L && R <= r)
    {
        tree[V] = x * (R - L); 
        push[V] = x;
        return;
    }
    psuh(V, L, R);
    int M = (L + R) / 2;
    adds(l, r, 2 * V + 1, L, M, x);
    adds(l, r, 2 * V + 2, M, R, x);
    tree[V] = tree[2 * V + 1] + tree[2 * V + 2];
}

signed main()
{
    //freopen("in.in", "r", stdin);
    //freopen("out.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;
    forn(i, n)
    {
        cin >> a[i];
    }
    for (int i = 1; i < n; i++)
    {
        cin >> k[i];
        p[i] = p[i - 1] + k[i];
    }
    for (int i = 0; i < n; i++)
    {
        a[i] -= p[i];
        add[i] = -p[i];
        added_since[i] = (i > 0 ? added_since[i - 1] : 0) + add[i];
        //cout << p[i] << " ";
        //cout << added_since[i] << "\n";
        //cout << a[i] << " ";
    }
    //cout << endl;
    build(0, 0, n);
    cin >> m;
    //cout << get(0, 1, 0, 0, n) << endl;
    for (int i = 0; i < m; i++)
    {
        char c;
        int a1, b;
        cin >> c >> a1 >> b;
        if (c == 's')
        {
            a1--;
            b--;
            for (int i = a1; i <= b; i++)
            {
                //cout << get(i, i + 1, 0, 0, n) << " ";
            }
            //cout << "e\n";
            cout << get(a1, b + 1, 0, 0, n) - added_since[b] + (a1 > 0 ? added_since[a1 - 1] : 0) << "\n";
        }
        else
        {
            a1--;
            int l = a1, r = n;
            while (l + 1 < r)
            {
                int mid = (l + r) / 2;
                if (get(mid, mid + 1, 0, 0, n) <= get(a1, a1 + 1, 0, 0, n) + b)
                {
                    l = mid;
                }
                else
                {
                    r = mid;
                }
            }
            //cout << a1 << " " << l << endl;
            //cout << get(a1, a1 + 1, 0, 0, n) + b << endl;
            adds(a1, l + 1, 0, 0, n, get(a1, a1 + 1, 0, 0, n) + b);
        }
    }
}