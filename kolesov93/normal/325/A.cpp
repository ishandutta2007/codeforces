#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <deque>
#include <string>
#include <string.h>
#include <queue>
#include <stdlib.h>
#include <set>

using namespace std;

int main() {
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);

    int n;
    cin >> n;

    typedef long long ll;

    ll minx, maxx, miny, maxy;
    ll sq;

    cin >> minx >> miny >> maxx >> maxy;
    sq = (maxx - minx) * (maxy - miny);
    n--;
    while (n--) {
        ll x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        sq += (y2 - y1) * (x2 - x1);

        minx = min(minx, x1);
        maxx = max(maxx, x2);
        miny = min(miny, y1);
        maxy = max(maxy, y2);
    }

    if (sq == (maxy - miny) * (maxx - minx) && maxx - minx == maxy - miny) {
        puts("YES");
        return 0;
    }
    puts("NO");

    return 0;
}