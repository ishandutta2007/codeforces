#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int64_t a[3];
        cin >> a[0] >> a[1] >> a[2];
        bool good = true;
        int64_t mx = (a[0] + a[1] + a[2]) / 2;
        if ((a[0] + a[1] + a[2]) % 2) mx++;
        for (int i = 0; i < 3; i++) {
            if (a[i] > mx) good = false;
        }
        if (good) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
}