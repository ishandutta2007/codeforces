#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, s;
    cin >> n >> s;
    s--;
    vector<int> a(n);
    for (auto& x : a)
        cin >> x;
    vector<int> b(n);
    for (auto& x : b)
        cin >> x;
    
    if (!a[0]) {
        cout << "NO" << '\n';
        return 0;
    }

    if (a[s]) {
        cout << "YES" << '\n';
        return 0;
    } else {
        for (int i = s + 1; i < n; i++) {
            if (a[i] && b[i] && b[s]) {
                cout << "YES" << '\n';
                return 0;
            }
        }
    }
    cout << "NO" << '\n';
}