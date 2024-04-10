#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int n, a, b;

int main() {
    scanf("%d%d%d", &n, &a, &b);
    if (a * b < n) printf("-1\n");
    else {
        int odd = 1;
        int even = 2;
        for (int i = 0; i < a; i++) {
            for (int j = 0; j < b; j++) {
                if (((i + j)&1) == 0 && odd <= n) {
                    printf("%d ", odd);
                    odd += 2;
                } else if (((i + j)&1) && even <= n) {
                    printf("%d ", even);
                    even += 2;
                } else printf("0 ");
            }
            printf("\n");
        }
    }
    return 0;
}