#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
const ld PI = acosl(-1.);

int main() {
    int n, v;
    cin >> n >> v;
    int ans = min(n - 1, v);
    for (int i = 2; i <= n; ++i) {
        if (i + v - 1 >= n) {
            break;
        }
        ans += i;
    }
    cout << ans << endl;

    return 0;
}