#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b, c, n, v1, v2, v3;
    //freopen("input.txt", "r", stdin);
    cin >> a >> b >> c >> n;
    v1 = 2*a;
    v2 = 2*b;
    v3 = max(c, n);
    if (n > v1 || 2*n >= v2 || 2*c < v3 || 2*n < v3) {
        cout << -1;
        return 0;
    }
    cout << v1 << endl;
    cout << v2 << endl;
    cout << v3 << endl;


}