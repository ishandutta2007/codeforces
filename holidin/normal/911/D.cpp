#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 1;

int a[N];

int main() {
    int i, j, k, n, l, r, q;
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    int sum = 0;
    for (i = 1; i <= n; ++i) {
        cin >> a[i];
        for (j = 1; j < i; ++j)
        if (a[j] > a[i])
            ++sum;
    }
    sum %= 2;
    cin >> q;
    for (i = 0; i < q; ++i) {
        cin >> l >> r;
        l = r - l + 1;
        if ((((l - 1) * l) / 2) % 2 == 1)
            sum = !sum;
        if (sum == 0)
            cout << "even\n";
        else
            cout << "odd\n";
    }
}