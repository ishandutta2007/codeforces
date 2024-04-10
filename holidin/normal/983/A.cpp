#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 1;

long long nod(long long a, long long b) {
    if (a < b)
        swap(a, b);
    if (b == 0)
        return a;
    else
        return nod(b, a % b);
}

int main() {
    long long i, p, q, b, n;
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for (i = 0; i < n; ++i) {
        cin >> p >> q >> b;
        long long x = nod(q, b);
        while (x > 1) {
            while (q % x == 0)
                q /= x;
            x = nod(q, b);
        }
        if (p % q == 0)
            cout << "Finite\n";
        else
            cout << "Infinite\n";
    }
}