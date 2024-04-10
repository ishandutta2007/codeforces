#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    string b;
    cin >> b;

    int l = -1'000'000'000;
    int r = 1'000'000'000;
    for (int i = 4; i < n; i++) {
        if (b[i] != b[i-1]) {
            if (b[i] == '1') {
                l = max(l, max({a[i], a[i-1], a[i-2], a[i-3], a[i-4]}) + 1);
            } else {
                r = min(r, min({a[i], a[i-1], a[i-2], a[i-3], a[i-4]}) - 1);
            }
        }
    }
    cout << l << " " << r << endl;
}