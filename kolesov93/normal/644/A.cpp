#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
const ld PI = acosl(-1.);

int main() {
    int n, a, b;
    cin >> n >> a >> b;

    int k1 = a * b / 2;
    int k2 = a * b - k1;
    int n1 = n / 2;
    int n2 = n - n1;

    if (n1 > k1 || n2 > k2) {
        puts("-1");
        return 0;
    }

    for (int i = 0; i < a; ++i) {
        for (int j = 0; j < b; ++j) {
            int parity = (i + j) & 1;
            if (parity == 0) {
                if (n2) {
                    printf("%d ", n2 * 2 - 1);
                    --n2;
                } else {
                    printf("0 ");
                }
            } else {
                if (n1) {
                    printf("%d ", n1 * 2);
                    --n1;
                } else {
                    printf("0 ");
                }
            }
        }
        puts("");
    }

    return 0;
}