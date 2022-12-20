#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    n *= 2;
    int a[n];
    int mode = -1;
    cin >> mode;
    bool good = false;
    a[0] = mode;
    for (int i = 1; i < n; i++) {
        int x;
        cin >> x;
        if (x != mode) {
            good = true;
        }
        a[i] = x;
    }

    if (!good) {
        cout << -1 << endl;
    } else {
        sort(a, a+n);
        for (int i = 0 ; i < n-1; i++) {
            cout << a[i] << ' ';
        }
        cout << a[n-1] << endl;
    }
}