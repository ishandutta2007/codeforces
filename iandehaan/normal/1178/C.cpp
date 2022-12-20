#include <iostream>
using namespace std;

 int64_t modulo(int64_t a, int64_t b, int64_t n){
    long long x=1, y=a; 
    while (b > 0) {
        if (b%2 == 1) {
            x = (x*y) % n; // multiplying with base
        }
        y = (y*y) % n; // squaring the base
        b /= 2;
    }
    return x % n;
}

int main() {
    int64_t w, h;
    cin >> w >> h;
    cout << modulo(2, w+h, 998244353) << endl;
}