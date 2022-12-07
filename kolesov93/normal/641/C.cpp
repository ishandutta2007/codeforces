#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
const ld PI = acosl(-1.);
const int N = 1000111;
int a[N];

int main() {
    int n, q;
    scanf("%d%d", &n, &q);

    int odd = 0, even = 0;
    while (q--) {
        int t, shift;
        scanf("%d", &t);
        if (t == 1) {
            scanf("%d", &shift);
            odd = (odd + shift + n) % n;
            even = (even + shift + n) % n;
        } else {
            if (even & 1) {
                odd = (odd + n - 1) % n;
                even = (even + 1) % n;
            } else {
                even = (even + n - 1) % n;
                odd = (odd + 1) % n;
            }
        }
    }

    
    for (int i = 0; i < n; ++i) {
        if (i & 1) {
            a[(i + even) % n] = i + 1;
        } else {
            a[(i + odd) % n] = i + 1;
        }
    }

    for (int i = 0; i < n; ++i) printf("%d ", a[i]);
    puts("");

    return 0;
}