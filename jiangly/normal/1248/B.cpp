#include <bits/stdc++.h>
using namespace std;
constexpr int MAX_N = 1E5;
int n;
int a[MAX_N];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    sort(a, a + n);
    int x = accumulate(a, a + n / 2, 0);
    int y = accumulate(a + n / 2, a + n, 0);
    cout << 1LL * x * x + 1LL * y * y << "\n";
    return 0;
}