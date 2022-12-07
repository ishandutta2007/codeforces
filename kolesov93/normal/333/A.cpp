#include <iostream>

using namespace std;

int main() {
    long long n;
    cin >> n;

    while ((n % 3) == 0) {
        n /= 3;
    }

    cout << (n + 2) / 3 << endl;

    return 0;
}