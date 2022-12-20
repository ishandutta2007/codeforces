#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    for (int cs = 1; cs <= t; cs++) {
        int n;
        cin >> n;
        char number[n];
        for (int i = 0; i < n; i++) {
            cin >> number[i];
        }
        int away = 200;
        for (int i = 0; i < n; i++) {
            if (number[i] == '8') {
                away = i;
                break;
            }
        }
        if (n - away >= 11) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}