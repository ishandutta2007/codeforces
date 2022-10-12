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

long long max(long long a, long long b)
{
    if (a > b)
        return a;
    return b;
}
long long min(long long a, long long b)
{
    if (a > b)
        return b;
    return a;
}
typedef long long ll;
typedef pair<long long, long long> pii;
typedef pair<ll, ll> pll;

namespace MySpace{

};

#define forn(i, n) for (long long (i) = 0; (i) != (n); (i)++)
#define fi first
#define se second

int n;
int a[300000];
int nb[23][120000];
int lst[23];
int r[5200000];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //freopen("", "r", stdin);
    //freopen("", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; i ++)
    {
        cin >> a[i];
        if (a[i] == 0) r[0] = 1;
    }
    for (int j = 0; j < 23; j++) lst[j] = n;
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = 0; j < 23; j++)
        {
            if (a[i] & (1 << j))
            {
                lst[j] = i;
            }
            nb[j][i] = lst[j];
        }
    }
    for (int i = 0; i < n; i++)
    {
        vector<pair<int, int> > appears;
        for (int j = 0; j < 23; j++)
        {
            appears.push_back({nb[j][i], j});
        }
        sort(appears.begin(), appears.end());
        int x = 0;
        for (int j = 0; j < 23; j++)
        {
            x = (x | (1 << appears[j].second));
            if (j + 1 < 23 && appears[j].first != appears[j + 1].first)
            {
                r[x] = 1;
            }
        }
    }
    ll ans = 0;
    for (int i = 0; i < (1 << 22); i++)
        ans += r[i];
    cout << ans;
}