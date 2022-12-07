#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
#include <algorithm>
#include <deque>
#include <iostream>
#include <map>
#include <cmath>
#include <memory.h>
#include <queue>
#include <set>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>

using namespace std;
typedef long long ll;
typedef long double ld;

const ld PI = acosl(-1.);

const int N = 100111;
int a[N];
int b[N];
ll f[N][2];
int n;

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", a + i);
    }
    sort(a, a + n);

    int k = 1;
    b[0] = 1;
    for (int i = 1; i < n; ++i)
        if (a[i] == a[k - 1]) {
            b[k - 1]++;
        } else {
            a[k++] = a[i];
            b[k - 1] = 1;
        }
    n = k;

    f[0][1] = ll(a[0]) * b[0];
    f[0][0] = 0;
    for (int i = 1; i < n; ++i) {
        f[i][1] = ll(a[i]) * b[i] + f[i - 1][0];
        if (a[i - 1] + 1 != a[i]) f[i][1] = max(f[i][1], ll(a[i]) * b[i] + f[i - 1][1]);
        f[i][0] = max(f[i - 1][0], f[i - 1][1]);
    }

    cout << max(f[n - 1][0], f[n - 1][1]) << endl;

    return 0;
}