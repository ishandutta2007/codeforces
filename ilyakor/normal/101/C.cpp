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

#define x1 x3982098543
#define y1 y3982098543

int64 x1, y1, x2, y2, x3, y3;

bool check(int64 X, int64 Y) {
    int64 d = sqr(x3) + sqr(y3);
    int64 dx = X * x3 + Y * y3;
    int64 dy = x3 * Y - y3 * X;
    if (d == 0) {
        if (dx == 0 && dy == 0 && X == 0 && Y == 0)
            return true;
        else
            return false;
    } else {
        if (dx % d == 0 && dy % d == 0)
            return true;
        else
            return false;
    }
}

int main()
{
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    for (int it = 0; it < 8; ++it) {
        int64 X = x2 - x1, Y = y2 - y1;
        if (check(X, Y)) {
            printf("YES\n");
            return 0;
        }
        int64 x = y1, y = -x1;
        x1 = x, y1 = y;
    }
    printf("NO\n");
    
    return 0;
}