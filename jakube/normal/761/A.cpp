#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);
    cout << fixed;

    int a, b;
    cin >> a >> b;
    cout << ((abs(a - b) <= 1 && a + b != 0) ? "YES" : "NO") << endl;

    return 0;
}