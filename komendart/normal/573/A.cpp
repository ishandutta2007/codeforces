#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    int n;
    cin >> n;
    vector<int> a(n, 0);
    for (int i = 0; i < n; i++) cin >> a[i];

    for (int i = 1; i < n; i++) {
        int g = gcd(a[0], a[i]);
        for (int j = 0; j < 2; j++) {
            int k = j == 0 ? a[0] / g: a[i] / g;
            while (k % 2 == 0) k /= 2;
            while (k % 3 == 0) k /= 3;
            if (k != 1) {
                cout << "No" << '\n';
                return 0;
            }
        }
    }

    cout << "Yes" << '\n';
}