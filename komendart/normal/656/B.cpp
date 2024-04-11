#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b) {
    while (b != 0) {
        int t = a % b;
        a = b; b = t;
    }
    return a;
}

int main() {
    int n;
    cin >> n;
    vector<int> M(n), R(n);
    for (int i = 0; i < n; i++) cin >> M[i];
    for (int i = 0; i < n; i++) cin >> R[i];

    cout << fixed; cout.precision(8);
    int lcm = M[0];
    for (int i = 1; i < n; i++) {
        lcm = lcm * M[i] / gcd(lcm, M[i]);
    }

    int ans = 0;
    for (int i = 0; i < lcm; i++) {
        for (int j = 0; j < n; j++) {
            if (i % M[j] == R[j]) {
                ans++;
                break;
            }
        }
    }
    cout << 1.0 * ans / lcm << endl;
}