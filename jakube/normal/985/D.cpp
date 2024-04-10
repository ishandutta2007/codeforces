#include <bits/stdc++.h>
using namespace std;

long long sum(long long n) {
    return (n+1) * n / 2;
}

long long f(long long n, long long H) {
    if (n <= H)
        return sum(n);
    else
        return sum(n) + sum(n-1) - sum(H-1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n, H;
    cin >> n >> H;
    
    // only upwards
    long long L = 0; // <=
    long long R = 2e9; // >
    while (L + 1 < R) {
        long long M = (L + R) / 2;
        long long x = f(M, H);
        if (x <= n)
            L = M;
        else
            R = M;
    }
    long long result = L + max(0LL, L - H);
    long long x = f(L, H);
    if (x < n)
        result += (n - x + L - 1) / L;
    cout << result << '\n';
}