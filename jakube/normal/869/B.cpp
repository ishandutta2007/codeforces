#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long a, b;
    cin >> a >> b;
    if (b - a >= 10) {
        cout << "0" << endl;
        return 0;
    }

    int digit = 1;
    for (long long i = a + 1; i <= b; i++) {
        digit = (digit * (i % 10)) % 10;
    }
    cout << digit << endl;
}