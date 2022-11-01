#include <cstdio>
#include <cassert>
#include <algorithm>
#include <cmath>
using namespace std;

// a1 ->, <- a2
int a1[100000], a2[100000];

bool check(int i, int j, int l, int wmax) {
    // pos = (a1[i] + a2[j]) / 2.0
    // time = (a2[j] - a1[i]) / 2.0 + l
    // abs(pos / time) <= wmax
    // abs(pos) <= wmax * time
    if (a1[i] > a2[j])
        return false;
    int pos2 = a1[i] + a2[j];
    int time2 = a2[j] - a1[i] + l * 2;
    return abs(pos2) < (long long) wmax * time2;
}

int main() {
    int n, l, wmax;
    scanf("%d %d %d", &n, &l, &wmax);

    int n1 = 0, n2 = 0;
    for (int i = 0; i < n; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        if (y == 1) {
            a1[n1++] = x + l;
        } else {
            a2[n2++] = x;
        }
    }

    sort(a1, a1 + n1);
    sort(a2, a2 + n2);

    long long int ans = 0;
    for (int i = 0, j = 0; i < n1; i++) {
        while (j < n2 && !check(i, j, l, wmax))
            j++;
        ans += n2 - j;
    }
    printf("%lld\n", ans);
}