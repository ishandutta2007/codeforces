#include <iostream>
using namespace std;

int sumOfDigs(int x) {
    int out = 0;
    while (x > 0) {
        out += x%10;
        x /= 10;
    }
    return out;
}

int main() {
    int a;
    cin >> a;
    while (true) {
        if (sumOfDigs(a)%4 == 0) {
            cout << a << endl;
            break;
        }
        a++;
    }
}