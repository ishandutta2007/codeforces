#include <bits/stdc++.h>

using namespace std;

#define int long long

int f(int x) {
    int ans = 1;
    for (int i = 2; i * i <= x; i++) {
        int tmp = 0;
        while (x % i == 0) {
            tmp++;
            x /= i;
        }
        ans *= (tmp + 1);
    }
    if (x > 1) {
        ans *= 2;
    }
    return ans;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    int tmp = -1;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (tmp == -1) {
            tmp = x;
        }
        else {
            tmp = __gcd(x, tmp);
        }
    }
    cout << f(tmp);
}