#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n, k;
    cin >> n >> k;
    while (k) {
        if (n % 10)
            n--;
        else
            n/=10;
        k--;
    }
    cout << n << '\n';
}