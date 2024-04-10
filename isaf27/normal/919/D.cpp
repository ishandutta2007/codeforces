#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <ctime>
#include <vector>
#include <queue>
#include <bitset>
#include <cmath>
#include <time.h>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <stdlib.h>
#include <deque>
#include <iomanip>
#include <complex>

using namespace std;

typedef long long ll;
typedef long double ld;

#define TIME (clock() * 1.0 / CLOCKS_PER_SEC)
#define rand_int ((rand() << 15) | rand())

const ld pi = 3.1415926535897932384626433832795;
const ld eps = 1e-10;
const ll prime = 239;
const ll MOD = 1e9 + 7;
const ll INF = 1e18;
const int BIG = 1e9 + 239;
const int MAX_N = 3 * 1e5 + 1;
const int MAX_T = (1 << 18);
const int MAX_LOG = 19;
const int dx[4] = {0, -1, 0, 1};
const int dy[4] = {-1, 0, 1, 0};
const int two = 2;
const int alf = 26;

vector<vector<int> > v(MAX_N);
string s;
bool used[MAX_N];
int n, m, to[MAX_N], color[MAX_N], dp[alf][MAX_N];
vector<int> topsort;

void dfs(int p)
{
    used[p] = 1;
    color[p] = 1;
    for (int i : v[p])
    {
        if (color[i] == 1)
        {
            cout << -1;
            exit(0);
        }
        if (color[i] == 2)
            continue;
        dfs(i);
    }
    color[p] = 2;
    topsort.push_back(p);
}

int main()
{
    #ifndef ONLINE_JUDGE //*
    #define fname "test"
    freopen(fname".in", "r", stdin);
    freopen(fname".out", "w", stdout);/**/
    #endif
    cin.sync_with_stdio(0);
    cin >> n >> m >> s;
    memset(to, 0, sizeof(to));
    for (int i = 0; i < m; i++)
    {
        int x, f;
        cin >> x >> f;
        x--, f--;
        if (x == f)
        {
            cout << -1;
            return 0;
        }
        to[f]++;
        v[x].push_back(f);
    }
    memset(used, 0, sizeof(used));
    memset(color, 0, sizeof(color));
    for (int i = 0; i < n; i++)
        if (to[i] == 0 && color[i] == 0)
            dfs(i);
    reverse(topsort.begin(), topsort.end());
    if (topsort.size() != n)
    {
        cout << -1;
        return 0;
    }
    memset(dp, 0, sizeof(dp));
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int x = topsort[i];
        //cerr << x << "\n";
        dp[s[x] - 'a'][x]++;
        for (int c = 0; c < alf; c++)
            ans = max(ans, dp[c][x]);
        for (int t : v[x])
            for (int c = 0; c < alf; c++)
                dp[c][t] = max(dp[c][t], dp[c][x]);
    }
    cout << ans;
    return 0;
}