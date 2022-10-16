#include <iostream>
using namespace std;

string min_nr, max_nr;

int main() {
    int n, m;
    cin >> n >> m;
    if (n == 1 && m == 0) {
        cout << "0 0";
        return 0;
    }
    if (m == 0 || m > 9 * n) {
        cout << "-1 -1";
        return 0;
    }
    int m1 = 9 * n - m, m2 = m;
    for (int i = 0; i < n; i++) {
        int t = min(9 - (i == 0), m1);
        min_nr += '9' - t;
        m1 -= t;
        int u = min(9, m2);
        max_nr += '0' + u;
        m2 -= u;
    }
    cout << min_nr << ' ' << max_nr;
}