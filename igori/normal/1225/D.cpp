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

ll n, k;
ll a[500000];
ll cnt[500000];
const ll INF = 1e10;

map<vector<int>, ll> mm;

ll paired[500000];
ll b[500000];

void solve()
{
    for (int i = 0; i < n; i++)
    {
        for (ll j = 2; j * j * j <= a[i]; j++)
        {
            while (a[i] % (j * j * j) == 0)
            {
                a[i] /= j * j * j;
            }
        }
    }
    vector<ll> d(n);
    F(i, n) d[i] = a[i];
    fill(cnt, cnt + 500000, 0);
    F(i, n) cnt[a[i]]++;
    for (int i = 0; i < n; i++)
    {
        vector<ll> divs;
        for (int j = 2; j * j <= a[i]; j++)
        {
            if (a[i] % j == 0)
            {
                while (a[i] % j == 0) a[i] /= j;
                divs.push_back(j);
            }
        }
        if (a[i] > 1)
        {
            divs.push_back(a[i]);
        }
        ll k = 1;
        for (int j = 0; j < divs.size(); j++) k *= divs[j] * divs[j] * divs[j];
        paired[i] = k / d[i];
    }
    long long ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans += cnt[paired[i]];
        if (d[i] == paired[i])
        {
            ans--;
        }
    }
    cout << ans / 2;
    return;
}

signed main()
{
    srand(time(NULL));
    //freopen("", "r", stdin);
    //freopen("", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    F(i, n) cin >> a[i];
    F(i, n) cnt[a[i]]++;
    ll ans = 0;
    if (k >= 4)
    {
        for (int i = 1; ; i++)
        {
            ll r = 1;
            for (int j = 0; j < k; j++)
            {
                r *= i;
                if (r > INF)
                {
                    cout << ans / 2;
                    return 0;
                }
            }
            for (int p = 0; p < n; p++)
            {
                ll other = r / a[p];
                if (other <= 1e5 && a[p] * other == r)
                {
                    ans += cnt[other];
                    if (other == a[p])
                    {
                        ans--;
                    }
                }
            }
        }
        return 0;
    }
    if (k == 2)
    {
        ll ans = 0;
        F(i, n)
        {
            vector<int> v;
            for (int j = 2; j * j <= a[i]; j++)
            {
                while (a[i] % (j * j) == 0)
                {
                    a[i] /= j * j;
                }
                if (a[i] % j == 0)
                {
                    v.push_back(j);
                    a[i] /= j;
                }
            }
            if (a[i] > 1)
            {
                v.push_back(a[i]);
            }
            mm[v]++;
        }
        for (auto it : mm)
        {
            ans += it.second * (it.second - 1) / 2;
        }
        cout << ans;
        return 0;
    }
    if (k == 3)
    {
        solve();
        return 0;
    }
}