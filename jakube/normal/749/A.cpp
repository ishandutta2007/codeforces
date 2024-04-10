#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);
    cout << fixed;

    int n;
    cin >> n;
    
    if (n < 4) {
        cout << 1 << endl;
        cout << n << endl;
        return 0;
    }

    cout << n / 2 << endl;
    cout << (n % 2 ? 3 : 2) << ' ';
    for (int i = 1; i < n/2; i++) 
        cout << 2 << ' ';
    cout << endl;

    return 0;
}