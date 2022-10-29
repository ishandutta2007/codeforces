#include <bits/stdc++.h>

using namespace std;
int a[100];
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        memset(a, 0, sizeof a);
        for (int i = 1; i <= n; i++) {
            int x;
            cin >> x;
            int k = 0;
            while (x) {
                if (x & 1) a[k]++;
                x >>= 1;
                k++;
            }
        }
        int p = -1;
        for (int i = 99; i >= 0; i--) {
            if (a[i] & 1) {
                p = i;
                break;
            }
        }
        if (p == -1) {
            cout << "DRAW" << endl;
            continue;
        }
        bool win = 1;
        if (((n - a[p]) & 1) == 0 && ((a[p] / 2) & 1) != 0) {
            win = 0;
        }
        if (win)
            cout << "WIN" << endl;
        else
            cout << "LOSE" << endl;
    }
}