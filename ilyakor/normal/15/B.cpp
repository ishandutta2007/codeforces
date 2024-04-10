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

int64 get(int64 l, int64 r)
{
    return max(0LL, r - l + 1);
}

int64 cross(int64 x1, int64 y1, int64 x2, int64 y2)
{
    return max(0LL, min(y1, y2) - max(x1, x2) + 1LL);
}

int64 cross(int64 x11, int64 y11, int64 x12, int64 y12, int64 x21, int64 y21, int64 x22, int64 y22)
{
    return cross(x11, x12, x21, x22) * cross(y11, y12, y21, y22);
}

int main()
{
    int nc;
    cin >> nc;
    for (int it = 0; it < nc; it++)
    {
        int64 n, m, x1, y1, x2, y2;
        cin >> n >> m >> x1 >> y1 >> x2 >> y2;
        x2 -= x1, y2 -= y1;
        int64 dx = x2, dy = y2;
        dx = abs(dx), dy = abs(dy);
        /*int64 res = 0;
        res += get(n - dx + 1, dx) * m;
        res += get(m - dy + 1, dy) * n;
        res += dx * dy * 2LL;
        res -= (get(n - dx + 1, dx) + get(m - dy + 1, dy))* (dx + dy);
        res += get(n - dx + 1, dx) * get(m - dy + 1, dy);
        cout << res << "\n";*/
        int64 rx = dx, ry = dy;
        int64 lx = n - dx, ly = m - dy;
        int64 res = n * m - lx * ly - (n - rx) * (m - ry) + cross(0, 0, lx - 1, ly - 1, rx, ry, n - 1, m - 1);
        cout << res << "\n";
    }
    return 0;
}