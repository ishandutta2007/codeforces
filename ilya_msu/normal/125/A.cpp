#include<iostream>
#include<vector>
#include<string>

using std::string;
using std::vector;
using std::cin;
using std::cout;
using std::endl;
using std::min;


long long next (long long x) {
    if (x == 0)
        return 0;
    if (x % 10 <= 4) {
        long long a = next(x / 10);
        return a * 10 + 4;
    }
    if (x % 10 <= 7) {
        long long a = next(x / 10);
        if (a > x / 10)
            return a * 10 + 4;
        else
            return a * 10 + 7;
    }
    return next((x + 10 - (x % 10)) / 10) * 10 + 4; 
}

struct pair {
    int x, y;
};


int main() {
    int n;
    cin >> n;
    if (n % 3 == 1)
        --n;
    if (n % 3 == 2)
        ++n;
    int d = n / 3;
    int f = d / 12;
    d = d - 12 * f;
    
    cout << f << " " << d << endl;
    return 0;
}