#include <algorithm>
#include <deque>
#include <iostream>
#include <map>
#include <math.h>
#include <memory.h>
#include <queue>
#include <set>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <time.h>
#include <vector>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef unsigned int uint;

const ld PI = acosl(-1.);

int main() {
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);

    int n;
    int ans = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j) {
            int x; scanf("%d", &x);
            if (i == j && x)
                ans += 1;
        }
    ans &= 1;

    int q;
    scanf("%d", &q);
    while (q--) {
        int t; scanf("%d", &t);
        if (t == 3) {
            if (ans) putchar('1');
            else putchar('0');
        } else {
            int y; scanf("%d", &y);
            ans ^= 1;
        }
    }

    puts("");
    
    return 0;
}