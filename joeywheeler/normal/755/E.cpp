#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

int n, k;

int main() {
    scanf("%d %d", &n, &k);
    if (n <= 3 || k == 1 || k >= 4 || (n==4 && k==2)) {
        printf("-1\n");
    } else {
        if (k == 2) {
            printf("%d\n", n-1);
            FO(i,0,n-1) {
                printf("%d %d\n", i+1, i+2);
            }
        } else {
            printf("%d\n", 3 + (n-4)*2);
            FO(i,0,3) printf("%d %d\n", i+1, i+2);
            FO(i,4,n) {
                printf("%d %d\n", i+1, 1);
                printf("%d %d\n", i+1, 3);
            }
        }
    }
}