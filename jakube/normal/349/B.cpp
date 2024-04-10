#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);
    cout << fixed;

    int n;
    cin >> n;
    vector<int> v(9);
    for (int idx = 0; idx < 9; idx++)
        cin >> v[idx];

    vector<pair<int, int>> a;
    for (int i = 0; i < 9; i++) {
        a.push_back({v[i], -(i+1)});
    }
    sort(a.begin(), a.end());

    if (n < a.front().first) {
        cout << -1 << endl;
        return 0;
    }

    while (n >= a.front().first) {
        int mod = a.front().first + (n % a.front().first);
        for (int i = 8; i >= 0; i--) {
            if (v[i] <= mod) {
                cout << i+1;
                n -= v[i];
                break;
            }
        }
    }

    cout << endl;
    return 0;
}