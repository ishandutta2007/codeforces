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
const int M = (int)(1e5 + 239);
const int N = (int)(2e3 + 239);
const int L = 19;
const int T = (1 << 18);
const int B = (int)(trunc(sqrt(M)) + 1);
const int X = (int)(1e4 + 239);

int n;
ll x[M], y[M];

bool cmp(pair<ll, ll> a, pair<ll, ll> b)
{
    ll pr = (a.first * b.second - a.second * b.first);
    if (pr != 0)
        return (pr > 0);
    ld len1 = hypot(a.first, a.second);
    ld len2 = hypot(b.first, b.second);
    return (len1 < len2);
}

int main() {
#ifdef ONPC
    freopen("input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
        y[i] -= x[i] * x[i];
    }
    if (n == 1) {
        cout << "0";
        return 0;
    }
    int id = 0;
    for (int i = 1; i < n; i++)
        if (y[i] < y[id] || (y[i] == y[id] && x[i] < x[id]))
            id = i;
    vector<pair<ll, ll> > v;
    for (int i = 0; i < n; i++)
        if (i != id)
            v.push_back({x[i] - x[id], y[i] - y[id]});
    sort(v.begin(), v.end(), cmp);
    vector<pair<ll, ll> > st;
    st.push_back({0, 0});
    for (int i = 0; i < (int) v.size(); i++) {
        while ((int) st.size() >= 2) {
            pair<ll, ll> sti = st.back();
            pair<ll, ll> sti1 = st[(int) st.size() - 2];
            pair<ll, ll> a1 = {v[i].first - sti1.first, v[i].second - sti1.second};
            pair<ll, ll> a2 = {sti.first - sti1.first, sti.second - sti1.second};
            if (a1.first * a2.second >= a1.second * a2.first)
                st.pop_back();
            else
                break;
        }
        st.push_back(v[i]);
    }
    reverse(st.begin(), st.end());
    int idl = 0;
    for (int i = 1; i < (int) st.size(); i++)
        if (st[i].first < st[idl].first || (st[i].first == st[idl].first && st[i].second > st[idl].second))
            idl = i;
    int idr = 0;
    for (int i = 1; i < (int) st.size(); i++)
        if (st[i].first > st[idr].first || (st[i].first == st[idr].first && st[i].second > st[idr].second))
            idr = i;
    int ans = 0;
    for (int i = idl; i != idr; i = (i + 1) % (int)st.size())
        ans++;
    cout << ans;
    return 0;
}