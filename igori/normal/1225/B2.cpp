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

void solve()
{
    int n, k, d;
    cin >> n >> k >> d;
    vector<int> a(n);
    F(i, n) cin >> a[i];
    int ans = 1e9;
    map<int, int> mm;
    for (int i = 0; i < d; i++)
    {
        mm[a[i]]++;
    }
    ans = min(ans, (int)mm.size());
    for (int i = d; i < n; i++)
    {
        mm[a[i]]++;
        mm[a[i - d]]--;
        if (mm[a[i - d]] == 0)
        {
            mm.erase(a[i - d]);
        }
        ans = min(ans, (int)mm.size());
    }
    cout << ans << "\n";
}

signed main()
{
    srand(time(NULL));
    //freopen("", "r", stdin);
    //freopen("", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}