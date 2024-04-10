#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);
    cout << fixed;

    string a, b;
    cin >> a >> b;
    int n;
    cin >> n;
    cout << a << ' ' << b << '\n';

    for (int i = 0; i < n; i++) {
        string vic, ne;
        cin >> vic >> ne;
        if (vic == a)
            a = ne;
        else
            b = ne;
        cout << a << ' ' << b << '\n';
    }

    return 0;
}