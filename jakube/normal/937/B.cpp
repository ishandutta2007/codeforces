#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int p, y;
    cin >> p >> y;
    int q = min(p, (int)sqrt(y + 1));
    for (int i = y; i > p; i--) {
        bool coprime = true;
        for (int j = 2; j <= q; j++) {
            if (i % j == 0) {
                coprime = false;
                break;
            }
        }
        if (coprime) {
            cout << i << endl;
            return 0;
        }
    }
    cout << -1 << endl;
}