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
typedef double ld;
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
const int X = 1e4 + 239;

int n, a[M], b[M], ans = 0;
set<pair<int, int> > l, r;

int main() {
#ifdef ONPC
    freopen("input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
    {
        if (i == 0 || i == n - 1)
        {
            b[i] = 0;
            continue;
        }
        b[i] = a[i];
        if (a[i - 1] < a[i])
            b[i] = min(a[i - 1] + 1, b[i]);
        if (a[i + 1] < a[i])
            b[i] = min(a[i + 1] + 1, b[i]);
        b[i]--;
    }
    //for (int i = 0; i < n; i++)
    //    cerr << b[i] << " ";
    for (int i = 0; i < n; i++)
        r.insert({i + b[i], i});
    for (int i = 0; i < n; i++)
    {
        r.erase({i + b[i], i});
        l.insert({b[i] - i, i});
        int now = n;
        if (!l.empty())
            now = min(now, l.begin()->first + i);
        if (!r.empty())
            now = min(now, r.begin()->first - i);
        //cerr << i + 1 << " " << now << "!\n";
        ans = max(ans, now + 1);
    }
    cout << ans;
    return 0;
}