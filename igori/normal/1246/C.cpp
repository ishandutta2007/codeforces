#include <iostream>
#include <map>
#include <set>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <fstream>
#include <bitset>
#include <queue>
#include <stack>
#include <deque>
#include <complex>
#include <iomanip>
#include <stdio.h>
#include <string.h>

using std::cin;
using std::cout;
using std::cerr;
using std::endl;

using std::map;
using std::set;
using std::bitset;
using std::vector;
using std::string;
using std::multimap;
using std::multiset;
using std::deque;
using std::queue;
using std::stack;
using std::pair;
using std::iterator;

using std::sort;
using std::stable_sort;
using std::reverse;
using std::max_element;
using std::min_element;
using std::unique;
using std::ios_base;
using std::swap;
using std::fill;

using std::setprecision;
using std::fixed;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<long long> vl;
typedef string S;

ll min(ll a, ll b) {return a < b ? a : b;}
ll min(int a, ll b) {return a < b ? a : b;}
ll min(ll a, int b) {return a < b ? a : b;}
ll min(int a, int b) {return a < b ? a : b;}

ll max(ll a, ll b) {return a > b ? a : b;}
ll max(int a, ll b) {return a > b ? a : b;}
ll max(ll a, int b) {return a > b ? a : b;}
ll max(int a, int b) {return a > b ? a : b;}

namespace MySpace{

};

#define F(i, n) for (int (i) = 0; (i) != (n); (i)++)
#define fi first
#define se second
#define re return
#define all(x) (x).begin(), (x).end()


//Cartesian tree
struct Node{
    int x, y;
    ll summ;
    int sz;
    Node * L, * R;
};

Node * NewNode(int x)
{
    Node * R = new Node();
    R->summ = x;
    R->x = x;
    R->y = (1 << 15) * rand() + rand();
    R->sz = 1;
    return R;
}

void describe(Node * Nd)
{
    if (!Nd) return;
    describe(Nd->L);
    cout << Nd->x << " ";
    describe(Nd->R);
}

int get_sz(Node * Nd)
{
    if (Nd) re Nd->sz; re 0;
}

ll get_summ(Node * Nd)
{
    if (Nd) re Nd->summ; re 0;
}

ll update(Node * Nd)
{
    Nd->summ = Nd->x + get_summ(Nd->L) + get_summ(Nd->R);
    Nd->sz = 1 + get_sz(Nd->L) + get_sz(Nd->R);
}

Node * Merge(Node * L, Node * R)
{
    if (!L) return R;
    if (!R) return L;
    if (L->y < R->y)
    {
        L->R = Merge(L->R, R);
        update(L);
        return L;
    }
    else
    {
        R->L = Merge(L, R->L);
        update(R);
        return R;
    }
}

pair<Node *, Node *> Split(Node * Scope, int k)
{
    if (!Scope) return {nullptr, nullptr};
    if (Scope->x <= k)
    {
        pair<Node *, Node *> a = Split(Scope->R, k);
        Scope->R = a.first;
        update(Scope);
        return {Scope, a.second};
    }
    else
    {
        pair<Node *, Node *> a = Split(Scope->L, k);
        Scope->L = a.second;
        update(Scope);
        return {a.first, Scope};
    }
}

pair<Node *, Node *> SplitSize(Node * Scope, int k)
{
    if (!Scope) return {nullptr, nullptr};
    if (get_sz(Scope->L) < k)
    {
        pair<Node *, Node *> a = SplitSize(Scope->R, k - get_sz(Scope->L) - 1);
        Scope->R = a.first;
        update(Scope);
        return {Scope, a.second};
    }
    else
    {
        pair<Node *, Node *> a = SplitSize(Scope->L, k);
        Scope->L = a.second;
        update(Scope);
        return {a.first, Scope};
    }
}

void Add(Node *& Root, int x)
{
    Node * Nd = NewNode(x);
    pair<Node *, Node *> a = Split(Root, x);
    a.first = Merge(a.first, Nd);
    Root = Merge(a.first, a.second);
}

ll n, m;
string s[5000];
const long long MOD = 1e9 + 7;

ll dp[2][2040][2040];
ll summR[2040][2040];
ll summD[2040][2040];
ll summDP[2][2040][2040];

signed main()
{
    srand(time(NULL));
    //freopen("", "r", stdin);
    //freopen("", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    if (n == 1 && m == 1)
    {
        cout << 1;
        return 0;
    }
    F(i, n) cin >> s[i];
    for (int i = 0; i < n; i++)
    {
        int cnt = 0;
        for (int j = m - 1; j >= 0; j--)
        {
            summR[i][j] = cnt;
            cnt += (s[i][j] == 'R');
        }
    }
    for (int j = 0; j < m; j++)
    {
        int cnt = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            summD[i][j] = cnt;
            cnt += (s[i][j] == 'R');
        }
    }
    int t = 1;
    for (int i = n - 1; i >= 0; i--)
    {
        if (s[i][m - 1] == 'R') t = 0;
        dp[1][i][m - 1] = t;
        summDP[1][i][m - 1] = t;
    }
    t = 1;
    for (int j = m - 1; j >= 0; j--)
    {
        if (s[n - 1][j] == 'R') t = 0;
        dp[0][n - 1][j] = t;
        summDP[0][n - 1][j] = t;
    }
    for (int i = n - 2; i >= 0; i--)
    {
        for (int j = m - 2; j >= 0; j--)
        {
            dp[0][i][j] = summDP[1][i][j + 1] - summDP[1][i][m - summR[i][j]]; if (dp[0][i][j] < 0) dp[0][i][j] += MOD;
            dp[1][i][j] = summDP[0][i + 1][j] - summDP[0][n - summD[i][j]][j]; if (dp[1][i][j] < 0) dp[1][i][j] += MOD;
            summDP[0][i][j] = summDP[0][i + 1][j] + dp[0][i][j]; if (summDP[0][i][j] >= MOD) summDP[0][i][j] -= MOD;
            summDP[1][i][j] = summDP[1][i][j + 1] + dp[1][i][j]; if (summDP[1][i][j] >= MOD) summDP[1][i][j] -= MOD;
        }
    }
    cout << (dp[0][0][0] + dp[1][0][0]) % MOD;
}