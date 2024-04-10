#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    int c = 0b11;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        x--;
        if (!(c & (1 << x))) {
            cout << "NO" << '\n';
            return 0;
        }
        c = 0b111 ^ c ^ (1 << x);
    }
    cout << "YES" << '\n';
}