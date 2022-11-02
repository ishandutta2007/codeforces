#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tc; cin >> tc;
    for (int ti = 0; ti < tc; ti++) {
        long long n, x, t; cin >> n >> x >> t;
        long long p = t / x;
        if (n <= p) cout << n * (n - 1LL) / 2LL << '\n';
        else cout << p * (p - 1LL) / 2LL + p * (n - p) << '\n';
    }
    return 0;
}