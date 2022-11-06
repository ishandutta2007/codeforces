#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    int n, a, b;
    cin >> n >> a >> b;

    if (n > a * b) {
        cout << -1 << '\n';
        return 0;
    }

    vector<int> odd, even;
    for (int i = 1; i <= n; i += 2) odd.push_back(i);
    for (int i = 2; i <= n; i += 2) even.push_back(i);

    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++) {
            if ((i + j) % 2 == 0 && !odd.empty()) {
                cout << odd.back() << ' ';
                odd.pop_back();
            } else if ((i + j) % 2 == 1 && !even.empty()) {
                cout << even.back() << ' ';
                even.pop_back();
            } else {
                cout << 0 << ' ';
            }
        }
        cout << '\n';
    }
}