#include <bits/stdc++.h>
using namespace std;

bool isPrime(int x) {
    if (x < 2) return false;
    if (x > 2 && x % 2 == 0) return false;

    for (int d = 3; d*d <= x; d+=2) {
        if (x % d == 0) return false;
    }
    return true;
}



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);
    cout << fixed;

    int n;
    cin >> n;
    
    for (int i = 0; i < n; ++i) {
        long long x;
        cin >> x;
        
        long long sq = (int)(std::sqrt(x) + 0.1);
        if (sq*sq == x && isPrime(sq))
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}