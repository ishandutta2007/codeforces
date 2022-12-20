#include <iostream>
using namespace std;

int main() {
    int x, y, z;
    cin >> x >> y >> z;
    if (x-y > z) {
        cout << "+" << endl;
    } else if (y-x > z) {
        cout << "-" << endl;
    } else if (x == y && z == 0) {
        cout << "0" << endl;
    } else {
        cout << "?" << endl;
    }
}