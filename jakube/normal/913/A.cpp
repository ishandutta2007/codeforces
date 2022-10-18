#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n, m;
    cin >> n >> m;
    n = min(n, 31LL);
    cout << (m & ((1LL << n) - 1)) << '\n';
}