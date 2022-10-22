#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int x = min(a, min(c, d));
    a -= x;
    c -= x;
    d -= x;
    int y = min(a, b);
    cout << 256 * x + 32 * y << '\n';
}