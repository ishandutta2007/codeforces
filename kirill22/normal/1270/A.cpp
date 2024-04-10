#include<bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, k1, k2;
        cin >> n >> k1 >> k2;
        set<int> a, b;
        for (int i = 0; i < k1; i++) {
            int x;
            cin >> x;
            a.insert(x);
        }
        for (int i = 0; i < k2; i++) {
            int x;
            cin >> x;
            b.insert(x);
        }
        cout << (*a.rbegin() > *b.rbegin() ? "YES\n" : "NO\n");
    }
}