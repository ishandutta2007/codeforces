#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int a[30000];

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int c0 = 0, c1 = 0;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            if (a[i] == 0)
                c0++;
            else
                c1++;
        }
        if (c0 >= c1) {
            cout << c0 << endl;
            for (int i = 1; i <= c0; i++) cout << 0 << ' ';
        } else {
            if (c1 & 1) {
                cout << c1 - 1 << endl;
                for (int i = 1; i < c1; i++) cout << 1 << ' ';
            } else {
                cout << c1 << endl;
                for (int i = 1; i <= c1; i++) cout << 1 << ' ';
            }
        }
        cout << endl;
    }
}