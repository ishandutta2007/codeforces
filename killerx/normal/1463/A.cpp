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
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        int mn = min(min(a, b), c);
        int s = a + b + c;
        if (s % 9 == 0 && mn >= s / 9) puts("YES");
        else puts("NO");
    }
    return 0;
}