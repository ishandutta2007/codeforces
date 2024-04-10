#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long a, b;
    cin >> a >> b;

    for (int i = 1; ; i++) {
        if (i % 2) {
            if (i > a) {
                cout << "Vladik" << endl;
                return 0;
            }
            a -= i;
        } else {
            if (i > b) {
                cout << "Valera" << endl;
                return 0;
            }
            b -= i;
        }
    }
}