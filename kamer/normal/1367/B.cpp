#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(void) {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        int wrongOdd = 0, wrongEven = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] % 2 != i % 2) {
                if (i % 2 == 0) wrongEven++;
                else            wrongOdd++;
            }
        }
        if (wrongEven != wrongOdd) {
            cout << "-1\n";
        } else {
            cout << wrongOdd << "\n";
        }
    }
}