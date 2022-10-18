#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> v(n);
    for (auto& x : v)
        cin >> x;
    
    int total = 0;
    cout << n + 1 << '\n';
    for (int i = n-1; i >= 0; i--) {
        int x = ((i - v[i] - total) % n + n) % n;
        cout << 1 << ' ' << i + 1 << ' ' << x << '\n';
        total += x;
    }
    cout << 2 << ' ' << n << ' ' << n << '\n';
}