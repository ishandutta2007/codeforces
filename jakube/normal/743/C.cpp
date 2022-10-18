#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);
    cout << fixed;

    int n;
    cin >> n;

    if (n == 1) {
        cout << -1 << endl;
        return 0;

    }
    
    cout << n << " " << n+1 << " " << n*(n+1) << endl;

    return 0;
}