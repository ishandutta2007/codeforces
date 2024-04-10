#include<bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    multiset<int> a, b;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a.insert(x);
    }
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        b.insert(x);
    }
    int ans = 0;
    while ((int) a.size()) {
        int x = *a.rbegin(), y = *b.rbegin();
        a.erase(a.find(x));
        b.erase(b.find(y));
        if (x > y) {
            a.insert((int) to_string(x).size());
            b.insert(y);
            ans++;
        } else if (x < y) {
            a.insert(x);
            b.insert((int) to_string(y).size());
            ans++;
        }
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}