#include <cstdio>

int CONST[5] = {0, 1, 0, 1, 2};

int get_sg(int n, int k) {
    if (k & 1) {
        if (n < 5) {
            return CONST[n];
        }
        if (n & 1) {
            return 0;
        }
        int tz = 0;
        while (~n & 1) {
            n >>= 1;
            tz ^= 1;
        }
        if (n == 1 && !tz) {
            return 2;
        }
        if (n == 3 && tz) {
            return 2;
        }
        if (n != 1 && n != 3 && !tz) {
            return 2;
        }
        return 1;
    } else {
        if (n <= 2) {
            return n;
        }
        return (n & 1) ^ 1;
    }
}

int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    int x = 0;
    for (int i = 0; i < n; ++ i) {
        int a;
        scanf("%d", &a);
        x ^= get_sg(a, k);
    }
    puts(x ? "Kevin" : "Nicky");
    return 0;
}