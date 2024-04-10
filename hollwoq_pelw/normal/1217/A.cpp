#include <bits/stdc++.h>

using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int st, in, ex;
        cin >> st >> in >> ex;
        int s = 0, e = ex + 1;
        while (s < e) {
            int m = (s + e) / 2;
            if (st + m > in + ex - m) e = m;
            else s = m + 1;
        }
        if (s > ex) printf("0\n");
        else printf("%d\n", ex - s + 1);
    }
    return 0;
}