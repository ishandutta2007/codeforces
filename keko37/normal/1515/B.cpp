#include<bits/stdc++.h>

using namespace std;

typedef long long llint;
typedef pair <int, int> pi;

int t;

bool is_square (int n) {
    int q = sqrt(n);
    return q * q == n;
}

bool ok (int n) {
    if (n % 2 != 0) return 0;
    return is_square(n / 2);
}

bool ok2 (int n) {
    if (n % 4 != 0) return 0;
    return is_square(n / 4);
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        if (ok(n) || ok2(n)) cout << "YES\n"; else cout << "NO\n";
    }
    return 0;
}