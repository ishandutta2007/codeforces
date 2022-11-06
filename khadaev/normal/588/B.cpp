#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n;
    cin >> n;
    long long ans = 1;
    for (int i = 2; i < 1000000; ++i)
        if (n % i == 0) {
            while (n % i == 0) n /= i;
            ans *= i;
        }
    cout << ans * n << endl;
}