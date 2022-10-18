#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);
    cout << fixed;

    long long n, k;
    cin >> n >> k;

    while (1) {
        if (k == (1LL << (n-1))) 
        {
            cout << n << endl;
            return 0;
        }

        if (k > (1LL << (n-1)))
            k -= (1LL << (n-1));

        n -= 1;

    }

    return 0;
}