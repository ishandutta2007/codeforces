#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);
    cout << fixed;

    int a, b, c;
    cin >> a >> b >> c;
    int n = min(a, min(b / 2, c / 4));
    cout << 7*n << endl;

    return 0;
}