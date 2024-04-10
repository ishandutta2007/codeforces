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

void solve()
{
    int n;
    cin >> n;
    int ans = 0;
    for (int i = 0; (1 << i) < n; i++)
    {
        vector<int> s;
        vector<int> f;
        for (int x = 0; x < n; x++)
        {
            if ((x >> i) & 1)
                s.push_back(x);
            else
                f.push_back(x);
        }
        cout << (int)s.size() << " " << (int)f.size() << " ";
        for (int x : s)
            cout << x + 1 << " ";
        for (int x : f)
            cout << x + 1 << " ";
        cout << endl;
        int now;
        cin >> now;
        if (now == -1)
            exit(0);
        ans = max(ans, now);
    }
    cout << "-1 " << ans << endl;
}

int main()
{
#ifdef ONPC
    //freopen("input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}