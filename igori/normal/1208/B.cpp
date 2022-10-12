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
#define int long long

const long long MOD = 1e9 + 7;

ll n, m, k;
ll a[1505][1505];
ll b[1500000];
S s, t;
ll ans = 1e9;

signed main()
{
    cin >> n;
    F(i, n) cin >> b[i];
    set<int> ss;
    for (int i = 0; i < n; i++) ss.insert(b[i]);
    if (ss.size() == n)
    {
        cout << 0;
        return 0;
    }
    for (int l = 0; l < n; l++)
    {
        set<int> ss;
        for (int i = 0; i < l; i++)
            ss.insert(b[i]);
        for (int r = n - 1; r >= l; r--)
        {
            int len = r - l + 1;
            int oth = n - len;
            if (ss.size() == oth)
                ans = min(ans, len);
            ss.insert(b[r]);
        }
    }
    cout << ans;
}