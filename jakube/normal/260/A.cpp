#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);
    cout << fixed;

    int a, b, n;
    cin >> a >> b >> n;
    
    string s = to_string(a);

    for (int i = 0; i < n; i++) {
        a = (a * 10) % b;

        if (a == 0) {
            s += "0";
        } else if (b - a < 10) {
            s += '0' + (b - a);
            a = 0;
        } else {
            cout << -1 << endl;
            return 0;
        }
    }

    cout << s << endl;

    return 0;
}