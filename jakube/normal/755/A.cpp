#include <bits/stdc++.h>
using namespace std;

bool isPrime(int n) {
    if (n % 2 == 0) return n == 2;
    for (int div = 3; div*div <= n; div+=2) {
        if (n % div == 0) return false;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);
    cout << fixed;

    int n;
    cin >> n;
    
    for (int m = 1;; m++) {
        if (!isPrime(n*m+1)) {
            cout << m << endl;
            return 0;
        }
    }

    return 0;
}