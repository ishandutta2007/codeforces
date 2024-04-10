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

namespace MySpace{

};

#define forn(i, n) for (int (i) = 0; (i) != (n); (i)++)

ll n;
string s[400];
int a[200][200];
vector<int> g[500];
int In[200];
int Out[200];
int tm = 1;
int ins[200];

void dfs(int x)
{
    if (In[x] != 0)
        return;
    In[x] = tm++;
    for (int i = 0; i < g[x].size(); i++)
    {
        int j = g[x][i];
        dfs(j);
    }
    Out[x] = tm++;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("", "r", stdin);
    freopen("", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
    }
    for (int i = 0; i < 200; i++) for (int j = 0; j < 200; j++) a[i][j] = 10000000;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int ch = -1;
            for (int k = 0; k < min(s[i].size(), s[j].size()); k++)
            {
                if (s[i][k] != s[j][k])
                {
                    ch = k;
                    break;
                }
            }
            if (ch == -1)
            {
                if (s[i].size() > s[j].size())
                {
                    cout << "Impossible";
                    return 0;
                }
            }
            else
            {
                a[s[i][ch]][s[j][ch]] = 1;
                g[s[i][ch]].push_back(s[j][ch]);
                ins[s[j][ch]]++;
                //cout << s[i][ch] << " " << s[j][ch] << endl;
            }
        }
    }
    for (int k = 0; k < 200; k++)
    {
        for (int i = 0; i < 200; i++)
        {
            for (int j = 0; j < 200; j++)
            {
                a[i][j] = min(a[i][j], a[i][k] + a[k][j]);
            }
        }
    }
    for (int i = 0; i < 200; i++)
    {
        if (a[i][i] < 10000000)
        {
            cout << "Impossible";
            return 0;
        }
    }
    for (int i = 0; i < 200; i++)
    {
        if (ins[i] == 0)
            dfs(i);
    }
    vector<pair<int, int> > ts;
    for (int i = 'a'; i <= 'z'; i++)
    {
        ts.push_back({-Out[i], i});
    }
    sort(ts.begin(), ts.end());
    for (int i = 0; i < 26; i++)
    {
        cout << (char)ts[i].second;
    }
}