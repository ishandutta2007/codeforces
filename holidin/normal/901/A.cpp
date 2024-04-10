#include <bits/stdc++.h>
using namespace std;
const int N = 300000;
const long long inf = 1e9 + 7;

int main() {
    int i, j, n, a[N], pr[N];
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n;
    int k = -1;
    for (i = 0; i <= n; ++i)
        cin >> a[i];
    pr[0] = a[0];
    for (i = 1; i <= n; ++i) {
        pr[i] = a[i] + pr[i - 1];
        if (a[i] > 1 && a[i - 1] > 1)
            k = i;
    }
    if (k > 0) {
        cout << "ambiguous\n";
        cout << 0;
        for (i = 1; i <= n; ++i)
        for (j = 0; j < a[i]; ++j)
            cout << ' '  << pr[i - 1];
        cout << "\n";
        cout << 0;
        for (i = 1; i <= n; ++i)
        for (j = 0; j < a[i]; ++j)
        if (i == k && j == 0)
            cout << ' ' << pr[i - 1] - 1;
        else
            cout << ' ' << pr[i - 1];
    } else
        cout << "perfect";

}