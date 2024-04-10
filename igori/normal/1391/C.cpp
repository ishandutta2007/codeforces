#include <iostream>

using namespace std;

int main()
{
    int n, mod = 1e9 + 7;
    cin >> n;
    long long f = 1;
    for (int i = 1; i <= n; i++)
        f = f * i % mod;
    long long g = 1;
    for (int i = 1; i <= n - 1; i++)
        g = g * 2 % mod;
    cout << (f + mod - g) % mod;
}