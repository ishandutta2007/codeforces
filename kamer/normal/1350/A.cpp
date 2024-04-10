#include <iostream>
using namespace std;

const int customBound = 1000;

int findDivisor(int n) {
    for (int i = 2; i < customBound; i++) {
        if ((n % i) == 0) return i; 
    }
    return n;
}

int main(void) {
    int T;
    cin >> T;
    while (T--) {
        int n, k;
        cin >> n >> k;
        n += findDivisor(n);
        cout << n + 2 * (k - 1) << "\n";
    }
    return 0;
}