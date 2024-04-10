#include <iostream>
using namespace std;

int main() {
    uint64_t n, target;
    cin >> n >> target;
    int count = 0;
    while (target %(n*2) == 0) {
        n *= 2;
        count++;
    }
    while (target %(n*3) == 0) {
        n *= 3;
        count++;
    }
    if (n == target) {
        cout << count << endl;
    } else {
        cout << -1 << endl;
    }
}