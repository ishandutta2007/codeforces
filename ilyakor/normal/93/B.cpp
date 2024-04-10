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

int main()
{
    int n, w, m;
    cin >> n >> w >> m;
    for (int x = 0; x < n; ++x) {
        bool ok = true;
        for (int i = 0; i < n; ++i)
            if ((x + (i + 1) * m - 1) / n - (x + i * m) / n >= 2) {
                ok = false;
                break;
            }
        if (!ok) continue;
        printf("YES\n");
        vector<vi > v(m);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                int cur = x + i * m + j;
                cur /= n;
                cur %= m;
                v[cur].pb(i);
            }
        }
        for (int i = 0; i < m; ++i) {
            sort(all(v[i]));
            map<int, int> M;
            for (int j = 0; j < sz(v[i]); ++j)
                ++M[v[i][j]];
            for (map<int, int>::iterator it = M.begin(); it != M.end(); ++it) {
                int x = it->first;
                double y = it->second;
                y /= m;
                y *= w;
                printf("%d %.10lf ", x + 1, y);
            }
            printf("\n");
        }
        return 0;
    }
    printf("NO\n");
    return 0;
}