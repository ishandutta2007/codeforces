#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);
    cout << fixed;

    int n, m, k;
    cin >> n >> m >> k;
    
    int a = (k - 1) / 2;
    
    cout << a / m + 1 << " " << (a % m) + 1 << " ";

    cout << (k & 1 ? "L" : "R") << endl;

    return 0;
}