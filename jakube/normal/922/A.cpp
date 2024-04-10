#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int x, y;
    cin >> x >> y;
    int c = x - (y - 1);
    if (c < 0 || c % 2 || y == 0 || (x != 0 && y == 1))
        cout << "No" << '\n';
    else
        cout << "Yes" << '\n';
}