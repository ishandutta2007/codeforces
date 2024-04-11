#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
const ld PI = acosl(-1.);

int main() {
    int n, d, h;
    cin >> n >> d >> h;

    if (h + h < d) {
        puts("-1");
        return 0;
    }

    if (d == 1) {
        if (h == 1 && n == 2) {
            cout << "1 2" << endl;
            return 0;
        }
        puts("-1");
        return 0;
    }

    if (h == d) {
        for (int i = 1; i <= h; ++i) {
            printf("%d %d\n", i, i + 1);
        }
        for (int i = h + 2; i <= n; ++i) {
            printf("%d %d\n", 2, i);
        }
    } else {
        for (int i = 1; i <= h; ++i) {
            printf("%d %d\n", i, i + 1);
        }
        int last = h + 1;

        int curd = h;
        int prev = 1;
        while (curd < d) {
            ++last;
            printf("%d %d\n", prev, last);
            prev = last;
            ++curd;
        }

        for (int i = last + 1; i <= n; ++i) {
            printf("%d %d\n", 1, i);
        }
    }

    return 0;
}