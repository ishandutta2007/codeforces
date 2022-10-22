#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
    int T;
    cin >> T;
    while(T--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n), b(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> b[i];
        }
        for (int i = 0; i < k; i++) {
            sort(a.begin(), a.end());
            sort(b.begin(), b.end());
            if (a[0] < b[n - 1]) {
                int temp = a[0];
                a[0] = b[n - 1];
                b[n - 1] = temp;
            }
        }
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += a[i];
        }
        cout << sum << "\n";
    }
    return 0;
}