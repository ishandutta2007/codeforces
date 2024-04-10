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

const int64 inf = (int64)(1E16);

map<ii, vi> M;
map<ii, int> Mcnt;

int gcd(int x, int y)
{
    if (!x) return y;
    if (!y) return x;
    return gcd(y, x % y);
}

int rev(int x)
{
    int y = 0;
    while (x) {
        y = y * 10 + x % 10;
        x /= 10;
    }
    return y;
}

int main()
{
    int mx, my, need;
    cin >> mx >> my >> need;
    int cur = 0;
    int cx = 1, cy = my;
    for (int i = 1; i <= my; ++i) {
        int j = rev(i);
        int x = i, y = j;
        int d = gcd(x, y);
        x /= d, y /= d;
        M[ii(x, y)].pb(i);
    }
    cur = 0;
    int64 res = inf;
    int rx = -1, ry = -1;
    for (; cx <= mx; ++cx) {
        {
            int ty = cx, tx = rev(cx);
            int d = gcd(ty, tx);
            tx /= d, ty /= d;
            cur += sz(M[ii(tx, ty)]);
            ++Mcnt[ii(tx, ty)];
        }
        while (cy > 1 && cur >= need) {
            int x = cy, y = rev(cy);
            int d = gcd(x, y);
            x /= d, y /= d;
            int delta = Mcnt[ii(x, y)];
            if (cur - delta < need) break;
            cur -= delta;
            M[ii(x, y)].pop_back();
            --cy;
        }
        if (cur >= need) {
            int64 r0 = ((int64)cx) * (int64)cy;
            if (res > r0)               
                res = r0, rx = cx, ry = cy;
        }
    }
    if (res == inf) printf("-1\n");
    else cout << rx << " " << ry << "\n";
    return 0;
}