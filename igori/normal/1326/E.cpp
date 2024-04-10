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
#include <random>
#include <functional>

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
#define int long long

const int N = 310200;
const int MOD = 998244353;

int n;
int p[N], pos[N], q[N];

// Editorial of problem 1179C

int tree[4 * N], add[4 * N];

void push(int v) {
    tree[v * 2 + 1] += add[v];
    add[v * 2 + 1] += add[v];
    tree[v * 2 + 2] += add[v];
    add[v * 2 + 2] += add[v];
    add[v] = 0;
}

void upd(int v, int tl, int tr, int l, int r, int x) {
    if (tr < l || r < tl) {
        return;
    }
    if (l <= tl && tr <= r) {
        tree[v] += x;
        add[v] += x;
        return;
    }
    int tm = (tl + tr) >> 1;
    push(v);
    upd(v * 2 + 1, tl, tm, l, r, x);
    upd(v * 2 + 2, tm + 1, tr, l, r, x);
    tree[v] = max(tree[v * 2 + 1], tree[v * 2 + 2]);
}

int get(int v, int tl, int tr) {
    if (tl == tr) {
        return tl;
    }
    int tm = (tl + tr) >> 1;
    push(v);
    if (tree[v * 2 + 2] >= 1) {
        return get(v * 2 + 2, tm + 1, tr);
    }
    else {
        return get(v * 2 + 1, tl, tm);
    }
}

void add1(int x) {
    //cout << x << ' ' << 1 << '\n';
    upd(0, 0, N, 0, x, 1);
}

void add2(int x) {
    //cout << x << ' ' << -1 << '\n';
    upd(0, 0, N, 0, x, -1);
}

int get() {
    return get(0, 0, N);
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> p[i], pos[p[i]] = i;
    for (int i = 1; i <= n; i++) cin >> q[i];
    int e = n;
    for (int i = 1; i <= n; i++)
    {
        while (e > 0 && get() == 0)
        {
            //cout << e << " " << get() << endl;
            add1(pos[e]);
            e--;
        }
        cout << e + 1 << " ";
        add2(q[i]);
    }
}