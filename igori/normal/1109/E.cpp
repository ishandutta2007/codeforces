//Updated 29.09.18
//#pragma GCC optimize("O3")
//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("O2")
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
#define forn(i, n) for (int (i) = 0; (i) != (n); i+=1)
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
const int MAX = 100001;
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
    for (int i = 0; y < 1e18; i+=1)
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
    for (int i = 0; i < 10; i+=1)
    c[i] = 0;
    for (int i = 0; x > 0; i+=1)
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
//#define int long long
const int L = 18;
int L2 = 18;
int n, q, mod, id, ansl;
int a[MAX];
ll p[MAX];
ll multi[MAX];
ll divide[MAX];
ll num[MAX];
ll divs[MAX];
ll degrees[9][MAX * L];
ll phi = 1;
int ans[MAX];
int container[9];
int kek[9];
int keksize;
int M_[4 * MAX];
int M;

int readInt()
{
    int a = 0;
    char ch;
    ch = getchar();
    while (ch >= '0' && ch <= '9')
    {
        a = a * 10 + ch - '0';
        ch = getchar();
    }
    return a;
}

struct Node{
    ll summ;
    ll mul1[9];
    ll mul2;
    Node()
    {
        summ = 1, mul2 = 1;
    }
};

Node Segments[4 * MAX];

inline ll get(Node & A)
{
    long long value = A.summ;
    value = value * A.mul2;
    if (value >= mod) value %= mod;
    for (int i = 0; i < id; i+=1)
    {
        value = value * degrees[i][A.mul1[i]];
        if (value >= mod) value %= mod;
    }
    return value;
}

inline ll combine(Node & A, Node & B)
{
    return get(A) + get(B);
}

void build(int V, int L, int R)
{
    if (L + 1 == R)
    {
        Segments[V].summ = 1;
        return;
    }
    int M = (L + R) / 2;
    M_[V] = M;
    build(2 * V + 1, L, M);
    build(2 * V + 2, M, R);
    Segments[V].summ = (Segments[2 * V + 1].summ + Segments[2 * V + 2].summ);
    if (Segments[V].mul2 >= mod) Segments[V].mul2 %= mod;
}

inline void psuh(int & V)
{
    Segments[2 * V + 1].mul2 *= Segments[V].mul2;
    if (Segments[2 * V + 1].mul2 >= mod) Segments[2 * V + 1].mul2 %= mod;
    Segments[2 * V + 2].mul2 *= Segments[V].mul2;
    if (Segments[2 * V + 2].mul2 >= mod) Segments[2 * V + 2].mul2 %= mod;
    Segments[V].mul2 = 1;
    for (int i = 0; i < id; i+=1)
    {
        Segments[2 * V + 1].mul1[i] += Segments[V].mul1[i];
        Segments[2 * V + 2].mul1[i] += Segments[V].mul1[i];
        Segments[V].mul1[i] = 0;
    }
    Segments[V].summ = combine(Segments[2 * V + 1], Segments[2 * V + 2]);
}

inline ll getT(int l, int r, int V, int L, int R)
{
    if (r <= L || R <= l)
    {
        return 0;
    }
    if (l <= L && R <= r)
    {
        return get(Segments[V]);
    }
    int M = M_[V];
    psuh(V);
    return getT(l, r, 2 * V + 1, L, M) + getT(l, r, 2 * V + 2, M, R);
}

inline void mT(int l, int r, int x, int V, int L, int R)
{
    //cout << l << " " << r << " " << V << " " << L << " " << R << endl;
    if (r <= L || R <= l)
    {
        return;
    }
    if (l <= L && R <= r)
    {
        for (int j = 0; j < keksize; j++)
        {
            int i = kek[j];
            Segments[V].mul1[i] += container[i];
        }
        Segments[V].mul2 *= x;
        if (Segments[V].mul2 >= mod)
            Segments[V].mul2 %= mod;
        return;
    }
    int M = M_[V];
    psuh(V);
    mT(l, r, x, 2 * V + 1, L, M);
    mT(l, r, x, 2 * V + 2, M, R);
    Segments[V].summ = combine(Segments[2 * V + 1], Segments[2 * V + 2]);
}

