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

const int inf = 1000 * 1000 * 1000;

const int dx[] = {-1, 0, 0, 1};
const int dy[] = {0, -1, 1, 0};

ii cross(int a1, int b1, int c1, int a2, int b2, int c2)
{
    int d = a1 * b2 - a2 * b1;
    int dx = c1 * b2 - c2 * b1;
    int dy = a1 * c2 - a2 * c1;
    return ii(dx / d, dy / d);
}

int main()
{
    int n;
    cin >> n;
    int m[4], M[4];
    for (int i = 0; i < 4; ++i)
        m[i] = inf, M[i] = -inf;
    for (int i = 0; i < n; ++i)
    {
        int x0, y0;
        scanf("%d%d", &x0, &y0);
        for (int dir = 0; dir < 4; ++dir)
        {
            int x = x0 + dx[dir], y = y0 + dy[dir];
            int t1 = x, t2 = y, t3 = x + y, t4 = x - y;
            m[0] = min(m[0], t1); M[0] = max(M[0], t1);
            m[1] = min(m[1], t2); M[1] = max(M[1], t2);
            m[2] = min(m[2], t3); M[2] = max(M[2], t3);
            m[3] = min(m[3], t4); M[3] = max(M[3], t4);
        }
    }
    vector<ii> v;
    v.pb(cross(1, 0, m[0], 1, -1, m[3]));
    v.pb(cross(1, -1, m[3], 0, 1, M[1]));
    v.pb(cross(0, 1, M[1], 1, 1, M[2]));
    v.pb(cross(1, 1, M[2], 1, 0, M[0]));
    v.pb(cross(1, 0, M[0], 1, -1, M[3]));
    v.pb(cross(1, -1, M[3], 0, 1, m[1]));
    v.pb(cross(0, 1, m[1], 1, 1, m[2]));
    v.pb(cross(1, 1, m[2], 1, 0, m[0]));

    int res = 0;
    for (int i = 0; i < sz(v); ++i)
    {
        int j = (i + 1) % sz(v);
        int x = abs(v[i].first - v[j].first);
        int y = abs(v[i].second - v[j].second);
        int dv = 1;
        if (x && y) ++dv;
        res += (x + y) / dv;
    }
    cout << res << "\n";
    return 0;
}