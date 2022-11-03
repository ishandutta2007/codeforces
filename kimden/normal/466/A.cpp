#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ll n, m, a, b;
    cin >> n >> m >> a >> b;
    n = min(min(a * n, (n % m) * a + (n / m) * b), ((n + m - 1) / m) * b);
    cout << n << endl;
}