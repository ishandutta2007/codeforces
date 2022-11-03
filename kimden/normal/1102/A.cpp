#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;


int main() {
    ios_base::sync_with_stdio(false);
    ll n;
    cin >> n;
    cout << ((n + 1) * n) % 4 / 2 << endl;
}