#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, pos, l, r;
    cin >> n >> pos >> l >> r;
    
    if (l == 1 && r == n)
        cout << 0 << '\n';
    else if (l == 1)
        cout << abs(r - pos) + 1 << '\n';
    else if (r == n)
        cout << abs(l - pos) + 1 << '\n';
    else cout << min(abs(pos - l), abs(pos - r)) + 2 + r - l << '\n';
}