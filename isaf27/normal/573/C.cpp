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

int n, deg[M], used[M], c = 0;
vector<int> v[M];

bool dfs(int p)
{
    if (deg[p] > 2)
        return false;
    used[p] = c;
    for (int i : v[p])
        if (used[i] != c)
            return dfs(i);
}

int main() {
#ifdef ONPC
    freopen("input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        int s, f;
        cin >> s >> f;
        s--, f--;
        deg[s]++;
        deg[f]++;
        v[s].push_back(f);
        v[f].push_back(s);
    }
    for (int i = 0; i < n; i++)
    {
        if (deg[i] <= 2) continue;
        int kol = 0;
        for (int j : v[i])
        {
            if (deg[j] >= 4)
            {
                kol++;
                continue;
            }
            c++;
            used[i] = c;
            used[j] = c;
            bool ch = true;
            for (int x : v[j])
                if (used[x] != c && !dfs(x))
                    ch = false;
            if (!ch)
                kol++;
        }
        if (kol > 2)
        {
            cout << "No";
            return 0;
        }
    }
    cout << "Yes";
    return 0;
}