inline void step1(int & l, int & r, int & x)
{
    fill(container, container + 9, 0);
    keksize = 0;
    for (int i = 0; i < id; i+=1)
    {
        //cout << divs[i] << endl;
        while (x % divs[i] == 0)
        {
            x /= divs[i];
            container[i]++;
        }
        if (container[i] > 0)
        {
            kek[keksize] = i;
            keksize++;
        }
    }
    //cout << "x = " << x << endl;
    mT(l, r + 1, x, 0, 0, n);
}
inline void step2(int & p1, int & x)
{
    fill(container, container + 9, 0);
    keksize = 0;
    for (int i = 0; i < id; i+=1)
    {
        while (x % divs[i] == 0)
        {
            x /= divs[i];
            container[i]--;
        }
        if (container[i] < 0)
        {
            kek[keksize] = i;
            keksize++;
        }
    }
    ll y = inq(x, phi - 1, mod);
    mT(p1, p1 + 1, y, 0, 0, n);
}
inline void step3(int & l, int & r)
{
    ans[ansl] = getT(l, r + 1, 0, 0, n) % mod;
    //if (ans[ansl] >= mod) ans[ansl] %= mod;
    ansl++;
}

signed main()
{
    //ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    scanf("%d %d", &n, &mod);
    //n = readInt();
    //mod = readInt();
    //cout << n << " " << mod << endl;

    divide[1] = 1;
    for (int i = 2; i <= MAX; i+=1)
    {
        if (!p[i])
        {
            for (int j = 1; i * j <= MAX; j+=1)
            {
                p[i * j] = i;
            }
            if (mod % i == 0)
            {
                num[i] = id;
                divs[id] = i;
                id++;
            }
            else
            {
                multi[i] = i;
                //divide[i] = inq(i, mod - 2, mod);
            }
        }
    }

    phi = mod;
    int x = mod;
    for (int i = 2; i * i <= x; i+=1)
    {
        if (p[i] == i)
        {
            int cnt = 0;
            while (x % i == 0)
            {
                cnt++;
                x /= i;
            }
            if (cnt)
            {
                phi = (phi * (i - 1)) / i;
            }
        }
    }
    if (x > 1)
    {
        phi *= x - 1;
    }

    for (int i = 0; i < id; i+=1)
    {
        //cout << divs[i] << " ";
        degrees[i][0] = 1;
        if (divs[i] > 5)
            L2 = 10;
        if (divs[i] > 10)
            L2 = 5;
        for (int j = 1; j < MAX * L2; j++)
        {
            degrees[i][j] = (degrees[i][j - 1] * divs[i]);
            if (degrees[i][j] >= mod) degrees[i][j] %= mod;
        }
    }

    build(0, 0, n);
    int a, t, l, r, p;
    for (int i = 0; i < n; i+=1)
    {
        scanf("%d", &a);
        //a = readInt();
        step1(i, i, a);
    }
    //q = readInt();
    scanf("%d", &q);
    while (q--)
    {
        //t = readInt();
        scanf("%d", &t);
        if (t == 1)
        {
            //l = readInt(), r = readInt(), x = readInt();
            scanf("%d %d %d", &l, &r, &x);
            l--;
            r--;
            step1(l, r, x);
        }
        if (t == 2)
        {
            //p = readInt(), x = readInt();
            scanf("%d %d", &p, &x);
            p--;
            step2(p, x);
        }
        if (t == 3)
        {
            //l = readInt(), r = readInt();
            scanf("%d %d", &l, &r);
            l--;
            r--;
            step3(l, r);
        }
    }
    for (int i = 0; i < ansl; i+=1)
    {
        printf("%d ", ans[i]);
    }
}