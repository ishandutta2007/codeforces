#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <random>

using namespace std;

//defines
typedef long long ll;
typedef long double ld;
#define TIME clock() * 1.0 / CLOCKS_PER_SEC

//permanent constants
const ld pi = acos(-1.0);
const int day[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
const int digarr[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};
const int dxo[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
const int dyo[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
const int alf = 26;
const int dig = 10;
const int two = 2;
const int th = 3;
const ll prost = 239;
const ll bt = 31;
const ld eps = 1e-8;
const ll INF = (ll)(1e18 + 239);
const int BIG = (int)(1e9 + 239);
const ll MOD = 998244353; //1e9 + 7;
const ll MOD2 = (ll)MOD * (ll)MOD;

//random
mt19937_64 rnd(239); //(chrono::high_resolution_clock::now().time_since_epoch().count());

//constants
const int M = (int)(2e5 + 239);
const int N = (int)(2e3 + 239);
const int L = 19;
const int T = (1 << 18);
const int B = (int)(trunc(sqrt(M)) + 1);
const int X = (int)(1e4 + 239);

int n, m, q, p[M], a[M], last[M], pos[M], st[M], to[M];
vector<int> v[M];

void dfs(int p, int h)
{
    st[h] = p;
    if (h >= n - 1)
        to[p] = st[h - n + 1];
    else
        to[p] = m;
    for (int i : v[p])
        dfs(i, h + 1);
}

int main()
{
#ifdef ONPC
    freopen("input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m >> q;
    for (int i = 0; i < n; i++)
    {
        cin >> p[i];
        p[i]--;
    }
    for (int i = 0; i < m; i++)
    {
        cin >> a[i];
        a[i]--;
    }
    for (int i = 0; i < n; i++)
        pos[p[i]] = i;
    for (int i = 0; i < n; i++)
        last[i] = m;
    for (int i = m - 1; i >= 0; i--)
    {
        int nx = p[(pos[a[i]] + 1) % n];
        v[last[nx]].push_back(i);
        last[a[i]] = i;
    }
    dfs(m, 0);
    for (int i = m - 1; i >= 0; i--)
        to[i] = min(to[i], to[i + 1]);
    string ans = "";
    for (int i = 0; i < q; i++)
    {
        int l, r;
        cin >> l >> r;
        l--, r--;
        ans += (char)('0' + (char)(to[l] <= r));
    }
    cout << ans;
    return 0;
}