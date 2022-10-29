#include <bits/stdc++.h>
using namespace std;
int a[200000], b[200000];
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++) cin >> a[i];
        for (int i = 1; i <= n; i++) cin >> b[i];
        bool big = 0, small = 0;
        for (int i = n; i > 0; i--) {
            if (a[i] == 1) big = 0;
            if (a[i] == -1) small = 0;
            if (a[i] < b[i]) big = 1;
            if (a[i] > b[i]) small = 1;
        }
        if (big || small)
            cout << "NO" << endl;
        else
            cout << "YES" << endl;
    }
}