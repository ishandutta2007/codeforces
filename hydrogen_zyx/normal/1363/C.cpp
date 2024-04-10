#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int cnt = 0;
        for (int i = 1; i < n; i++) {
            int a, b;
            cin >> a >> b;
            if (a == x) cnt++;
            if (b == x) cnt++;
        }
        if (cnt <= 1) {
            cout << "Ayush" << endl;
            continue;
        } else if (n & 1) {
            cout << "Ashish" << endl;
            continue;
        } else {
            cout << "Ayush" << endl;
            continue;
        }
    }
}