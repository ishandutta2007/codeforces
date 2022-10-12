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

long long n, k;
long long a[500000];
long long ans[500000];
int pos[500000];
long long inv[500000];

long long Tree[1500000];
long long Tree2[1500000];

void Add(int p, int l, int r, int v)
{
    if (l + 1 == r)
    {
        Tree[v]++;
        return;
    }
    int m = (l + r) / 2;
    if (p < m) Add(p, l, m, 2 * v + 1);
    else Add(p, m, r, 2 * v + 2);
    Tree[v] = Tree[2 * v + 1] + Tree[2 * v + 2];
}

long long Get(int L, int R, int l, int r, int v)
{
    if (R <= l || r <= L)
        return 0;
    if (L <= l && r <= R)
        return Tree[v];
    int m = (l + r) / 2;
    return Get(L, R, l, m, 2 * v + 1) + Get(L, R, m, r, 2 * v + 2);
}

void Add2(int p, int l, int r, int v, int www)
{
    if (l + 1 == r)
    {
        Tree2[v] += www;
        return;
    }
    int m = (l + r) / 2;
    if (p < m) Add2(p, l, m, 2 * v + 1, www);
    else Add2(p, m, r, 2 * v + 2, www);
    Tree2[v] = Tree2[2 * v + 1] + Tree2[2 * v + 2];
}

long long Get2(int L, int R, int l, int r, int v)
{
    if (R <= l || r <= L)
        return 0;
    if (L <= l && r <= R)
        return Tree2[v];
    int m = (l + r) / 2;
    return Get2(L, R, l, m, 2 * v + 1) + Get2(L, R, m, r, 2 * v + 2);
}

long long summa(long long l, long long r)
{
    return (l + r) * (r - l + 1) / 2;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        a[i]--;
        pos[a[i]] = i;
    }
    for (int i = 0; i < n; i++)
    {
        //cout << i << endl;
        Add(pos[i], 0, n, 0);
        Add2(pos[i], 0, n, 0, pos[i]);
        if (i) inv[i] = inv[i - 1];
        inv[i] += Get(pos[i] + 1, n, 0, n, 0);
        if (i % 2 == 1)
        {
            int look = (i + 1) / 2;
            int l = -1, r = n;
            while (l + 1 < r)
            {
                int mid = (l + r) / 2;
                int Before = Get(0, mid, 0, n, 0);
                if (Before >= look)
                {
                    r = mid;
                }
                else
                {
                    l = mid;
                }
            }
            int m = (i + 1) / 2;
            long long s1 = summa(r - m, r - 1) - Get2(0, r, 0, n, 0);
            long long s2 = - summa(r, r + m - 1) + Get2(r, n, 0, n, 0);
            cout << s1 + s2 + inv[i] << " ";
        }
        else
        {
            int look = i / 2;
            int l = -1, r = n;
            while (l + 1 < r)
            {
                int mid = (l + r) / 2;
                int Before = Get(0, mid, 0, n, 0);
                if (Before > look)
                {
                    r = mid;
                }
                else
                {
                    l = mid;
                }
            }
            r--;
            long long eps = i / 2;
            //cout << r << " " << r - eps - 1 << " " << r - 2 << " " << endl;
            long long s1 = summa(r - eps, r - 1) - Get2(0, r, 0, n, 0);
            long long s2 = - summa(r + 1, r + eps) + Get2(r + 1, n, 0, n, 0);
            cout << s1 + s2 + inv[i] << " ";
        }
    }
}