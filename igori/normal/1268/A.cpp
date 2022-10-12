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

long long n, k;
long long a[500000], c[500000];
string s;

void check()
{
    vector<long long> b(n);
    for (int i = 0; i < k; i++) b[i] = c[i];
    for (int i = k; i < n; i++) b[i] = b[i - k];
    int t = 1;
    for (int i = 0; i < n; i++)
    {
        if (b[i] > a[i])
        {
            break;
        }
        if (b[i] < a[i])
        {
            t = 0;
            break;
        }
    }
    if (t)
    {
        for (int i = 0; i < n; i++) cout << b[i];
        exit(0);
    }
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    cin >> s;
    for (int i = 0; i < n; i++)
    {
        a[i] = s[i] - '0';
        c[i] = a[i];
    }
    cout << n << "\n";
    check();
    for (int x = k - 1; x >= 0; x--)
    {
        if (c[x] != 9)
        {
            c[x]++;
            check();
        }
        else
        {
            c[x] = 0;
        }
    }
}