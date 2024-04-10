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
const int MOD = 998244353; //1e9 + 7;
const ll MOD2 = (ll)MOD * (ll)MOD;

//random
mt19937_64 rnd(239); //(chrono::high_resolution_clock::now().time_since_epoch().count());

//constants
const int M = (int)(2e5 + 239);
const int N = (int)(2e3 + 239);
const int L = 20;
const int T = (1 << 19);
const int B = (int)(trunc(sqrt(M)) + 1);
const int X = 1e4 + 239;

vector<pair<ll, ll> > v;
int n;
ll t, unused;

multiset<ll> a1, a2;
ll sa, cur;

void add(ll x)
{
    if (x + sa <= cur)
    {
        a1.insert(x);
        sa += x;
        return;
    }
    if (!a1.empty())
    {
        auto it = a1.end();
        it--;
        if ((*it) > x)
        {
            sa -= (*it);
            a2.insert(*it);
            a1.erase(it);
            a1.insert(x);
            sa += x;
            return;
        }
    }
    a2.insert(x);
}

int can_kill(ll x)
{
    cur = x;
    while (!a2.empty())
    {
        auto it = a2.begin();
        if ((*it) + sa > cur)
            break;
        a1.insert(*it);
        sa += (*it);
        a2.erase(it);
    }
    return a1.size();
}

int main()
{
#ifdef ONPC
    freopen("input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> t >> unused;
    for (int i = 0; i < n - 1; i++)
    {
        ll a, b;
        cin >> a >> b;
        v.push_back(make_pair(a, b - a + 1));
    }
    sort(v.rbegin(), v.rend());
    sa = 0;
    cur = 0;
    int ans = 1;
    for (int i = 0; i < n - 1; i++)
        if (v[i].first > t)
            ans++;
    int st = 0;
    for (int i = 0; i < n - 1; i++)
        if (v[i].first <= t && (i == 0 || v[i - 1].first != v[i].first))
        {
            for (int x = st; x < i; x++)
                add(v[x].second);
            st = i;
            ll can = t - v[i].first;
            ans = min(ans, i + 1 - can_kill(can));
        }
    for (int x = st; x < n - 1; x++)
        add(v[x].second);
    ans = min(ans, n - can_kill(t));
    cout << ans;
    return 0;
}