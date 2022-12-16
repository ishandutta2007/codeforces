#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int a, b, c, n;
        cin >> a >> b >> c >> n;
        if ((a+b+c+n) % 3 != 0) {
            cout << "NO" << endl;
            continue;
        }

        n = (a+b+c+n);

        if (a > n/3 || b > n/3 || c > n/3) {
            cout << "NO" << endl;
            continue;
        }
        cout << "YES" << endl;
    }
}