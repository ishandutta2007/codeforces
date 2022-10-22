#include <iostream>
using namespace std;

int main(void) {
    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;
        if (b > 2 * a) b = 2 * a;
        if (a > 2 * b) a = 2 * b;
        cout << (a + b) / 3 << "\n";
    }
}