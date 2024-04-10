#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int a[n];
    int prev;
    cin >> prev;
    bool incr = true;
    bool good = true;
    for (int i = 1; i < n; i++) {
        if (prev == n) {
            incr = false;
        }
        int x;
        cin >> x;
        if (incr && x < prev) {
            good = false;
        }
        if ((!incr) && x > prev) {
            good = false;
        }
        prev = x;
    }
    if (good) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}