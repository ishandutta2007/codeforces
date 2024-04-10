#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    int t;
    cin >> t;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    for (int i = 0; i < n; i++) {
        t -= 86400 - v[i];
        if (t <= 0) {
            cout << i + 1 << '\n';
            break;
        }
    }
}