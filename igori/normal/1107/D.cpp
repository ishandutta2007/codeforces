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

int n, k;
bitset<5200> a[5200];
int summ[5200][5200];
string s[5200];

bool check(int p)
{
    if (n % p != 0) return 0;
    for (int i = p; i <= n; i += p)
    {
        for (int j = p; j <= n; j += p)
        {
            int r = summ[i][j] - summ[i][j - p] - summ[i - p][j] + summ[i - p][j - p];
            //cout << i << " " << j << " " << p << " " << r << endl;
            if (r != 0 && r != p * p) return 0;
        }
    }
    return 1;
}

signed main()
{
    //freopen("", "r", stdin);
    //freopen("", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) cin >> s[i];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j += 4)
        {
            int x = j / 4;
            char d = s[i][x];
            int dd = d - '0';
            if ('0' <= d && d <= '9') ; else dd = dd + '0' - 'A' + 10;
            a[i][j] = dd & 8;
            a[i][j + 1] = dd & 4;
            a[i][j + 2] = dd & 2;
            a[i][j + 3] = dd & 1;
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            summ[i + 1][j + 1] = summ[i][j + 1] + summ[i + 1][j] - summ[i][j] + (a[i][j] == 1);
        }
    }
    ll ans = 1;
    for (int r = 2; r * ans <= n; r++)
    {
        int t = 1;
        for (int j = 2; j * j <= r; j++)
        {
            if (r % j == 0) t = 0;
        }
        if (t == 0) continue;
        while (check(ans * r))
            ans *= r;
    }
    cout << ans;
}