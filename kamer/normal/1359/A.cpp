#include <iostream>
using namespace std;

int main(void) {
    int t;
    cin >> t;
    while(t--) {
        int n, m, k;
        cin >> n >> m >> k;
        int d = n / k;
        if (m <= d) {
            cout << m << "\n";
        } else {
            m = m - d;
            cout << d - (m + k - 2) / (k - 1) << "\n";
        }
    }
}