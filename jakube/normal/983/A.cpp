#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        long long p, q, b;
        cin >> p >> q >> b;
        auto g = gcd(p, q);
        q /= g;
        g = gcd(q, b);
        while (g > 1) {
            while (q % g == 0)
                q /= g;
            g = gcd(q, g);
        }
        if (q == 1) 
            cout << "Finite" << '\n';
        else
            cout << "Infinite" << '\n';
    }
}