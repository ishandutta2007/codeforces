#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
const long long N = 3e5 + 1;

int main() {
    int x, y, z, a, b, c;
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> x >> y >> z;
    cin >> a >> b >> c;
    if (x <= a && x + y <= a + b && x + y + z <= a + b + c)
        cout << "YES\n";
    else
        cout << "NO\n";
}