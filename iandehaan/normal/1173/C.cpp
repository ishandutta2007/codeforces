#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
    }
    int out = 0;
    int table[n+1];
    int lastZero = -1;
    for (int i = 1; i <= n; i++) {
        cin >> table[i];
        if (table[i] == 0) {
            lastZero = i;
        }
    }

    out = max(0, lastZero);
    int lastOut = -1;
    while (true) {
    for (int i = n; i >= 1; i--) {
        // cout << i << ' ' << out << endl;
        if (table[i] == 0) {
            continue;
        }
        int afterRemoveZero = i - out;
        if (out >= i) {
            int yeet = i;
            yeet += n-table[i]+1;
            out = max(out, yeet);
        } else if (i-out < table[i]) {
            int yeet = i;
            yeet += n-table[i]+1;
            out = max(out, yeet);
        } else {
            out = max(out, i-table[i]);
        }
    }
    if (lastOut == -1 || lastOut != out) {
        lastOut = out;
    } else {
        break;
    }
    }
    cout << out << endl;
}