#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <cstring>
#include <cstdio>
#include <cassert>
#include <queue>
#include <bitset>
#include <cmath>
#include <sstream>
#include <string>
#include <vector>

#define mp make_pair
#define pb push_back
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end()

using namespace std;

typedef pair<int, int> ii;
typedef long long int64;
typedef vector<int> vi;

template<class T> T abs(T x) {return x > 0 ? x : (-x); }
template<class T> T sqr(T x) {return x * x; }

const int maxn = 4200;

const int inf = 1000 * 1000 * 10;

int d[maxn][maxn];

int add(int l, ii p) {
    int x = max(p.first, l);
    return x + p.second;
}

int main()
{
    int n, k;
    cin >> n >> k;
    vector<ii> v(n);
    for (int i = 0; i < n; ++i)
        cin >> v[i].first >> v[i].second;

    sort(all(v));

    for (int i = 0; i <= n; ++i)
        for (int j = 0; j <= k; ++j)
            d[i][j] = inf;

    int res = 0;
    
    d[0][0] = 1;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= k; ++j) {
            d[i + 1][j] = min(d[i + 1][j], add(d[i][j], v[i]));
            d[i + 1][j + 1] = min(d[i + 1][j + 1], d[i][j]);
        }       
    }

    for (int i = 0; i <= n; ++i) {
        int ri = i;
        for (int j = k; j >= 0; --j) {
            int r = ri >= sz(v) ? 86401 : v[ri].first;
            res = max(res, r - d[i][j]);

            ++ri;
        }
    }

    cout << res << "\n";
    return 0;
}