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
const ll MOD = 1e9 + 7;
ll n, m;
ll wants[(1 << 9)];
ll covers[(1 << 9)];

ll minC[(1 << 9)];
ll num[(1 << 9)];

vector<pair<ll, ll> > cost_num;

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        int k;
        cin >> k;
        int mask = 0;
        for (int j = 0; j < k; j++)
        {
            int a;
            cin >> a;
            a--;
            mask += (1 << a);
        }
        wants[mask]++;
    }
    for (int mask = 0; mask < (1 << 9); mask++)
    {
        minC[mask] = 1e18;
        for (int sub = 0; sub < (1 << 9); sub++)
        {
            if ((sub & mask) == sub)
                covers[mask] += wants[sub];
        }
    }
    for (int i = 0; i < m; i++)
    {
        long long cost = 0;
        cin >> cost;
        int k;
        cin >> k;
        int mask = 0;
        for (int j = 0; j < k; j++)
        {
            int a;
            cin >> a;
            a--;
            mask += (1 << a);
        }
        if (cost < minC[mask])
        {
            minC[mask] = cost;
            num[mask] = i;
        }
        cost_num.push_back({cost, i});
    }
    sort(all(cost_num));
    ll poradovat = 0, cost = 1e18, id1 = 0, id2 = 0;
    for (int i = 0; i < (1 << 9); i++)
    {
        for (int j = 0; j < (1 << 9); j++)
        {
            if (i == j)
                continue;
            long long mask = (i | j);
            long long p = covers[mask];
            long long c = minC[i] + minC[j];
            if (c >= 3000000000)
                continue;
            if (p > poradovat)
            {
                poradovat = p;
                cost = c;
                id1 = num[i];
                id2 = num[j];
            }
            if (p == poradovat && c < cost)
            {
                cost = c;
                id1 = num[i];
                id2 = num[j];
            }
        }
    }
    for (int i = 0; i < (1 << 9); i++)
    {
        long long p = covers[i];
        long long c = minC[i];
        long long id = num[i];
        long long Sid = 0;
        for (int j = 0; j < cost_num.size(); j++)
        {
            if (cost_num[j].second != id)
            {
                c += cost_num[j].first;
                Sid = cost_num[j].second;
                break;
            }
        }
        if (c >= 3000000000)
        {
            continue;
        }
        if (p > poradovat)
        {
            poradovat = p;
            cost = c;
            id1 = num[i];
            id2 = Sid;
        }
        if (p == poradovat && c < cost)
        {
            cost = c;
            id1 = num[i];
            id2 = Sid;
        }
    }
    cout << id1 + 1 << " " << id2 + 1;
}