#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    for (int cs = 0; cs < t; cs++) {
        uint64_t n, k;
        cin >> n >> k;
        uint64_t moves = 0;
        while (n != 0) {
            if (n == 1) {
                n--;
                moves++;
            } else if (n % k == 0) {
                n /= k;
                moves++;
            } else {
                uint64_t x = n % k;
                n -= x;
                moves += x;
            }
        }
        cout << moves << endl;
    }
}