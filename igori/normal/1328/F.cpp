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

const int N = 510200;

int n, k;
int a[N];
int p[N];

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a, a + n);
    for (int i = 0; i + k - 1 < n; i++)
    {
        if (a[i] == a[i + k - 1])
        {
            cout << 0;
            return 0;
        }
    }
    int x = a[k - 1], res = 0;
    for (int i = 0; i < k; i++)
    {
        res += x - a[i];
    }
    int y = a[n - k], res2 = 0;
    for (int i = n - k; i < n; i++)
    {
        res2 += a[i] - y;
    }
    for (int i = 0; i < n; i++)
    {
        p[i] = (i ? p[i - 1] : 0) + a[i];
    }
    int resF = 1e18;
    for (int i = 0; i < n;)
    {
        int j = i;
        while (j < n && a[j] == a[i])
        {
            j++;
        }
        int cnt0 = i;
        int cnt1 = n - j;
        int x = a[i] - 1;
        int y = a[i] + 1;
        int si1 = cnt0 * x - (i ? p[i - 1] : 0);
        int si2 = p[n - 1] - p[j - 1] - cnt1 * y;
        int we = j - i;
        int add = k - we;
        resF = min(resF, si1 + si2 + add);
        if (cnt0 >= add)
        {
            resF = min(resF, si1 + add);
        }
        if (cnt1 >= add)
        {
            resF = min(resF, si2 + add);
        }
        if (i > 0 && a[i - 1] + 1 != a[i])
        {
            int val = a[i] - 1;
            int cnt0 = i;
            int cnt1 = n - i;
            int x = a[i] - 1;
            int y = a[i] + 1;
            int si1 = cnt0 * x - (i ? p[i - 1] : 0);
            int si2 = p[n - 1] - p[i - 1] - cnt1 * y;
            int we = 0;
            int add = k - we;
            resF = min(resF, si1 + si2 + add);
            if (cnt0 >= add)
            {
                resF = min(resF, si1 + add);
            }
            if (cnt1 >= add)
            {
                resF = min(resF, si2 + add);
            }
        }
        if (i + 1 < n && a[i + 1] != a[i] + 1)
        {
            int val = a[i] + 1;
            int cnt0 = j;
            int cnt1 = n - j;
            int x = val - 1;
            int y = val + 1;
            int si1 = cnt0 * x - (j ? p[j - 1] : 0);
            int si2 = p[n - 1] - p[j - 1] - cnt1 * y;
            int we = 0;
            int add = k - we;
            if (cnt0 < add && cnt1 < add)
                resF = min(resF, si1 + si2 + add);
            if (cnt0 >= add)
            {
                resF = min(resF, si1 + add);
            }
            if (cnt1 >= add)
            {
                resF = min(resF, si2 + add);
            }
        }
        i = j;
    }
    cout << resF;
}