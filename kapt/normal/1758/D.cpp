#include <bits/stdc++.h>
using namespace std;

int main() {
    int tst;
    cin >> tst;
    while (tst--) {
        int n;
        cin >> n;
        cout << 3 * n << " " << 5 * n << " ";
        for (int i = 4 * n - n / 2 + 1; i < 4 * n + n / 2; ++i) {
            if (n % 2 == 0 && i == 4 * n) continue;
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}