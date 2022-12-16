#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    if (n == 1) {
        cout << 9 << ' ' << 8 << endl;
        return 0;
    }
    cout << 3*n << ' ' << 2*n << endl;
}