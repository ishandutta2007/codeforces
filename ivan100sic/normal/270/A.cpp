#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int x;
        cin >> x;
        x = 180 - x;
        
        if (360 % x == 0) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}