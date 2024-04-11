#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    int n;
    cin >> n;
    n *= 2;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int p = accumulate(a.begin(), a.end(), 0) / (n / 2);
    vector<char> used(n);
    for (int i = 0; i < n; i++) {
        if (used[i]) continue;
        for (int j = i + 1; j < n; j++) {
            if (!used[j] && a[i] + a[j] == p) {
                cout << a[i] << ' ' << a[j] << '\n';
                used[j] = true;
                break;
            }
        }
    }
}