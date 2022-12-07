#include <iostream>
#include <cstdio>

using namespace std;

const int N = 200222;
int w[N], h[N];

int main() {
    int n;
    scanf("%d", &n);

    int sumw = 0;
    int maxh1 = -1; // 1 <= h[i] <= 1000
    int maxh2 = -1; // n >= 2
    for (int i = 0; i < n; ++i) {
        scanf("%d%d", w + i, h + i);
        sumw += w[i];

        if (h[i] > maxh2) {
            maxh2 = h[i];
        }
        if (maxh1 < maxh2) {
            swap(maxh1, maxh2);
        }
    }

    for (int i = 0; i < n; ++i) {
        int curw = sumw - w[i];
        int curh = (h[i] == maxh1 ? maxh2 : maxh1);
        printf("%d", curw * curh); // n * h * w ~ 200,000 * 10 * 1,000 = 2,000,000,000: fits in int
        if (i + 1 < n) putchar(' ');
    }
    cout << endl;

    return 0;
}