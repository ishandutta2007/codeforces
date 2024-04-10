#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

int x[1000];
double y[1000];

int main() {
    int n, r;
    scanf("%d %d", &n, &r);
    for (int i = 0; i < n; i++) {
        scanf("%d", x + i);
        y[i] = r;
        for (int j = 0; j < i; j++) {
            if (abs(x[i] - x[j]) <= 2 * r)
                y[i] = max(y[i], y[j] + sqrt(4 * r * r - (x[i] - x[j]) * (x[i] - x[j])));
        }
    }
    for (int i = 0; i < n; i++)
        printf("%.9f%c", y[i], i == n - 1 ? '\n' : ' ');
}