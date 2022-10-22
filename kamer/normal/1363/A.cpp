#include <iostream>
using namespace std;

int main(void) {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        bool onlyEvens = true;
        bool onlyOdds = true;
        int sum = 0;
        for (int i = 0; i < n; i++) {
            int a;
            cin >> a;
            sum += a;
            if (a % 2 == 1) onlyEvens = false;
            else            onlyOdds  = false;
        }
        if (n == x) {
            if (sum % 2 == 1) {
                cout << "Yes\n";
            } else {
                cout << "No\n";
            }
        } else if (onlyEvens) {
            cout << "No\n";
        } else if (onlyOdds) {
            if (x % 2 == 1) {
                cout << "Yes\n";
            } else {
                cout << "No\n";
            }
        } else {
            cout << "Yes\n";
        }
    }
}