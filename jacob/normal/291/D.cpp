#include <cstdio>
#include <vector>
using namespace std;

int main(void) {
    int n, k;
    scanf("%d%d", &n, &k);
    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        v[i] = (i == 0) ? 0 : 1;
    }
    for (int i = 0; i < k; ++i) {
        for (int j = n-1; j >= 0; --j) {
            if (v[j] == j) {
                printf("%d ", n);
                continue;
            }
            if (2 * v[j] <= j) {
                printf("%d ", n - j);
                v[j] *= 2;
            } else {
                printf("%d ", n - (j - v[j]));
                v[j] += v[j - v[j]];
            }
        }
        printf("\n");
    }
    return 0;
}