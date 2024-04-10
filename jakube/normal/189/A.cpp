#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);
    cout << fixed;

    int n, a, b, c;
    cin >> n >> a >> b >> c;
    
    int m = 0;
    for (int i = 0; i*a <= n; i++) {
        for (int j = 0; i*a + j*b <= n; j++) {
            int k = (n - i*a - j*b) / c;
            if (i*a + j*b + k*c == n) {
                m = max(m, i+j+k);
            }
        }
    }

    cout << m << endl;

    return 0;
}