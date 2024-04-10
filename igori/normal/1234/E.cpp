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

using std::min;
using std::max;

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

int x[500000];

vector<int> pos[500000];
int into[500000];
int scanA[500000];
int scanB[500000];

void solve()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++) cin >> x[i];
    long long stable = 0;
    x[0] = x[1];
    x[m + 1] = x[m];
    m += 2;
    for (int i = 0; i + 1 < m; i++) stable += abs(x[i] - x[i + 1]);
    for (int i = 1; i + 1 < m; i++) pos[x[i]].push_back(i);
    for (int i = 0; i + 1 < m; i++)
    {
        if (min(x[i], x[i + 1]) + 1 <= max(x[i], x[i + 1]) - 1) {
            scanA[min(x[i], x[i + 1]) + 1]++;
            scanB[max(x[i], x[i + 1]) - 1]++;
        }
    }
    long long kek = 0;
    for (int i = 1; i <= n; i++)
    {
        kek += scanA[i];
        into[i] = kek;
        kek -= scanB[i];
    }
    for (int i = 1; i <= n; i++)
    {
        long long res = stable;
        res -= into[i];
        //cout << i << " " << stable << " " << res << "\n";
        for (int j = 0; j < pos[i].size(); j++)
        {
            int a = x[pos[i][j]];
            int b = x[pos[i][j] + 1];
            res -= abs(a -b);
            if (b == a) res += 0;
            if (b < a) res += b;
            if (b > a) res += b - 1;

            b = x[pos[i][j] - 1];
            res -= abs(a - b);
            if (b == a) res += 0;
            if (b < a) res += b;
            if (b > a) res += b - 1;
        }
        cout << res << " ";
    }
}

signed main()
{
    srand(time(NULL));
    //freopen("", "r", stdin);
    //freopen("", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int TESTCASES = 1;
    while (TESTCASES--)
    {
        solve();
    }
}