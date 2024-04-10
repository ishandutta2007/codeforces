#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(void) {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        sort(a.begin(), a.end());
        int i;
        for (i = n - 1; i >= 0; i--) {
            if (a[i] <= i + 1) {
                break;
            }
        }
        cout << i + 2 << "\n";
    }
}