#include <bits/stdc++.h>
using namespace std;

int inverse(int n) {
    int x = 0;
    while (n) {
        x = x * 10 + (n % 10);
        n /= 10;
    }
    return x;
}

long long f(int n) {
    long long  b = 1;
    while (b <= n) 
        b *= 10;
    return n * b + inverse(n);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long s = 0;
    int k, p;
    cin >> k >> p;
    for (int i = 1; i <= k; i++) {
        s += f(i) % p;
    }
    cout << (s % p) << endl;
    
}