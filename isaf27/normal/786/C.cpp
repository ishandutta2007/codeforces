#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <ctime>
#include <vector>
#include <queue>
#include <bitset>
#include <cmath>
#include <time.h>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <stdlib.h>
#include <deque>
#include <iomanip>
#include <complex>
//#include <ext/rope>

using namespace std;
//using namespace __gnu_cxx;

//defines
typedef long long ll;
typedef long double ld;
#define TIME clock() * 1.0 / CLOCKS_PER_SEC
#define fast_read cin.sync_with_stdio(0)
#define PREX(number) cout << fixed << setprecision(number)
#define nul point(0, 0)
#define all(v) v.begin(), v.end()
#define random srand(time(NULL))
#define rand_int ((rand() << 15) | rand())
#define do_zero(massiv) memset(massiv, 0, sizeof(massiv))
#define forn(i, l, r) for (int i = l; i < r; i++)
#define str_to_int(stroka) atoi(stroka.c_str())
#define str_to_ll(stroka) atoll(stroka.c_str())
#define str_to_double(stroka) atof(stroka.c_str())
#define read_int(number) scanf("%d", &number)
#define what_is(x) cerr << #x << " is " << x << endl
#define solve_system int number; cin >> number; forn(i, 0, number) solve()
#define unique(v) v.resize(unique(all(v)) - v.begin())
#define bits(number) __builtin_popcount(number)

//easy functions
template< typename T >
T gcd(T a, T b) { return a ? gcd(b % a, a) : b; }
template< typename T >
T lcm(T a, T b) { return (a / gcd(a, b)) * b; }
string int_to_str_easy(ll n) { return n ? "" : int_to_str_easy(n / 10) + (char)('0' + n % 10); }
template< typename T >
T sum(vector<T> v) {T ans = 0; for (T i : v) ans += i; return ans; }
template< typename T >
bool is_prime_sqrt(T n)
{
    if (n == 1)
        return false;
    T k = trunc(sqrt(n));
    for (T i = 2; i <= k; i++)
        if (n % i == 0)
            return false;
    return true;
}
bool is_down(char x) { return ('a' <= x && x <= 'z'); }
bool is_upper(char x) { return ('A' <= x && x <= 'Z'); }
bool is_digit(char x) { return ('0' <= x && x <= '9'); }
string follow(string s) { for (int i = 0; i < s.length(); i++) if (is_upper(s[i])) s[i] += 'a' - 'A'; return s; }

//constants
const ld pi = 3.141592653589793238462643383279;
const ld log23 = 1.58496250072115618145373894394781;
const ld eps = 1e-8;
const ld zero = 0;
const ll INF = 1e18;
const int COUT = 30;
const int prost = 239;
const ll prost64 = 239;
const int two = 2;
const ll sr = 31;
const ll MOD = 1000000007;
const int BIG = 1e9;
const int alf = 26;
const int MAX_N = 1e5 + 1;
const int BLOCK = trunc(sqrt(MAX_N)) + 1;
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};
const int dxo[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
const int dyo[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
const int bit_max = 32;
const int dig = 10;
const string str_alf = "abcdefghijklmnopqrstuvwxyz";
const string str_alf_big = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const int day[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
const int km = (1 << 17) - 1;

// Code starts here

struct Node
{
    Node *left;
    Node *right;
    int sum, x, y;

    Node(int a, int b)
    {
        this->left = NULL;
        this->right = NULL;
        this->sum = 0;
        this->x = a;
        this->y = b;
    }
};

vector<Node*> v, now;
int last[MAX_N], n, m, a[MAX_N], q;

Node* build(int l, int r, int i)
{
    if (r - l == 1)
    {
        Node *d = new Node(l, r);
        now[i] = d;
        return d;
    }
    int mid = (l + r) >> 1;
    Node *lt = build(l, mid, 2 * i + 1);
    Node *rt = build(mid, r, 2 * i + 2);
    Node *d = new Node(l, r);
    d->left = lt;
    d->right = rt;
    now[i] = d;
    return d;
}

void update(int i, int s)
{
    Node *d = new Node(i, i + 1);
    int u = km + i;
    d->sum = now[u]->sum + s;
    now[u] = d;
    while (u)
    {
        u = (u - 1) / 2;
        Node *y = new Node(now[2 * u + 1]->x, now[2 * u + 2]->y);
        y->left = now[2 * u + 1];
        y->right = now[2 * u + 2];
        y->sum = y->left->sum + y->right->sum;
        now[u] = y;
    }
}

int find_element(Node *t, int k)
{
    if (t->y - t->x == 1)
        return t->x;
    int kol = t->left->sum;
    if (kol >= k)
        return find_element(t->left, k);
    return find_element(t->right, k - kol);
}

int answer(int l, int k)
{
    Node *cur = v[l];
    int al = cur->sum;
    if (al < k)
        return n + 1;
    if (k == 1)
        return l + 1;
    return find_element(cur, k) + 1;
}

int gett(int k)
{
    int c = 0;
    int ans = 0;
    while (c < n)
    {
        //cerr << c << "\n";
        ans++;
        c = answer(c, k + 1) - 1;
    }
    return ans;
}

int main()
{   //*
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif /**/
    fast_read;
    for (int i = 0; i < 2 * km + 1; i++)
        now.push_back(NULL);
    Node *noused = build(0, km + 1, 0);
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
        a[i]--;
    }
    for (int i = 0; i < n; i++)
        last[i] = -1;
    for (int i = 0; i < n; i++)
        v.push_back(NULL);
    for (int i = n - 1; i >= 0; i--)
    {
        if (last[a[i]] != -1)
            update(last[a[i]], -1);
        last[a[i]] = i;
        update(i, 1);
        v[i] = now[0];
    }
    for (int k = 0; k < n; k++)
        cout << gett(k + 1) << " ";
    return 0;
}