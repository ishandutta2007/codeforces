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

const int N = 2949;
const int INF = N * N;

int n, m;
string s[5000];
int cx[4] = {0, 1, 0, -1};
int cy[4] = {1, 0, -1};
int cnt[N][N];

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> s[i];
    vector<pii> q;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (s[i][j] == '.')
            {
                int c = 0;
                for (int k = 0; k < 4; k++)
                {
                    int nx = i + cx[k];
                    int ny = j + cy[k];
                    if (0 <= nx && nx < n && 0 <= ny && ny < m)
                    {
                        if (s[nx][ny] == '.') c++;
                    }
                }
                //cout << c << " " << i << " " << j << endl;
                if (c == 1) q.push_back({i, j});
                cnt[i][j] = c;
            }
        }
    }
    for (int ii = 0; ii < q.size(); ii++)
    {
        pii b = q[ii];
        int sk = -1;
        int i = b.fi;
        int j = b.se;
        if (s[i][j] != '.')
        {
            continue;
        }
        for (int k = 0; k < 4; k++)
        {
            int nx = i + cx[k];
            int ny = j + cy[k];
            int c = 0;
            if (0 <= nx && nx < n && 0 <= ny && ny < m)
            {
                if (s[nx][ny] == '.')
                {
                    sk = k;
                    break;
                }
            }
        }
        if (sk == -1)
        {
            cout << "Not unique";
            return 0;
        }
        if (sk == 0)
        {
            s[i][j] = '<';
            s[i][j + 1] = '>';
        }
        if (sk == 1)
        {
            s[i][j] = '^';
            s[i + 1][j] = 'v';
        }
        if (sk == 2)
        {
            s[i][j] = '>';
            s[i][j - 1] = '<';
        }
        if (sk == 3)
        {
            s[i][j] = 'v';
            s[i - 1][j] = '^';
        }
        i = i + cx[sk];
        j = j + cy[sk];
        for (int k = 0; k < 4; k++)
        {
            int nx = i + cx[k];
            int ny = j + cy[k];
            if (0 <= nx && nx < n && 0 <= ny && ny < m)
            {
                if (s[nx][ny] == '.')
                {
                    cnt[nx][ny]--;
                    if (cnt[nx][ny] == 1) q.push_back({nx, ny});
                }
            }
        }
    }
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++)
    {
        if (s[i][j] == '.')
        {
            cout << "Not unique";
            return 0;
        }
    }
    for (int i = 0; i < n; i++) cout << s[i] << "\n";
}