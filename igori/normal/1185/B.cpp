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

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string s, t;
        cin >> s >> t;
        if (s.size() > t.size())
        {
            cout << "NO\n";
            continue;
        }
        int res = 1;
        for (int j1 = 0, j2 = 0; j1 < s.size();)
        {
            if (j2 >= t.size())
            {
                res = 0;
                break;
            }
            if (t[j2] != s[j1])
            {
                res = 0;
                break;
            }

            char c = s[j1];
            int cnt1 = 0, cnt2 = 0;
            while (j1 < s.size() && s[j1] == c)
            {
                cnt1++;
                j1++;
            }

            while (j2 < t.size() && t[j2] == c)
            {
                cnt2++;
                j2++;
            }
            if (cnt1 > cnt2)
            {
                res = 0;
                break;
            }
            if (j1 == s.size() && j2 != t.size())
            {
                res = 0;
                break;
            }
        }
        if (res == 1)
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }
}