#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);
    cout << fixed;

    int n;
    cin >> n;
    int c = 0;
    int m = 0;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        c = c - a + b;
        m = max(m, c);
    }

    cout << m << endl;
    return 0;
}