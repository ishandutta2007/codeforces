#include<bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, q;
        cin >> n >> q;
        map<int, int> l, r;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            r[x] = i;
            if (l.find(x) == l.end()) {
                l[x] = i;
            }
        }
        while (q--) {
            int a, b;
            cin >> a >> b;
            if (l.find(a) != l.end() && l.find(b) != l.end()) {
                if (l[a] <= r[b]) {
                    cout << "YES\n";
                } else {
                    cout << "NO\n";
                }
            } else {
                cout << "NO\n";
            }
        }
    }
}