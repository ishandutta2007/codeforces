#include <bits/stdc++.h>
using namespace std;

bool isPrime(int n) {
    for (int d = 2; d*d <= n; d++) {
        if (n % d == 0) return false;
    }
    return true;
}



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);
    cout << fixed;

    int n, m;
    cin >> n >> m;
    
    
    for (int i = n+1; ; i++) {
        if (isPrime(i)) {
            if (m == i)
                cout << "YES" << endl;
            else   
                cout << "NO" << endl;
            return 0;
        }
    }

    return 0;
}