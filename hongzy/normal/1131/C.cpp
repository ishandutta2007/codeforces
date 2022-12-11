#include <algorithm>
#include <cstdio>
using namespace std;

const int N = 110;

int n, h[N];

int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i ++)
        scanf("%d", h + i);
    sort(h + 1, h + n + 1);
    for(int i = 1; i <= n; i += 2) {
        printf("%d ", h[i]);
    }
    for(int i = n - (n & 1); i >= 1; i -= 2) {
        printf("%d ", h[i]);
    }
    return 0;
}