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
int a[500000];
int b[500000];

void solve()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        b[i] = a[i];
    }
    sort(b, b + n);
    if (b[0] == b[n - 1])
    {
        cout << 1 << "\n";
        for (int j = 0; j < n; j++)
        {
            cout << 1 << " ";
        }
        cout << "\n";
        return;
    }
    for (int i = 0; i < n; i++)
    {
        if (a[i] == a[(i + 1) % n])
        {
            cout << 2 << "\n";
            vector<int> ans(n);
            ans[(i + 1) % n] = 1;
            for (int j = (i + 2) % n, op = 1; op < n; op++, j = (j + 1) % n)
            {
                if (a[j] == a[(j - 1 + n) % n])
                {
                    ans[j] = ans[(j - 1 + n) % n];
                }
                else
                {
                    ans[j] = 3 - ans[(j - 1 + n) % n];
                }
            }
            for (int i = 0; i < n; i++) cout << ans[i] << " "; cout << "\n";
            return;
        }
    }
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] != a[(i + 1) % n])
        {
            cnt++;
        }
    }
    if (cnt % 2 == 0)
    {
        cout << 2 << "\n";
        int k = 1;
        for (int i = 0; i < n; i++)
        {
            if (a[i] == a[(i - 1 + n) % n])
            {
                cout << k << " ";
            }
            else
            {
                k = 3 - k;
                cout << k << " ";
            }
        }
        cout << "\n";
        return;
    }
    cout << 3 << "\n";
    cout << 3 << " ";
    int k = 1;
    for (int i = 1; i < n; i++)
    {
        if (a[i] == a[i - 1])
        {
            cout << k << " ";
        }
        else
        {
            k = 3 - k;
            cout << k << " ";
        }
    }
    cout << "\n";
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
}