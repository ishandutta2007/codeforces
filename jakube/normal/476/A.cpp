#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);
    cout << fixed;

    int n, m;
    cin >> n >> m;
    
    int a = n / 2;
    int b = n - a*2;

    while (a > 0 && (a + b) % m) {
        a--;
        b += 2;
    } 

    cout << ((a + b) % m == 0 ? a + b : -1) << endl;

    return 0;
}