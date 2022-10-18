#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    
    if (n <= 5)
        cout << -1 << '\n';
    else {
        cout << 1 << " " << 2 << '\n';
        cout << 1 << " " << 3 << '\n';
        cout << 1 << " " << 4 << '\n';
        for (int i = 5; i <= n; i++) {
            cout << 2 << " " << i << '\n';
        }
    }

    // star
    for (int i = 2; i <= n; i++) {
        cout << 1 << " " << i << '\n';
    }
}