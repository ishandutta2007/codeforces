#include <bits/stdc++.h>
#define va first
#define vb second
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int n, p, k;
bool sieve[1010101] = {true, true};
int main() {
    cin >> n;

    for (int i=2; i<1010101; i++) {
        if (!sieve[i]) {
            for (int j=2; i*j<1010101; j++) {
                sieve[i*j] = true;
            }
        }
    }

    for (int i=n; i<=3*n/2; i++) {
        if (!sieve[i]) {
            p = i;
            break;
        }
    }

    k = 3*n-2*p;

    cout << p << '\n';
    for (int i=1; i<=n; i++) {
        cout << i << ' ' << i%n+1 << '\n';
    }

    for (int i=1; i<=(n-k)/2; i++) {
        cout << i << ' ' << i+n/2 << '\n';
    }
}