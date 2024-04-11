#include <stdio.h>
#include <algorithm>
#include <math.h>
#include <vector>
#include <deque>
#include <string>
#include <string.h>
#include <queue>
#include <stdlib.h>
#include <set>

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
const ld PI = acosl(-1.);
using namespace std;

const int N = 111;
char w[N][N];
int n;

int x[N], y[N];


int main() {
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);

    scanf("%d\n", &n);
    for (int i = 0; i < n; ++i) {
        gets(w[i]);
    }

    memset(x, -1, sizeof(x));
    memset(y, -1, sizeof(y));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
           if (w[i][j] == '.') {
                x[i] = j;
                y[j] = i;
           }
        }
    }

    bool cx = true, cy = true;
    for (int i = 0; i < n; ++i) {
        if (x[i] == -1) cx = false;
        if (y[i] == -1) cy = false;
    }

    if (!cx && !cy) {
        puts("-1");
        return 0;
    }
    
    if (cx) {
        for (int i = 0; i < n; ++i) printf("%d %d\n", i + 1, x[i] + 1);
    } else {
        for (int i = 0; i < n; ++i) printf("%d %d\n", y[i] + 1, i + 1);
    }

    return 0;
}