#include <iostream>
using namespace std;

int main() {
    int num1 = 0;
    int num2 = 0;
    int curr = 0;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (x == 1) {
            num1++;
        } else {
            num2++;
        }
    }

    while (num1 > 0 || num2 > 0) {
        if (num1 + num2 == 1) {
            if (num1 == 1) {
                cout << 1 << endl;
                return 0;
            } else {
                cout << 2 << endl;
                return 0;
            }
        }
        if (curr == 0 && num2 > 0) {
            cout << 2 << " ";
            curr += 2;
            num2--;
            continue;
        }
        if (num1 > 1) {
            curr += 1;
            num1--;
            cout << 1 << " ";
            continue;
        }
        if (num1 == 1 && curr % 2 == 0) {
            cout << 1 << " ";
            curr += 1;
            num1--;
            continue;
        }
        curr += 2;
        cout << 2 << " ";
        num2--;
    }
}