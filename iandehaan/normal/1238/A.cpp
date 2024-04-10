#include <iostream>
using namespace std;

int main() {
    uint64_t t, x, y;
    cin >> t;
    while (t--) {
        cin >> x >> y;
        cout << (x-y == 1 ? "NO" : "YES") << endl;;
    }
}