#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int numZero = 0, numOne = 0;
        for (auto c : s) {
            if (c == '0') numZero++;
            else numOne++;
        }
        if (min(numZero, numOne) % 2 == 1) {
            cout << "DA\n";
        } else {
            cout << "NET\n";
        }

    }
}