#include <bits/stdc++.h>
using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int a, b, c, n, k, i, t;
    cin >> n >> a >> b;
    c = 0; k = 0;
    for (i = 1; i <= n; ++i) {
        cin >> t;
        if (t == 1)
            if (a > 0)
                a--;
            else if (b > 0) {
                b--;
                c++;
            } else if (c > 0)
                c--;
            else ++k;
        if (t == 2)
            if (b > 0)
                b--;
            else
                k += 2;
    }
    cout << k;
}