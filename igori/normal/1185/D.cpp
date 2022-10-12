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
using std::min;
using std::max;

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
ll n;
vector<pii> a;

bool ok(vector<int> vv)
{
    sort(all(vv));
    if (vv.size() <= 2)
    {
        return 1;
    }
    for (int i = 0; i + 1 < vv.size(); i++)
    {
        if (vv[i + 1] - vv[i] != vv[1] - vv[0])
            return 0;
    }
    return 1;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        a.push_back({x, i + 1});
    }
    sort(all(a));
    if (n <= 10)
    {
        for (int i = 0; i < n; i++)
        {
            vector<int> g;
            for (int j = 0; j < n; j++)
            {
                if (i != j)
                {
                    g.push_back(a[j].first);
                }
            }
            if (ok(g))
            {
                cout << a[i].second;
                return 0;
            }
        }
        cout << -1;
        return 0;
    }
    map<int, int> mm;
    int checks = 10;
    for (int i = 0; i + 1 < n; i++)
    {
        mm[a[i + 1].first - a[i].first]++;
        if (mm[a[i + 1].first - a[i].first] == 1 && checks > 0)
        {
            vector<int> g1, g2;
            for (int j = 0; j < n; j++)
            {
                if (j != i)
                    g1.push_back(a[j].first);
                if (j != i + 1)
                    g2.push_back(a[j].first);
            }
            if (ok(g1))
            {
                cout << a[i].second;
                return 0;
            }
            if (ok(g2))
            {
                cout << a[i + 1].second;
                return 0;
            }
            checks--;
        }
    }
    cout << -1;
    return 0;
}