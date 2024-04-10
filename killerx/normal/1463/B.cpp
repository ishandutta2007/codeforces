#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mp make_pair
#define pb push_back

#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

int main() {
    int T;
    scanf("%d", &T);
    while (T --) {
        int n;
        scanf("%d", &n);
        while (n --) {
            int a;
            scanf("%d", &a);
            int b = 1;
            while (b * 2 <= a) b *= 2;
            printf("%d ", b);
        }
        printf("\n");
    }
    return 0;
}