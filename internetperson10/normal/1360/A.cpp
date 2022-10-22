#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int a, b;
        cin >> a >> b;
        int x = min(max(a, 2*b), max(b, 2*a));
        cout << x*x << '\n';
    }
}