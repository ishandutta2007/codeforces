#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        int sum = 0;
        for (int i = 0; i < n; i++) sum += a[i];
        if (sum % x != 0) {
            cout << n << "\n";
            continue;
        }
        int left = 0;
        int right = n - 1;
        while ((left < n) && (a[left] % x == 0)) left++;
        if (left == n) {
            cout << "-1\n";
            continue;
        }
        while ((right >= 0) && (a[right] % x == 0)) right--;
        cout << max(right, n - 1 - left) << "\n";
    }
}