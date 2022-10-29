#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        int ji = 0, ou = 0;
        for (int i = 0; i < n; i++) {
            int a;
            cin >> a;
            if (a & 1)
                ji++;
            else
                ou++;
        }
        bool f = 0;
        for (int i = 1; i <= ji; i += 2) {
            if (m - i <= ou && m - i >= 0) f = 1;
        }
        if (f)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
}