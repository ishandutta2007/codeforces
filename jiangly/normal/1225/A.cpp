#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int a, b;
    cin >> a >> b;
    if (a == b)
        cout << 10 * a << " " << 10 * b + 1 << endl;
    else if (a + 1 == b)
        cout << 10 * a + 9 << " " << 10 * b << endl;
    else if (a == 9 && b == 1)
        cout << 9 << " " << 10 << endl;
    else
        cout << -1 << endl;
    return 0;
}