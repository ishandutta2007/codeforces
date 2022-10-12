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
using std::min;
using std::max;
using std::fill;

using std::setprecision;
using std::fixed;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<long long> vl;
typedef string S;

namespace MySpace{

};

#define F(i, n) for (int (i) = 0; (i) != (n); (i)++)
#define fi first
#define se second
#define re return
#define all(x) (x).begin(), (x).end()

int n, m;
string s[5000];
string t[5000];

bool ok(int i, int j)
{
    return (0 <= i && i < n) && (0 <= j && j < m);
}

void mark(char c, int x, int y, int dx, int dy)
{
    x += dx, y += dy;
    while (ok(x, y) && (s[x][y] == '.'))
    {
        s[x][y] = c;
        x += dx;
        y += dy;
        if (ok(x, y) && s[x][y] != '.' && s[x][y] != '*' && s[x][y] != c)
        {
            cout << "YES";
            exit(0);
        }
    }
    if (ok(x, y))
    {
        if (s[x][y] != '.' && s[x][y] != '*' && s[x][y] != c)
        {
            cout << "YES";
            exit(0);
        }
    }
}

void mark2(char c, int x, int y, int dx, int dy)
{
    x += dx, y += dy;
    while (ok(x, y) && (t[x][y] == '.'))
    {
        t[x][y] = c;
        x += dx;
        y += dy;
        if (ok(x, y) && t[x][y] != '.' &&  t[x][y] != '*' && t[x][y] != c)
        {
            cout << "YES";
            exit(0);
        }
    }
    if (ok(x, y))
    {
        if (t[x][y] != '.' && t[x][y] != '*' && t[x][y] != c)
        {
            cout << "YES";
            exit(0);
        }
    }
}

signed main()
{
    //freopen("", "r", stdin);
    //freopen("", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> s[i];
    int si = -1, sj = -1, ti = -1, tj = -1;
    for (int i = 0; i < n; i++)
    {
        if (si != -1) break;
        for (int j = 0; j < m; j++)
        {
            if (s[i][j] == 'S')
            {
                mark('S', i, j, 0, 1);
                mark('S', i, j, 1, 0);
                mark('S', i, j, -1, 0);
                mark('S', i, j, 0, -1);
                si = i, sj = j;
                break;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (ti != -1) break;
        for (int j = 0; j < m; j++)
        {
            if (s[i][j] == 'T')
            {
                mark('T', i, j, 0, 1);
                mark('T', i, j, 1, 0);
                mark('T', i, j, -1, 0);
                mark('T', i, j, 0, -1);
                ti = i, tj = j;
                break;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        //cout << s[i] << "\n";
        t[i] = s[i];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (s[i][j] == 'S')
            {
                mark('S', i, j, 1, 0);
                mark('S', i, j, -1, 0);
            }
        }
    }
    for (int j = 0; j < m; j++)
    {
        for (int i = 0; i < n; i++)
        {
            if (t[i][j] == 'S')
            {
                mark2('S', i, j, 0, 1);
                mark2('S', i, j, 0, -1);
            }
        }
    }
    cout << "NO";
}