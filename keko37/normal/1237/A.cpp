#include<bits/stdc++.h>

using namespace std;

const int MAXN = 15005;

int n, cnt;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i=0; i<n; i++) {
        int x; cin >> x;
        if (x % 2 == 0) {
            cout << x / 2 << endl;
        } else {
            if (cnt % 2) cout << (x + 1) / 2 << endl; else cout << (x - 1) / 2 << endl;
            cnt++;
        }
    }
    return 0;
}