#include<bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        int pos = 0, q;
        cin >> q;
        while (q--) {
            int x;
            cin >> x;
            pos = (pos + x) % n;
        }
        cout << a[pos] << '\n';
    }
}