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

namespace MySpace{

};

#define F(i, n) for (int (i) = 0; (i) != (n); (i)++)
#define fi first
#define se second
#define re return
#define all(x) (x).begin(), (x).end()

void solve()
{
    int n;
    S s1, s2;
    cin >> n >> s1 >> s2;
    int row = 1;
    for (int i = 0; i < n; i++)
    {
        if (row == 1)
        {
            if ('1' <= s1[i] && s1[i] <= '2')
                continue;
            if ('3' <= s1[i] && s1[i] <= '6' && '3' <= s2[i] && s2[i] <= '6')
            {
                row = 2;
                continue;
            }
            cout << "NO\n";
            return;
        }
        else
        {
            if ('1' <= s2[i] && s2[i] <= '2')
                continue;
            if ('3' <= s1[i] && s1[i] <= '6' && '3' <= s2[i] && s2[i] <= '6')
            {
                row = 1;
                continue;
            }
            cout << "NO\n";
            return;
        }
    }
    if (row == 1)
    {
        cout << "NO\n";
    }
    else
    {
        cout << "YES\n";
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
    cin >> TESTCASES;
    while (TESTCASES--)
    {
        solve();
    }
}