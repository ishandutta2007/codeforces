#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);
    cout << fixed;

    // (1+n^2)*n/2

    int n;
    cin >> n;
    
    int a = 1;
    int b = n*n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n/2; j++) {
            cout << a << " " << b << " ";
            a++;
            b--;
        }
        cout << endl;
    }
    return 0;
}