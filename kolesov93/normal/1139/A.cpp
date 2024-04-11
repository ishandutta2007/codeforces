#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
const ld PI = acosl(-1.);

int main() {
    int n;
    ll ans = 0;
    cin >> n;
    int got = 0;
    while (n--) {
        ++got;
        char c = getchar();
        while (c < '0' || c > '9') c = getchar();
        int d = c - '0';
        if (!(d & 1)) {
            ans += got;
        }
    }
    cout << ans << endl;

    return 0;
}