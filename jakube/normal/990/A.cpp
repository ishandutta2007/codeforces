#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n, m, a, b;
    cin >> n >> m >> a >> b;
    cout << min(n % m * b, (m - n % m) * a) << '\n';
    
}