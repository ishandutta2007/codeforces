#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, l, r;
    cin >> n >> l >> r;
    long long x = pow(2,l)-1+n-l, y = pow(2,r)-1+pow(2,r-1)*(n-r);
    cout << x << ' ' << y;
    return 0;
}