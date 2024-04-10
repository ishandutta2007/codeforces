#include <bits/stdc++.h>

using namespace std;

int main() {
    long long int l, r, x, y, k;
    cin >> l >> r >> x >> y >> k;
    x*=k;
    y*=k;
    if(l>y || r<x || (r-l<k && r%k - l%k >= 0 && r%k && l%k)) cout << "NO";
    else cout << "YES";
}