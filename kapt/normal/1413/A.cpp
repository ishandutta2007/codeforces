#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e3;
int arr[MAXN];

main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
        }
        int c = 1;
        for (int i = 0; i < n; ++i) {
            c *= -1;
            cout << c * arr[i ^ 1] << " ";
        }
        cout << endl;
    }
    return 0;
}