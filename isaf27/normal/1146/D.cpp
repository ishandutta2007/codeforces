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
#include <iomanip>
#include <cassert>

using namespace std;

//defines
typedef long long ll;
typedef long double ld;
#define TIME clock() * 1.0 / CLOCKS_PER_SEC
#define prev kekekekek

//permanent constants
const ld pi = acos(-1.0);
const int day[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
const int digarr[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};
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
const int MOD = 998244353; //1e9 + 7;
const ll MOD2 = (ll)MOD * (ll)MOD;

//random
mt19937 rnd(239); //(chrono::high_resolution_clock::now().time_since_epoch().count());

//constants
const int M = (int)(2e5 + 239);
const int N = (int)(2e3 + 239);
const int L = 20;
const int T = (1 << 19);
const int B = (int)(trunc(sqrt(M)) + 1);
const int X = 110;

int m, a, b, g, k, d[M];
vector<pair<int, int> > v[M];

int main()
{
#ifdef ONPC
    freopen("input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> m >> a >> b;
    g = gcd(a, b);
    k = max(a, b) * 2;
    //k = 1000;
    for (int i = 0; i <= k; i++)
        if (i + a <= k)
            v[i].push_back(make_pair(i + a, i + a));
    for (int i = 0; i <= k; i++)
        if (i >= b)
            v[i].push_back(make_pair(i, i - b));
    for (int i = 0; i <= k; i++)
        sort(v[i].begin(), v[i].end());
    set<pair<int, int> > q;
    for (int i = 0; i <= k; i++)
    {
        if (i == 0)
            d[i] = 0;
        else
            d[i] = k + 100;
        q.insert(make_pair(d[i], i));
    }
    while (!q.empty())
    {
        int p = q.begin()->second;
        q.erase(q.begin());
        for (pair<int, int> t : v[p])
        {
            int i = t.second;
            int w = t.first;
            if (max(w, d[p]) < d[i])
            {
                q.erase(make_pair(d[i], i));
                d[i] = max(w, d[p]);
                q.insert(make_pair(d[i], i));
            }
        }
    }
    ll ans = 0;
    for (int i = 0; i <= k; i++)
        if (i % g == 0)
            ans += max(0, m - d[i] + 1);
    k = ((k + g) / g) * g;
    if (k <= m)
    {
        ll l = k;
        ll r = (m / g) * g;
        ans += (ll)(m + 1) * (1LL + ((r - l) / (ll)g));
        l /= g;
        r /= g;
        ll sum = (r * (r + 1)) / 2LL;
        sum -= (l * (l - 1)) / 2LL;
        sum *= (ll)g;
        ans -= sum;
    }
    cout << ans;
    return 0;
}