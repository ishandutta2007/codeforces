#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    for (int x = 5; x * x <= n; x++) {
        int y = n / x;
        if (x * y == n) {
            string vowels = "aeiou";
            for (int row = 0; row < y; row++) {
                int offset = row;
                for (int col = 0; col < x; col++) {
                    cout << vowels[(col + offset) % 5];
                }
            }
            cout << endl;
            return 0;
        }
    }
    cout << -1 << '\n';
}