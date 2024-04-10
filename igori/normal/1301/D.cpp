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
#define y1 y1337

const long long MOD = 998244353;

long long inq(long long x, long long y)
{
    if (y == 0) return 1;
    long long l = inq(x, y / 2);
    if (y % 2) return l * l % MOD * x % MOD;
    return l * l % MOD;
}

const long long INF = 1e14;

long long n, m, k;
vector<pair<int, string> > ans;

string to_string1(char c)
{
    if (c == 'D') return "D";
    if (c == 'L') return "L";
    if (c == 'R') return "R";
    if (c == 'U') return "U";
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> k;
    if (4 * n * m - 2 * m - 2 * n < k)
    {
        cout << "NO";
        return 0;
    }
    if (m == 1)
    {
        cout << "YES\n";
        cout << k << endl;
        for (int i = 0; i < n - 1 && k > 0; i++, k--) cout << "1 D\n";
        for (int i = 0; i < n - 1 && k > 0; i++, k--) cout << "1 U\n";
        return 0;
    }
    cout << "YES\n";
    for (int i = 0; i + 1 < n; i++)
    {
        if (i % 2 == 0)
        {
            ans.push_back({m - 1, "DUR"});
            ans.push_back({1, "D"});
        }
        else
        {
            ans.push_back({m - 1, "DUL"});
            ans.push_back({1, "D"});
        }
    }
    if ((n - 1) % 2 == 0) ans.push_back({m - 1, "R"});
    else ans.push_back({m - 1, "L"});
    for (int i = n - 1; i >= 0; i--)
    {
        if (i % 2 == 0)
        {
            ans.push_back({m - 1, "L"});
            if (i != 0) ans.push_back({1, "U"});
        }
        else
        {
            ans.push_back({m - 1, "R"});
            if (i != 0) ans.push_back({1, "U"});
        }
    }
    vector<pair<int, string> > ans2;
    for (int i = 0; i < ans.size(); i++)
    {
        if (ans[i].second.size() * ans[i].first <= k)
        {
            ans2.push_back(ans[i]);
            k -= ans[i].second.size() * ans[i].first;
        }
        else
        {
            int cnt = k / (int)ans[i].second.size();
            if (cnt != 0) ans2.push_back({cnt, ans[i].second});
            k -= cnt * ans[i].second.size();
            for (int j = 0; j < k; j++) ans2.push_back({1, to_string1(ans[i].second[j])});
            break;
        }
    }
    cout << ans2.size() << "\n";
    for (int i = 0; i < ans2.size(); i++)
    {
        cout << ans2[i].first << " " << ans2[i].second << "\n";
    }
}