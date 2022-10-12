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
ll n, m;
string s[5000];

void solve()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
    }
    vector<pair<int, int> > fm(26);
    vector<pair<int, int> > lm(26);
    for (int i = 0; i < 26; i++)
    {
        fm[i] = {10000, 10000};
        lm[i] = {-1, -1};
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            pair<int, int> d = {i, j};
            if (s[i][j] == '.') continue;
            fm[s[i][j] - 'a'] = min(fm[s[i][j] - 'a'], d);
            lm[s[i][j] - 'a'] = max(lm[s[i][j] - 'a'], d);
        }
    }
    for (int i = 1; i < 26; i++)
    {
        pair<int, int> c14 = {-1, -1};
        for (int j = 0; j < i; j++)
        {
            if (lm[j] == c14 && lm[i] != c14)
            {
                lm[j] = lm[i];
                fm[j] = fm[i];
            }
        }
    }
    vector<int> example[5000];
    vector<int> my[5000];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (s[i][j] != '.')
                example[i].push_back(s[i][j] - 'a');
            else
                example[i].push_back(-1);
            my[i].push_back(-1);
        }
    }
    int t = 1;
    long long cnt = 0;
    for (int c = 0; c < 26; c++)
    {
        pair<int, int> c14 = {-1, -1};
        if (lm[c] == c14)
        {
            break;
        }
        cnt++;
        if (fm[c].first == lm[c].first)
        {
            for (int j = fm[c].second; j <= lm[c].second; j++)
            {
                my[fm[c].first][j] = c;
            }
        }
        else
        {
            if (fm[c].second == lm[c].second)
            {
                for (int i = fm[c].first; i <= lm[c].first; i++)
                {
                    my[i][fm[c].second] = c;
                }
            }
            else
            {
                t = 0;
                break;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (example[i][j] != my[i][j])
                t = 0;
        }
    }
    if (t)
    {
        cout << "YES\n";
        cout << cnt << "\n";
        for (int i = 0; i < cnt; i++)
        {
            cout << fm[i].first + 1 << " " << fm[i].second + 1 << " " << lm[i].first + 1 << " " << lm[i].second + 1 << "\n";
        }
    }
    else
        cout << "NO\n";
    return;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        solve();
    }
}