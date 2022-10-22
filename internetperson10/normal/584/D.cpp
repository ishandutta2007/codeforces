#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

bool isprime(int n) {
    for(int a=2; a<=sqrt(n); a++)
        if(n%a==0)
            return false;
    return true;
}

int main() {
    int n, a=2;
    cin >> n;
    if(isprime(n))
        cout << 1 << '\n' << n;
    else if(isprime(n-2))
        cout << 2 << '\n' << 2 << ' ' << n-2;
    else {
        while(1) {
            if(isprime(a) && isprime(n-2*a)) {
                cout << 3 << '\n' << a << ' ' << a << ' ' << n-2*a;
                break;
            }
            a++;
        }
    }
}