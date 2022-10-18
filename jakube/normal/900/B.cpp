#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int a, b, c;
    cin >> a >> b >> c;
    vector<bool> vis(b, false);
    for (int i = 0; !vis[a]; i++) {
        vis[a] = true;
        a *= 10;
        if (a / b == c) {
            cout << i + 1 << '\n';
            return 0;
        }
        a %= b;
    }
    cout << -1 << '\n';
    
}