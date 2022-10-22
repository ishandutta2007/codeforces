#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    set <int> s;
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        if (x == i) {
            ans++;
        } else {
            s.insert(x);
        }
    }
    cout << ans + (int) s.size() / 2;
    return 0;
}