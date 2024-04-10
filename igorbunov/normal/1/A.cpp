#include <bits/stdc++.h>

using namespace std;

#define int long long
signed main() {
    int n, m, a;
    cin >> n >> m >> a;
    cout << ((n - 1) / a + 1) * ((m - 1) / a + 1);
}