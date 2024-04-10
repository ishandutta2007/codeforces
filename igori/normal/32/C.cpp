#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m, s;
    cin >> n >> m >> s;
    int r = n % s, c = m % s;
    if (r == 0) r = s;
    if (c == 0) c = s;
    cout << 1ll * r * c * ((n + s - 1) / s) * ((m + s - 1) / s);
}