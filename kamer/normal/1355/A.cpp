#include<iostream>
using namespace std;

int minDigit(long long x) {
    int minDig = 10;
    if (x == 0) {
        return 0;
    }
    while (x > 0) {
        if (minDig > (x % 10)) {
            minDig = x % 10;
        }
        x = x / 10;
    }
    return minDig;
}

int maxDigit(long long x) {
    int maxDig = -1;
    if (x == 0) {
        return 0;
    }
    while (x > 0) {
        if (maxDig < (x % 10)) {
            maxDig = x % 10;
        }
        x = x / 10;
    }
    return maxDig;
}

int main(void) {
    long long t;
    cin >> t;
    for (long long i = 0; i < t; i++) {
        long long a, k;
        cin >> a >> k;
        if (a == 0) {
            cout << "0\n";
            continue;
        }
        bool cont = false;
        for (long long j = 1; j < k; j++) {
            int m = minDigit(a);
            int M = maxDigit(a);
            if (m == 0) {
                cout << a << "\n";
                cont = true;
                break;
            }
            a = a + m * M;
        }
        if (cont) {
            continue;
        }
        cout << a << "\n";
    }
    return 0;
}