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

const int N = 1510200;
const int MOD = 998244353;

int n, k;
int dd[N], d[N];

void solve()
{
    string s;
    cin >> s;

    fill(dd, dd + s.size(), 0);
    fill(d, d + s.size(), 0);

    int L = 0, R = s.size() - 1;
    string c = "";
    while (L < R && s[L] == s[R])
    {
        c += s[L];
        L++, R--;
    }
    string g = "";
    for (int i = L; i <= R; i++)
    {
        g += s[i];
    }

    if (g.size() == 0)
    {
        cout << c;
        reverse(all(c));
        cout << c << "\n";
        return;
    }

    int l = 0, r = -1;
    for (int i = 1; i < g.size(); i++)
    {
        int k = 0;
        if (i <= r) k = min(r - i + 1, dd[r - i + l + 1]);
        while (i + k < g.size() && i - k - 1 >= 0 && g[i - k - 1] == g[i + k])
            k++;
        dd[i] = k;
        if (i + k - 1 > r)
        {
            l = i - k;
            r = i + k - 1;
        }
    }

    l = 0, r = -1;
    for (int i = 1; i < g.size(); i++)
    {
        int k = 0;
        if (i <= r) k = min(r - i, d[r - i + l]);
        while (i + k + 1 < g.size() && i - k - 1 >= 0 && g[i - k - 1] == g[i + k + 1])
            k++;
        d[i] = k;
        if (i + k > r)
        {
            l = i - k;
            r = i + k;
        }
    }

    int anspref = 0, anssuff = 0;
    //for (int i = 0; i < g.size(); i++) cout << d[i] << " "; cout << "\n";
    //for (int i = 0; i < g.size(); i++) cout << dd[i] << " "; cout << "\n";

    for (int i = 0; i < g.size(); i++)
    {
        if (d[i] == i)
        {
            anspref = max(anspref, 2 * d[i] + 1);
        }
        if (i > 0 && dd[i] == i)
        {
            anspref = max(anspref, 2 * dd[i]);
        }
    }
    for (int i = 0; i < g.size(); i++)
    {
        if (i + d[i] == g.size() - 1)
        {
            anssuff = max(anssuff, 2 * d[i] + 1);
        }
        if (i + dd[i] == g.size())
        {
            anssuff = max(anssuff, 2 * dd[i]);
        }
    }

    if (anspref > anssuff)
    {
        for (int i = 0; i < c.size(); i++) cout << c[i];
        for (int i = 0; i < anspref; i++) cout << g[i];
        for (int i = 0; i < c.size(); i++) cout << c[c.size() - 1 - i];
        cout << "\n";
    }
    else
    {
        for (int i = 0; i < c.size(); i++) cout << c[i];
        for (int i = g.size() - anssuff; i < g.size(); i++) cout << g[i];
        for (int i = 0; i < c.size(); i++) cout << c[c.size() - 1 - i];
        cout << "\n";
    }
}

signed main()
{
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