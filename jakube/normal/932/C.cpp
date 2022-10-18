#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    int a, b;
    cin >> a >> b;

    // find solutions for x*a + y*b = n
    for (int x = 0; x*a <= n; x++) {
        int yb = n - x*a;
        if (yb % b == 0) {
            int y = yb / b;

            int cur = 1;
            for (int i = 0; i < x; i++, cur+=a) {
                for (int j = 0; j < a; j++) {
                    cout << cur + (j + 1) % a << " ";
                }
            }
            for (int i = 0; i < y; i++, cur+=b) {
                for (int j = 0; j < b; j++) {
                    cout << cur + (j + 1) % b << " ";
                }
            }
            cout << endl;
            return 0;
        }
    }
    cout << -1 << '\n';
}