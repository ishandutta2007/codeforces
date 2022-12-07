#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int n, Min[3], Max[3];

int main() {
    scanf("%d", &n);
    int sum = 0;
    for (int i = 0; i < 3; i++) {
        scanf("%d%d", &Min[i], &Max[i]);
        n -= Min[i];
        Max[i] -= Min[i];
    }
    for (int i = 0; i < 3; i++) {
        if (n < Max[i]) {
            Min[i] += n;
            n = 0;
        } else {
            n -= Max[i];
            Min[i] += Max[i];
        }
        printf("%d ", Min[i]);
    }
    return 0;
}