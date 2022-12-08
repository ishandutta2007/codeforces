#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(2 * n);
        for (int &i : a)
            cin >> i;
        sort(a.begin(), a.end());
        vector<int> res(2 * n);
        for (int i = 0; i < n; i++) {
            res[2 * i] = a[i];
            res[2 * i + 1] = a[i + n];
        }
        for (int i : res)
            cout << i << " ";
        cout << "\n";
    }
    return 0;
}