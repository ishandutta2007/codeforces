#include <bits/stdc++.h>
using namespace std;

bool isprime(int n) {
    for (int i = 2; i < min(100000, n); ++i)
        if (n % i == 0) return false;
    return true;
}

int main() {
    int n;
    cin >> n;
    if (isprime(n)) {
        cout << "1\n" << n << "\n";
        return 0;
    }
    for (int i = 3; ; i += 2) {
        int a = i, b = n - 3 - i;
        if (isprime(a) && isprime(b)) {
            cout << "3\n3 " << a << " " << b << "\n";
            return 0;
        }
    }
}