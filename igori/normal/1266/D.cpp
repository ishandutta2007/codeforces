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
int n, m;
int a[500000];
vector<pair<int, int> > give;
vector<pair<int, int> > rget;
vector<pair<pii, int> > ans;

int f1(int i)
{
    return give[i].first;
}
int f2(int j)
{
    re rget[j].first;
}

signed main()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        long long v, u, d;
        cin >> v >> u >> d;
        v--, u--;
        a[v] -= d;
        a[u] += d;
    }
    for (int i = 0; i < n; i++)
    {
        if (a[i] < 0) give.push_back({i, -a[i]});
        if (a[i] > 0) rget.push_back({i, a[i]});
    }
    for (int i = 0, j = 0; ; )
    {
        if (i == give.size() && j == rget.size()) break;
        if (give[i].second == rget[j].second)
        {
            ans.push_back({{f1(i), f2(j)}, give[i].second});
            i++, j++;
        }
        else
        {
            if (give[i].second > rget[j].second)
            {
                ans.push_back({{f1(i), f2(j)}, rget[j].second});
                give[i].second -= rget[j].second;
                j++;
            }
            else
            {
                ans.push_back({{f1(i), f2(j)}, give[i].second});
                rget[j].second -= give[i].second;
                i++;
            }
        }
    }
    int cnt = 0;
    for (int i = 0; i < ans.size(); i++) if (ans[i].second != 0) cnt++;
    cout << cnt << "\n";
    for (int i = 0; i < ans.size(); i++)
    {
        if (ans[i].second != 0)
        {
            cout << ans[i].first.first + 1 << " " << ans[i].first.second + 1 << " " << ans[i].second << "\n";
        }
    }
}