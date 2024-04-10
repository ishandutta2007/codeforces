#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
const int N = 4e5;

long long a[N];
int nod(int a, int b) {
    if (a < b)
        swap(a, b);

    if (b == 0)
        return a;
    else
        return nod(b, a % b);
}

int main() {
    int i, j, k, n;
    //freopen("input.txt", "r", stdin);
    int nd = 0;
    int mx = 0;
    cin >> n;
    for (i = 0; i < n; ++i) {
        cin >> a[i];
        mx = max(mx, (int)a[i]);
    }
    for (i = 1; i < n; ++i)
        nd = nod(nd, abs(a[i] - a[i - 1]));
    long long ans = 0;
    for (i = 0; i < n; ++i)
        if (a[i] != mx)
            ans += (mx - a[i]) / nd;
    cout << ans << ' ' << nd;
}