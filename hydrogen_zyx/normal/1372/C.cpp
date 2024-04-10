#include <bits/stdc++.h>
using namespace std;
int a[300000];
bool b[300000];
int main() {
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) {
        memset(b, 0, sizeof(b));
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            if (a[i] == i) b[i] = 1;
        }
        int p1 = 1, p2 = n;
        while (p1 <= n && b[p1] == 1) p1++;
        while (p2 > 0 && b[p2] == 1) p2--;
        if (p1 > n && p2 <= 0) {
            cout << 0 << endl;
            continue;
        }
        bool f = 1;
        for (int i = p1; i <= p2; i++) {
            if (b[i] == 1) f = 0;
        }
        if (!f) {
            cout << 2 << endl;
            continue;
        } else {
            cout << 1 << endl;
            continue;
        }
    }
}