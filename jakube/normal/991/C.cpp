#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n;
    cin >> n;
    long long L = 0; // too less
    long long R = n; // >= 50%
    while (L + 1 < R) {
        long long M = (L + R) / 2;
        long long sum = 0;
        long long N = n;
        while (N) {
            long long x = min(M, N);
            N -= x;
            sum += x;
            N -= N / 10;
        }
        if (sum * 2 >= n)
            R = M;
        else
            L = M;
    }
    cout << R << '\n';
}