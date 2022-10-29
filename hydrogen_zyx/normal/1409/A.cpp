#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t, n;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;
        a = abs(a - b);
        cout << (a + 9) / 10 << endl;
    }
}