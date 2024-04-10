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

const long long inf = 1e18;
const long long infsmart = 1e12;

void Set(int l, int r, int L, int R, int V, int val)
{
    if (l <= L && R <= r)
    {
        //Tree[V] = max(val, Tree[V]);
        return;
    }
    if (r <= L || R <= l)
        return;
}

long long Get(int l, int r, int L, int R, int V)
{
    if (l <= L && R <= r)
    {
        //return Tree[V];
    }
    if (r <= L || R <= l)
    {
        return 0;
    }
}

int n;
S s;

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> s;
    int smallest = 'z' + 1;
    for (int i = 0; i < s.size(); i++)
    {
        if (smallest < s[i])
        {
            cout << "Ann\n";
        }
        else
        {
            cout << "Mike\n";
        }
        smallest = min(smallest, (int)s[i]);
    }
}