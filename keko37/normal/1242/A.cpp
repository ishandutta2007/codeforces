#include<bits/stdc++.h>

using namespace std;

typedef long long llint;

llint n;

int main () {
    cin >> n;
    for (llint i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            while (n % i == 0) n /= i;
            if (n == 1) cout << i; else cout << 1;
            return 0;
        }
    }
    cout << n;
    return 0;
}