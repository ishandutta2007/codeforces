#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        if (n == 1)
            printf("FastestFinger\n");
        else if (n == 2)
            printf("Ashishgup\n");
        else {
            if (n % 2 == 1)
                printf("Ashishgup\n");
            else {
                int nn = n;
                while (nn % 2 == 0)
                    nn /= 2;
                if (nn == 1)
                    printf("FastestFinger\n");
                else if (n % 4 == 0)
                    printf("Ashishgup\n");
                else { // 2 * odd
                    bool jest = false;
                    int sq = std::sqrt(n);
                    for (int i = 3; i <= sq; i++)
                        if (n % i == 0)
                            jest = true;
                    if (jest)
                        printf("Ashishgup\n");
                    else
                        printf("FastestFinger\n");
                }
            }
        }
    }
    return 0;
}