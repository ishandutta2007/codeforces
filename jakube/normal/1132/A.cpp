#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int a, b, c, d;
    cin >> a >> b >> c >> d;
    cout << ((a == 0 && c == 0 && d == 0) || (a == d && a > 0) ? 1 : 0) << endl;
}