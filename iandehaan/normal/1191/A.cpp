#include <iostream>
using namespace std;

int main() {
    int x;
    cin >> x;
    if (x % 4 == 1) {
        cout << "0 A" << endl;
    } else if (x % 4 == 3) {
        cout << "2 A" << endl;
    } else if (x % 4 == 2) {
        cout << "1 B" << endl;
    } else {
        cout << "1 A" << endl;
    }
}