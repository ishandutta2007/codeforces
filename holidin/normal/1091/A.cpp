#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b, c, x;
    //freopen("input.txt", "r", stdin);
    //ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> a >> b >> c;
    x = min(min(a, b - 1), c - 2);
    cout << 3 * x + 3;
}