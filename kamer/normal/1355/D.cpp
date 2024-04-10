#include <iostream>
using namespace std;

int main(void) {
    int n, s;
    cin >> n >> s;
    if (s < 2 * n) {
        cout << "NO\n";
        return 0;
    }

    cout << "YES\n";
    for (int i = 0; i < n - 1; i++) {
        cout << "2 ";
    }

    cout << s + 2 - 2 * n << "\n1\n";
}