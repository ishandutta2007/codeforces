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

signed main()
{
    cin >> n;
    F(i, n)
    {
        int a, b, c;
        cin >> a >> b >> c;
        c %= 3;
        if (c == 0)
        {
            cout << a << "\n";
        }
        if (c == 1)
        {
            cout << b << "\n";
        }
        if (c == 2)
        {
            cout << (a ^ b) << "\n";
        }
    }
}