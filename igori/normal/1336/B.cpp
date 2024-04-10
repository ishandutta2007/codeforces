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
using std::min;

#define int long long

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

const int N = 501000;

int n, m, k;

long long sqr(long long x)
{
    return 1LL * x * x;
}

void solve()
{
    cin >> n >> m >> k;
    vector<int> a(n), b(m), c(k);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[i];
    for (int i = 0; i < k; i++) cin >> c[i];
    sort(all(a));
    sort(all(b));
    sort(all(c));
    long long ans = 5e18;
    //mid A
    for (int x = 0, y = 0, z = 0; x < n; x++)
    {
        while (y + 1 < m && b[y + 1] <= a[x]) y++;
        while (z + 1 < k && c[z] < a[x]) z++;
        if (b[y] <= a[x] && a[x] <= c[z])
        {
            ans = min(ans, sqr(a[x] - b[y]) + sqr(a[x] - c[z]) + sqr(b[y] - c[z]));
        }
    }
    swap(b, c);
    swap(m, k);
    for (int x = 0, y = 0, z = 0; x < n; x++)
    {
        while (y + 1 < m && b[y + 1] <= a[x]) y++;
        while (z + 1 < k && c[z] < a[x]) z++;
        if (b[y] <= a[x] && a[x] <= c[z])
        {
            ans = min(ans, sqr(a[x] - b[y]) + sqr(a[x] - c[z]) + sqr(b[y] - c[z]));
        }
    }
    swap(b, c);
    swap(m, k);
    //mid B
    swap(a, b);
    swap(n, m);
    for (int x = 0, y = 0, z = 0; x < n; x++)
    {
        while (y + 1 < m && b[y + 1] <= a[x]) y++;
        while (z + 1 < k && c[z] < a[x]) z++;
        if (b[y] <= a[x] && a[x] <= c[z])
        {
            ans = min(ans, sqr(a[x] - b[y]) + sqr(a[x] - c[z]) + sqr(b[y] - c[z]));
        }
    }
    swap(b, c);
    swap(m, k);
    for (int x = 0, y = 0, z = 0; x < n; x++)
    {
        while (y + 1 < m && b[y + 1] <= a[x]) y++;
        while (z + 1 < k && c[z] < a[x]) z++;
        if (b[y] <= a[x] && a[x] <= c[z])
        {
            ans = min(ans, sqr(a[x] - b[y]) + sqr(a[x] - c[z]) + sqr(b[y] - c[z]));
        }
    }
    swap(b, c);
    swap(m, k);
    swap(a, b);
    swap(n, m);
    //mid C
    swap(a, c);
    swap(n, k);
    for (int x = 0, y = 0, z = 0; x < n; x++)
    {
        while (y + 1 < m && b[y + 1] <= a[x]) y++;
        while (z + 1 < k && c[z] < a[x]) z++;
        if (b[y] <= a[x] && a[x] <= c[z])
        {
            ans = min(ans, sqr(a[x] - b[y]) + sqr(a[x] - c[z]) + sqr(b[y] - c[z]));
        }
    }
    swap(b, c);
    swap(m, k);
    for (int x = 0, y = 0, z = 0; x < n; x++)
    {
        while (y + 1 < m && b[y + 1] <= a[x]) y++;
        while (z + 1 < k && c[z] < a[x]) z++;
        if (b[y] <= a[x] && a[x] <= c[z])
        {
            ans = min(ans, sqr(a[x] - b[y]) + sqr(a[x] - c[z]) + sqr(b[y] - c[z]));
        }
    }
    swap(b, c);
    swap(m, k);
    swap(a, c);
    swap(n, k);
    //cout << n << " " << m << " " << k << " ";
    cout << ans << "\n";
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