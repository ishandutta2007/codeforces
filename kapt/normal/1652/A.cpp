#include <bits/stdc++.h>
using namespace std;

main() {
    int tst;
    cin >>tst;
    while (tst--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
        }
        sort(arr.begin(), arr.end());
        cout<< arr[n - 1] + arr[n - 2] << endl;
    }
    return 0;
}