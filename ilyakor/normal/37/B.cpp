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
#define mp make_pair
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end()

using namespace std;

typedef pair<int, int> ii;
typedef long long int64;
typedef vector<int> vi;

template<class T> T abs(T x) {return x > 0 ? x : (-x); }
template<class T> T sqr(T x) {return x * x; }

const int maxn = 2000;

int n, m, r;

int d[maxn], p[maxn], u[maxn];

int main()
{
    cin >> n >> m >> r;
    for (int i = 0; i < n; ++i)
    {
        cin >> p[i] >> d[i];
    }
    int cur = m;
    int dps = 0;
    int res = 0;
    vector<ii> v;
    while (cur > 0)
    {
        cur -= dps;
        cur += r;
        cur = min(cur, m);
        if (cur <= 0) break;
        int opt = -1, ov = -1;
        for (int i = 0; i < n; ++i)
        {
            if (u[i]) continue;
            if (cur * 100 > m * p[i]) continue;
            if (d[i] > ov)
                ov = d[i], opt = i;
        }
        if (opt == -1)
        {
            if (dps <= r)
            {
                printf("NO\n");
                return 0;
            }
        }
        else
        {
            v.pb(ii(res, opt));
            dps += ov;
            u[opt] = true;
        }
        ++res;
    }
    cout << "YES\n";
    cout << res << " " << sz(v) << "\n";
    for (int i = 0; i < sz(v); ++i)
        printf("%d %d\n", v[i].first, v[i].second + 1);
    return 0;
}