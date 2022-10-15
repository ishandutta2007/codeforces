#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>
#include<stack>


using namespace std;

int gcd (int a, int b) {
    while (b > 0) {
        a = a % b;
        swap(a, b);
    }
    return a;
}

int main() {
    int a, b, n;
    cin >> a >> b >> n;
    int x = 0;
    while (n > 0) {
        if (x % 2 == 0)
            n -= gcd(a, n);
        else
            n -= gcd(n, b);
        ++x;
    }
    cout << (x + 1) % 2 << endl;
    return 0;
}