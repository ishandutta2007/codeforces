#include <iostream>

using namespace std;

int main() {
    int l, b, a=0;
    cin >> l >> b;
    while(l<=b) {
        l*=3;
        b*=2;
        a+=1;
    }
    cout << a;
}