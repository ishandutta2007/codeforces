#include <bits/stdc++.h>
using namespace std;
const int N = 200001;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    int i, j, k, n, t, x, o, top, top1, n1, x1, top2, x2;
    int a1[N], b1[N];
    cin >> n >> k;
    x = (n - 1) / k;
    if (x * k < (n - 1))
        ++x;
    top = 1;
    n1 = n - k;
    int u = 0;
    top1 = n;
    top2 = 0;
    x2 = x;
    while (k > 0) {
        ++u;
        j = 1;
        i = 1;
        while ((i < x) && (top < n1)) {
            ++top;
            ++top2;
            a1[top2] = j;
            b1[top2] = top;
            j = top;
            ++i;
        }
        if (u == 2)
            x1 = i;
        ++top2;
        a1[top2] = j;
        b1[top2] = top1;
        k--;
        top1--;
        if (k > 0) {
        x = (n1 - top)/k;
        if (x * k < n1 - top)
            ++x;
            ++x;
        }
    }
    cout << x2 + x1 << endl;
    for (i = 1; i <= top2; ++i)
        cout << a1[i] << ' ' << b1[i] << "\n";
}