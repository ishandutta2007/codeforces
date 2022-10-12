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

const long long inf = 1e18;
const long long infsmart = 1e12;

ll n, k;
ll erato[1200000];

ll phi(int x)
{
    int Phi = x;
    int last = 1000001;
    while (x > 1)
    {
        if (erato[x] != last)
        {
            last = erato[x];
            Phi = Phi * (erato[x] - 1) / erato[x];
        }
        x /= erato[x];
    }
    return Phi;
}

vector<long long> kek, lol;

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    for (int i = 2; i <= 1000000; i++)
    {
        if (erato[i] == 0)
        {
            for (int j = 1; j * i <= 1000000; j++)
            {
                erato[i * j] = i;
            }
        }
    }
    cin >> n >> k;
    long long ans = 0;
    for (int i = 3; i <= n; i++)
    {
        if (i % 2 == 0)
        {
            lol.push_back(phi(i));
        }
        else
        {
            kek.push_back(phi(i));
        }
    }
    sort(all(kek));
    sort(all(lol));
    long long i = 0, j = 0;
    for (; k > 0; k--)
    {
        int val1 = 1e9, val2 = 1e9;
        if (i < kek.size())
            val1 = kek[i];
        if (j < lol.size())
            val2 = lol[j];
        if (j == 0) val2++;
        if (val1 <= val2)
            i++;
        else
            j++;
        ans += min(val1, val2);
    }
    cout << ans + 1;
}