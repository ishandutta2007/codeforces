#include <bits/stdc++.h>
using namespace std;
const int N = 3000;

int nod(int a, int b) {
    if (b > a)
        swap(a, b);
    if (b == 0)
        return a;
    else
        return nod(b, a%b);
}

int main() {
    int nd[N][N], i, j, a[N], n;
    //freopen("input.txt", "r", stdin);
    cin >> n;
    for (i = 0; i < n; ++i)
        cin >> a[i];
    int t = n + 1;
    for (i = 0; i < n; ++i) {
        nd[i][i] = a[i];
        for (j = i + 1; j < n; ++j) {
            nd[i][j] = nod(nd[i][j - 1], a[j]);
            if (nd[i][j] == 1 && j - i < t) {
                t = j - i;
            }
        }
        if (a[i] == 1)
            t = 0;
    }
    if (t > n) {
        cout << -1;
        return 0;
    }
    if (t == 0) {
        j = n;
        for (i = 0; i < n; ++i)
        if (a[i] == 1)
            --j;
        cout << j;
    } else
        cout << t + n - 1;
}