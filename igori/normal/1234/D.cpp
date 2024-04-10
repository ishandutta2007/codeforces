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

namespace MySpace{

};

#define F(i, n) for (int (i) = 0; (i) != (n); (i)++)
#define fi first
#define se second
#define re return
#define all(x) (x).begin(), (x).end()

int q;
set<int> pos[26];

void solve()
{
    string s;
    cin >> s;
    cin >> q;
    for (int i = 0; i < s.size(); i++)
    {
        pos[s[i] - 'a'].insert(i);
    }
    for (int i = 0; i < 26; i++)
    {
        pos[i].insert(s.size());
    }
    while (q--)
    {
        int t;
        cin >> t;
        if (t == 2)
        {
            int a, b;
            cin >> a >> b;
            a--, b--;
            a--;
            int res = 0;
            for (int i = 0; i < 26; i++)
            {
                if (pos[i].size() == 0)
                    continue;
                auto it1 = pos[i].upper_bound(a);
                auto it2 = pos[i].upper_bound(b);
                //cout << "KEK" << endl;
                int x1 = *it1;
                int x2 = *it2;
                //cout << "LOL" << endl;
                if (x1 != x2)
                    res++;
            }
            cout << res << "\n";
        }
        else
        {
            int a;
            char d;
            cin >> a >> d;
            a--;
            pos[s[a] - 'a'].erase(a);
            s[a] = d;
            pos[s[a] - 'a'].insert(a);
        }
    }
}

signed main()
{
    srand(time(NULL));
    //freopen("", "r", stdin);
    //freopen("", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int TESTCASES = 1;
    while (TESTCASES--)
    {
        solve();
    }
}