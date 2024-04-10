#include<bits/stdc++.h>

using namespace std;

int ask(int l, int r) {
    cout << "? " << l + 1 << " " << r + 1 << endl;
    int cnt = 0;
    for (int i = l; i <= r; i++) {
        int x;
        cin >> x;
        x--;
        cnt += l <= x && x <= r;
    }
    return cnt % 2;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int l = -1, r = n - 1;
        while (l + 1 < r) {
            int m = (l + r) / 2;
            if (ask(0, m)) {
                r = m;
            } else {
                l = m;
            }
        }
        cout << "! " << r + 1 << endl;
    }
}