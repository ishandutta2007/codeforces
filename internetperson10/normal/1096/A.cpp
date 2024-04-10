#include <iostream>

using namespace std;

int main() {
    int lower, upper, testcases;
    cin >> testcases;
    for(int a=0; a<testcases; a++) {
        cin >> lower >> upper;
        cout << lower << ' ' << lower*2 << '\n';
    }
}