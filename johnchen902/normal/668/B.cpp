#include <cstdio>
#include <algorithm>
using namespace std;
int main() {
    int n, q;
    scanf("%d %d", &n, &q);
    int d0 = 0, d1 = 0;
    for(int qi = 0; qi < q; qi++) {
        int t;
        scanf("%d", &t);
        if(t == 1) {
            int x;
            scanf("%d", &x);
            d0 = (d0 + x) % n;
            d1 = (d1 + x) % n;
        } else { // t == 2
            if(d0 % 2 == 0) {
                d0++;
                d1--;
            } else {
                d0--;
                d1++;
            }
        }
    }
    for(int i = 0; i < n; i++) {
        if((d0 % 2 == 0) == (i % 2 == 0)) {
            printf("%d", ((i - d0) % n + n) % n + 1);
        } else {
            printf("%d", ((i - d1) % n + n) % n + 1);
        }
        putchar(i == n - 1 ? '\n' : ' ');
    }
}