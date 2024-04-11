#include <bits/stdc++.h>

using namespace std;

void win(int x) {
    if (x == 1) cout << "Daenerys" << endl;
    else cout << "Stannis" << endl;
}

int main() {
    ios_base::sync_with_stdio(false);

    int n, k;
    cin >> n >> k;
    int odd = 0, even = 0;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        if (a % 2 == 1) {
            odd++;
        } else {
            even++;
        }
    }

    if (n == k) {
        win(odd & 1 ^ 1);
        return 0;
    }
    if ((n - k + 1) / 2 >= even && k % 2 == 1) {
        win(0);
        return 0;
    }
    if ((n - k) / 2 >= even && k % 2 == 0) {
        win(1);
        return 0;
    }
    if ((n - k) / 2 >= odd || (n - k) % 2 == 0) {
        win(1);
        return 0;
    }
    win(0);
}