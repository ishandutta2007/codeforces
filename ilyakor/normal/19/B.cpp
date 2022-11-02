#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <cstring>
#include <cstdio>
#include <cassert>
#include <queue>
#include <bitset>
//#include <cmath>
#include <sstream>
#include <string>
#include <vector>

#define pb push_back
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end()

using namespace std;

typedef pair<int, int> ii;
typedef long long int64;
typedef vector<int> vi;

template<class T> T abs(T x) {return x > 0 ? x : (-x); }
template<class T> T sqr(T x) {return x * x; }

const int maxn = 3000;
const int64 inf = 10000000000000000LL;

int64 d[2][2 * maxn + 100];

int main()
{
    for (int i = 0; i < 2 * maxn; i++)
        d[0][i] = inf;
    d[0][maxn] = 0;
    int n;
    cin >> n;
    for (int it = 0; it < n; it++)
    {
        int ti, ci;
        cin >> ti >> ci;
        int cur = (it + 1) % 2, prev = it % 2;
        for (int i = 0; i < 2 * maxn; i++)
            d[cur][i] = inf;
        for (int i = 0; i < 2 * maxn; i++)
        {
            if (d[prev][i] == inf) continue;
            {
                int i0 = i + ti;
                if (i0 < 0 || i0 >= 2 * maxn) continue;
                d[cur][i0] = min(d[cur][i0], d[prev][i] + ci);
            }
            {
                int i0 = i - 1;
                if (i0 < 0 || i0 >= 2 * maxn) continue;
                d[cur][i0] = min(d[cur][i0], d[prev][i]);
            }
        }
    }
    int64 res = inf;
    for (int i = 0; i < maxn; i++)
        res = min(res, d[n % 2][maxn + i]);
    cout << res << "\n";
    return 0;
}